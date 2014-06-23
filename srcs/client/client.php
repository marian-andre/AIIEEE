#!/usr/bin/env php
<?php

include(__DIR__."/connection.class.php");
include(__DIR__."/ia.class.php");

/*
 ** Function print_usage on error
 */

function	usage()
{
	echo "Usage: ./client -n <team> -p <port> [-h <hostname>]
		-n nom d'equipe
		-p port
		-h nom de la machine par defaut c'est le localhost";
	exit (1);
}

/*
 ** Function test args on program launch
 */

function	check_args($argc, $argv)
{
	if (!($argc === 5 || $argc === 7))
		usage();
	else if ($argv[1] !== "-n" || $argv[3] !== "-p" || (isset($argv[5]) && $argv[5] !== "-h"))
		usage();
}

/*
 ** Function who initialise client values
 */

function init_client($argc, $argv, &$ia, &$serveur)
{
	$serveur = new connection();
	$ia = new ia();

	connection::$verbose_debug = TRUE;
	connection::$verbose_send = TRUE;
	connection::$verbose_read = TRUE;
	$ia->serveur = $serveur;
	$serveur->set_host(isset($argv[6]) ? gethostbyname($argv[6]) : "127.0.0.1");
	$serveur->set_port($argv[4]);
	$serveur->connect();
	$serveur->receive_msg();
	$serveur->send_msg($argv[2]);
	$ia->connect_nbr = $serveur->receive_msg();
	$ia->mapsize = $serveur->receive_msg();
}

/*
 ** Function who run client ia
 */

function	run_client($ia, $serveur, $argv)
{
	$index = 0;
	while (true)
	{
		$serveur->send_msg("connect_nbr");
		$ia->connect_nbr = $serveur->receive_msg();
		$ia->client_get_nourriture();
		if ($ia->connect_nbr > 0)
			$ia->client_fork("./php-5.5.13/sapi/cli/php", $argv);
		if ($ia->stuff === NULL)
			$cmd_to_send = "inventaire";
		else if ($ia->client_canlevelup())
			$cmd_to_send = "incantation";
		else if ($index % 30 === 9)
			$cmd_to_send = "fork";
		else
			$cmd_to_send = $ia->search_what_missing();
		$ia->last_action = $cmd_to_send;
		$serveur->send_msg($cmd_to_send);
		$ia->last_action_receive = $serveur->receive_msg();
		if ($cmd_to_send === "incantation")
			$ia->level = substr($ia->last_action_receive, 16, 1);
		else if ($cmd_to_send === "inventaire")
			$ia->get_inventaire($ia->last_action_receive);
		$index++;
	}
}

/*
 ** Run Program ...
 */

function	main($argc, $argv)
{
	connection::$verbose_debug = FALSE;
	check_args($argc, $argv);
	init_client($argc, $argv, $ia, $serveur);
	if ($ia->connect_nbr !== "ko" && $ia->mapsize !== "ko")
		run_client($ia, $serveur, $argv);
}

if (!function_exists('pcntl_exec'))
{
	echo "Error, PHP version !" . PHP_EOL;
	exit (1);
}
main($argc, $argv);

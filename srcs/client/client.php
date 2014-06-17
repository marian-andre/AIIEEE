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
	connection::$verbose_send = TRUE;
	$index = 0;
	while (true)
	{
		$serveur->send_msg("connect_nbr");
		$ia->connect_nbr = $serveur->receive_msg();
		if ($ia->connect_nbr > 0)
			$ia->client_fork("./bin/client", $argv);
		if ($ia->stuff === NULL)
			$cmd_to_send = "inventaire";
		else if ($ia->client_canlevelup())
			$cmd_to_send = "incantation";
		else if ($index % 10 === 9)
			$cmd_to_send = "fork";
		else
			$cmd_to_send = $ia->search_what_missing();
		$ia->last_action = $cmd_to_send;
		$serveur->send_msg($cmd_to_send);
		$receive = $serveur->receive_msg();
		if ($cmd_to_send === "incantation")
		{
			if (strncmp($receive, "niveau actuel : ", 16) === 0)
				$ia->level++;
		}
		else if ($cmd_to_send === "inventaire")
			$ia->get_inventaire($receive);
		else if (strncmp($cmd_to_send, "prend ", 6) === 0 && $receive === "ok")
			$ia->stuff = NULL;
		$index++;
	}
}

/*
 ** Run Program ...
 */

function	main($argc, $argv)
{
	check_args($argc, $argv);
	init_client($argc, $argv, $ia, $serveur);
	if ($ia->connect_nbr !== "ko" && $ia->mapsize !== "ko")
		run_client($ia, $serveur, $argv);
}

if(!function_exists('pcntl_exec'))
{
	echo "Error, PHP version\n";
	exit (1);
}
main($argc, $argv);

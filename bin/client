#!/usr/bin/php
<?php
include(__DIR__.'/usage.php');
include(__DIR__.'/connection.php');
include(__DIR__.'/ia.php');

if (!($argc == 5 || $argc == 7))
    usage();
if ($argv[1] != "-n" || $argv[3] != "-p" || (isset($argv[5]) && $argv[5] != "-h"))
    usage();
$team = $argv[2];
$port = $argv[4];
$host = (isset($argv[6]) ? $argv[6] : "127.0.0.1");
$socket = connection($host, $port, $team);
ia($socket, $team);
socket_close($socket);
?>

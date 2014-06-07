<?php
function connection($host, $port, $team)
{
	set_time_limit(0);
	$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	if ($socket === false)
		exit("socket_create() failed, reason :  ".
			socket_strerror(socket_last_error()).PHP_EOL);
	$result = socket_connect($socket, $host, $port);
	if ($socket === false)
		exit("socket_connect() failed, reason : ($result) ".
			socket_strerror(socket_last_error($socket)).PHP_EOL);
	$line = socket_read($socket, 1024, PHP_NORMAL_READ);
	if ($line != "BIENVENUE\n")
		exit("ERROR BIENVENUE".PHP_EOL);
	socket_write($socket, $team."\n");
	$line = socket_read($socket, 1024, PHP_NORMAL_READ);
	$line = socket_read($socket, 1024, PHP_NORMAL_READ);
	return ($socket);
}
?>

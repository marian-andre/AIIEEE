<?php
function ia($socket, $team)
{
	$lvl = 1;
	socket_write($socket, "voir\n");
	$line = socket_read($socket, 1024, PHP_NORMAL_READ);
	echo $line;
}
?>

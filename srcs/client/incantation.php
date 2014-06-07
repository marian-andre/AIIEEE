<?php
function incantation($socket)
{
	socket_write($socket, "incantation\n");
	$line = socket_read($socket, 1024, PHP_NORMAL_READ);
	$line = socket_read($socket, 1024, PHP_NORMAL_READ);
}
?>

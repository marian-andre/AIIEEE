<?php
function get_set_obj($req, $socket)
{
	socket_write($socket, $req." linemate"."\n");
	socket_read($socket, 1024, PHP_NORMAL_READ);
}
?>

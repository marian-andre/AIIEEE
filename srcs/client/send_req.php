<?php
function send_req($req, $socket)
{
	socket_write($socket, $req."\n");
	socket_read($socket, 1024, PHP_NORMAL_READ);
}
?>

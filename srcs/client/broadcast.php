<?php
function broadcast($req, $socket)
{
	socket_write($socket, $req." YOLOOO"."\n");
	socket_read($socket, 1024, PHP_NORMAL_READ);
}
?>

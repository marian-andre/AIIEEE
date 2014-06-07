<?php
function mort($socket)
{
	$read = array($socket);
	$write = NULL;
	$exept = NULL;
	if (socket_select($read, $write, $exept, 0) == 1)
	{
		$line = socket_read($socket, 1024, PHP_NORMAL_READ);
		if ($line == "mort\n")
		{
			socket_close($socket);
			exit(0);
		}
	}
}
?>

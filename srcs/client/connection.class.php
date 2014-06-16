<?php

set_time_limit(0);

class		connection
{
	private	$_sock;
	private	$_port;
	private	$_host;

	public	function	set_host($host)
	{
		$this->_host = $host;
	}

	public	function	set_port($port)
	{
		$this->_port = $port;
	}

	public function	connect()
	{
		if (($this->_sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === FALSE)
		{
			echo socket_strerror(socket_last_error())."\n";
			exit (1);
		}
		else if (@socket_set_option($this->_sock, SOL_SOCKET, SO_REUSEADDR, 1) === FALSE)
		{
			echo "socket_set_option : " . socket_strerror(socket_last_error())."\n";
			exit (1);
		}
		else if (@socket_connect($this->_sock, $this->_host, $this->_port) === FALSE)
		{
			echo socket_strerror(socket_last_error())."\n";
			exit (1);
		}
		echo "Connecting client on server ".$this->_host.":".$this->_port." succeed.\n";
	}

	public	function	send_msg($msg)
	{
		if (@socket_write($this->_sock, trim($msg)."\n", strlen($msg) + 1) === FALSE)
		{
			echo "Impossible d'envoyer le message sur la socket " . $this->_sock."\n";
			exit (1);
		}
	}

	public	function	read_msg()
	{
		if (($msg = @socket_read($this->_sock, 1024, PHP_NORMAL_READ)) === FALSE)
		{
			echo "Impossible de lire le message sur la socket " . $this->_sock."\n";
			exit (1);
		}
		return (trim($msg));
	}

	public	function	receive_msg()
	{
		$rep = $this->read_msg();
		if ($rep === "elevation en cours")
			$rep = $this->read_msg();
		echo $rep . "\n";
		if ($rep === "mort")
			$this->disconnect();
		return ($rep);
	}

	public	function	disconnect()
	{
		socket_close($this->_sock);
		echo "Closing connection client on server : ".$this->_host.":".$this->_port." succeed.\n";
		exit (0);
	}
}

?>

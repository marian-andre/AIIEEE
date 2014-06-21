<?php

set_time_limit(0);

class		connection
{
	private			$_sock;
	private			$_port;
	private			$_host;
	static public	$verbose_debug = TRUE;
	static public	$verbose_send = FALSE;
	static public	$verbose_read = FALSE;

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
			if (self::$verbose_debug === TRUE)
				echo socket_strerror(socket_last_error()) . PHP_EOL;
			exit (1);
		}
		else if (@socket_set_option($this->_sock, SOL_SOCKET, SO_REUSEADDR, 1) === FALSE)
		{
			if (self::$verbose_debug === TRUE)
				echo "socket_set_option : " . socket_strerror(socket_last_error()) . PHP_EOL;
			exit (1);
		}
		else if (@socket_connect($this->_sock, $this->_host, $this->_port) === FALSE)
		{
			if (self::$verbose_debug === TRUE)
				echo socket_strerror(socket_last_error()) . PHP_EOL;
			exit (1);
		}
		if (self::$verbose_debug === TRUE)
			echo "Connecting client on server ".$this->_host.":".$this->_port." succeed." . PHP_EOL;
	}

	public	function	send_msg($msg)
	{
		if (self::$verbose_send === TRUE) echo "--> $msg:";
		if (@socket_write($this->_sock, trim($msg)."\n", strlen($msg) + 1) === FALSE)
		{
			if (self::$verbose_debug === TRUE)
				echo "Impossible d'envoyer le message sur la socket " . $this->_sock. PHP_EOL;
			exit (1);
		}
	}

	public	function	read_msg()
	{
		if (($msg = @socket_read($this->_sock, 1024, PHP_NORMAL_READ)) === FALSE)
		{
			if (self::$verbose_debug === TRUE)
				echo "Impossible de lire le message sur la socket " . $this->_sock . PHP_EOL;
			exit (1);
		}
		return (trim($msg));
	}

	public	function	receive_msg()
	{
		$rep = $this->read_msg();
		if ($rep === "elevation en cours")
			$rep = $this->read_msg();
		if (self::$verbose_read === TRUE) echo $rep . PHP_EOL;
		if ($rep === "mort")
			$this->disconnect();
		return ($rep);
	}

	public	function	disconnect()
	{
		socket_close($this->_sock);
		if (self::$verbose_debug === TRUE)
			echo "Closing connection client on server : ".$this->_host.":".$this->_port." succeed." . PHP_EOL;
		exit (0);
	}
}

?>

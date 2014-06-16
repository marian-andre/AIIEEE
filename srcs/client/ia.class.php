<?php

require_once(__DIR__."/connection.class.php");

class			ia
{
	public		$connect_nbr;
	public		$mapsize;
	public		$level;
	public		$stuff;
	public		$serveur;
	public		$last_action;

	function		__construct()
	{
		$this->stuff = NULL;
		$this->level = 1;
		$this->last_action = NULL;
	}

	function		get_inventaire($receive)
	{
		$receive = str_replace('{', '', $receive);
		$receive = str_replace('}', '', $receive);
		$inventaire = array();
		$inventaire = explode(',', $receive);
		$i = 0;
		$stuff = array();
		while (isset($inventaire[$i]))
		{
			$inventaire[$i] = explode(' ', $inventaire[$i]);
			@$this->stuff[$inventaire[$i][0]] = $inventaire[$i][1];
			$i++;
		}
	}

	function		get_nb_player_on_my_case()
	{
		$this->serveur->send_msg("voir");
		$receive = $this->serveur->receive_msg();
		$receive = str_replace('{', '', $receive);
		$receive = str_replace('}', '', $receive);
		$map = array();
		$map = explode(',', $receive);
		$map = explode(' ', $map[0]);
		$i = 0;
		$nb = 0;
		while (isset($map[$i]))
		{
			if ($map[$i] == "nourriture")
			{
				$this->serveur->send_msg("prend nourriture");
				$receive = $this->serveur->receive_msg();
			}
			if ($map[$i] == "joueur")
				$nb++;
			$i++;
		}
		return ($nb);
	}

	function		client_fork($file, $argv)
	{
		array_shift($argv);
		$pid = pcntl_fork();
		if ($pid == -1)
		{
			echo "Duplication impossible\n";
			exit (1);
		}
		else if ($pid)
			pcntl_wait($status);
		else if (pcntl_exec($file, $argv) !== FALSE)
			$this->connect_nbr--;
	}

	function		client_canlevelup()
	{
		if ($this->level == 1)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 1)
					return (true);
		}
		else if ($this->level == 2)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 1
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 2)
					return (true);
		}
		else if ($this->level == 3)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 2
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 1
				&& isset($this->stuff["phiras"]) && $this->stuff["phiras"] >= 2)
				if ($this->get_nb_player_on_my_case() >= 2)
					return (true);
		}
		else if ($this->level == 4)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 1
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 2
				&& isset($this->stuff["phiras"]) && $this->stuff["phiras"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 4)
					return (true);
		}
		else if ($this->level == 5)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 2
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 1
				&& isset($this->stuff["mendiane"]) && $this->stuff["mendiane"] >= 3)
				if ($this->get_nb_player_on_my_case() >= 4)
					return (true);
		}
		else if ($this->level == 6)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 2
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 3
				&& isset($this->stuff["phiras"]) && $this->stuff["phiras"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 6)
					return (true);
		}
		else if ($this->level == 7)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 2
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 2
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 2
				&& isset($this->stuff["mendiane"]) && $this->stuff["mendiane"] >= 2
				&& isset($this->stuff["phiras"]) && $this->stuff["phiras"] >= 2
				&& isset($this->stuff["thystame"]) && $this->stuff["thystame"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 6)
					return (true);
		}
		return (false);
	}

	function		vision($receive, $search)
	{
		$receive = str_replace('{', '', $receive);
		$receive = str_replace('}', '', $receive);
		$map = array();
		$map = explode(',', $receive);
		$i = 0;
		while (isset($map[$i]))
		{
			$map[$i] = explode(' ', $map[$i]);
			$i++;
		}
		if ($this->last_action == "gauche" || $this->last_action == "droite")
			return ("avance");
		$i = 0;
		while (isset($search[$i]))
		{
			$a = 0;
			while (isset($map[$a]))
			{
				$b = 0;
				while (isset($map[$a][$b]))
				{
					if ($map[$a][$b] == $search[$i])
					{
						if ($a == 0)
							return ("prend " . $search[$i]);
						else if ($a == 2
							|| $a == 6
							|| $a == 12
							|| $a == 20
							|| $a == 30
							|| $a == 42
							|| $a == 56
							|| $a == 72)
							return ("avance");
						else if ($a == 3
							|| ($a  > 6 && $a < 9)
							|| ($a  > 12 && $a < 16)
							|| ($a  > 20 && $a < 25)
							|| ($a  > 30 && $a < 36)
							|| ($a  > 42 && $a < 49)
							|| ($a  > 56 && $a < 64)
							|| ($a  > 72 && $a < 81))
							return ("droite");
						return ("gauche");
					}
					$b++;
				}
				$a++;
			}
			$i++;
		}
		return ("avance");
	}

	function		search_what_missing()
	{
		$tab_search = array();
		if ($this->level == 1)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] < 1)
				$tab_search[] = "linemate";
			if ($this->get_nb_player_on_my_case() < 1)
				$tab_search[] = "player";
		}
		else if ($this->level == 2)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] < 1)
				$tab_search[] = "linemate";
			if (isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] < 1)
				$tab_search[] = "deraumere";
			if (isset($this->stuff["sibur"]) && $this->stuff["sibur"] < 1)
				$tab_search[] = "sibur";
			if ($this->get_nb_player_on_my_case() < 2)
				$tab_search[] = "player";
		}
		else if ($this->level == 3)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] < 2)
				$tab_search[] = "linemate";
			if (isset($this->stuff["sibur"]) && $this->stuff["sibur"] < 1)
				$tab_search[] = "sibur";
			if (isset($this->stuff["phiras"]) && $this->stuff["phiras"] < 2)
				$tab_search[] = "phiras";
			if ($this->get_nb_player_on_my_case() < 2)
				$tab_search[] = "player";
		}
		else if ($this->level == 4)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] < 1)
				$tab_search[] = "linemate";
			if (isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] < 1)
				$tab_search[] = "deraumere";
			if (isset($this->stuff["sibur"]) && $this->stuff["sibur"] < 2)
				$tab_search[] = "sibur";
			if (isset($this->stuff["phiras"]) && $this->stuff["phiras"] < 1)
				$tab_search[] = "phiras";
			if ($this->get_nb_player_on_my_case() < 4)
				$tab_search[] = "player";
		}
		else if ($this->level == 5)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] < 1)
				$tab_search[] = "linemate";
			if (isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] < 2)
				$tab_search[] = "deraumere";
			if (isset($this->stuff["sibur"]) && $this->stuff["sibur"] < 1)
				$tab_search[] = "sibur";
			if (isset($this->stuff["mendiane"]) && $this->stuff["mendiane"] < 3)
				$tab_search[] = "mendiane";
			if ($this->get_nb_player_on_my_case() < 4)
				$tab_search[] = "player";
		}
		else if ($this->level == 6)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] < 1)
				$tab_search[] = "linemate";
			if (isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] < 2)
				$tab_search[] = "deraumere";
			if (isset($this->stuff["sibur"]) && $this->stuff["sibur"] < 3)
				$tab_search[] = "sibur";
			if (isset($this->stuff["phiras"]) && $this->stuff["phiras"] < 1)
				$tab_search[] = "phiras";
			if ($this->get_nb_player_on_my_case() < 6)
				$tab_search[] = "player";
		}
		else if ($this->level == 7)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] < 2)
				$tab_search[] = "linemate";
			if (isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] < 2)
				$tab_search[] = "deraumere";
			if (isset($this->stuff["sibur"]) && $this->stuff["sibur"] < 2)
				$tab_search[] = "sibur";
			if (isset($this->stuff["mendiane"]) && $this->stuff["mendiane"] < 2)
				$tab_search[] = "mendiane";
			if (isset($this->stuff["phiras"]) && $this->stuff["phiras"] < 2)
				$tab_search[] = "phiras";
			if (isset($this->stuff["thystame"]) && $this->stuff["thystame"] < 1)
				$tab_search[] = "thystame";
			if ($this->get_nb_player_on_my_case() < 6)
				$tab_search[] = "player";
		}
		else
			$tab_search[] = "nourriture";
		$this->serveur->send_msg("voir");
		$receive = $this->serveur->receive_msg();
		return ($this->vision($receive, $tab_search));
	}
}

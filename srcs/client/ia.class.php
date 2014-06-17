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

	public function		__construct()
	{
		$this->stuff = NULL;
		$this->level = 1;
		$this->last_action = NULL;
	}

	public function		get_inventaire($receive)
	{
		$receive = str_replace('{', '', $receive);
		$receive = str_replace('}', '', $receive);
		$inventaire = array();
		$inventaire = explode(',', $receive);
		$index = 0;
		$stuff = array();
		while (isset($inventaire[$index]))
		{
			$inventaire[$index] = explode(' ', $inventaire[$index]);
			@$this->stuff[$inventaire[$index][0]] = $inventaire[$index][1];
			$index++;
		}
	}

	public function		client_fork($file, $argv)
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

	private function	get_nb_player_on_my_case()
	{
		$this->serveur->send_msg("voir");
		$receive = $this->serveur->receive_msg();
		$receive = str_replace('{', '', $receive);
		$receive = str_replace('}', '', $receive);
		$map = array();
		$map = explode(',', $receive);
		$map = explode(' ', $map[0]);
		$index = 0;
		$count = 0;
		while (isset($map[$index]))
		{
			if ($map[$index] == "nourriture")
			{
				$this->serveur->send_msg("prend nourriture");
				$receive = $this->serveur->receive_msg();
			}
			if ($map[$index] == "joueur")
				$count++;
			$index++;
		}
		return ($count);
	}

	public function		client_canlevelup()
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

	private function		search_array($search)
	{
		$this->serveur->send_msg("voir");
		$receive = $this->serveur->receive_msg();
		$receive = str_replace('{', '', $receive);
		$receive = str_replace('}', '', $receive);
		$map = array();
		$map = explode(',', $receive);
		$index = 0;
		while (isset($map[$index]))
		{
			$map[$index] = explode(' ', $map[$index]);
			$index++;
		}
		if ($this->last_action == "gauche" || $this->last_action == "droite")
			return ("avance");
		$index = 0;
		while (isset($search[$index]))
		{
			$a = 0;
			while (isset($map[$a]))
			{
				$b = 0;
				while (isset($map[$a][$b]))
				{
					if ($map[$a][$b] == $search[$index])
					{
						if ($a == 0)
						{
							if ($search[$index] !== "nourriture")
								$this->stuff = NULL;
							return ("prend " . $search[$index]);
						}
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
			$index++;
		}
		return ("avance");
	}

	public function		search_what_missing()
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
		return ($this->search_array($tab_search));
	}
}

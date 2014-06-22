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
	public		$last_action_receive;

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
			$inventaire[$index] = explode(' ', trim($inventaire[$index]));
			$this->stuff[$inventaire[$index][0]] = $inventaire[$index][1];
			$index++;
		}
	}

	public function		client_fork($file, $argv)
    {
		array_shift($argv);
        $arg = $argv;
        array_unshift($arg, "srcs/client/client.php");
		$pid = @pcntl_fork();
		if ($pid == -1)
			echo "ERROR : Duplication impossible\n";
		else if (!$pid)
			pcntl_exec($file, $arg);
	}

	private function	get_nb_player_on_my_case()
	{
		if ($this->last_action != "voir")
		{
			$this->last_action = "voir";
			$this->serveur->send_msg($this->last_action);
			$this->last_action_receive = $this->serveur->receive_msg();
		}
		$receive = str_replace('{', '', $this->last_action_receive);
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
				$this->serveur->receive_msg();
			}
			if ($map[$index] == "joueur")
				$count++;
			$index++;
		}
		return ($count);
	}

	private function	client_pose_item()
	{
		$to_pose = array_keys($this->stuff);
		foreach ($this->stuff as $elem)
		{
			$index_elem = 0;
			if ($to_pose[$index] != "nourriture")
				while (++$index_elem <= $elem)
				{
					$this->last_action = "pose " . $to_pose[$index];
					$this->serveur->send_msg($this->last_action);
					$this->serveur->receive_msg();
				}
			$index++;
		}
		$this->stuff = NULL;
		return (true);
	}

	public function		client_canlevelup()
	{
		if ($this->level == 1)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 1)
					return ($this->client_pose_item());
		}
		else if ($this->level == 2)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 1
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 2)
					return ($this->client_pose_item());
		}
		else if ($this->level == 3)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 2
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 1
				&& isset($this->stuff["phiras"]) && $this->stuff["phiras"] >= 2)
				if ($this->get_nb_player_on_my_case() >= 2)
					return ($this->client_pose_item());
		}
		else if ($this->level == 4)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 1
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 2
				&& isset($this->stuff["phiras"]) && $this->stuff["phiras"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 4)
					return ($this->client_pose_item());
		}
		else if ($this->level == 5)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 2
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 1
				&& isset($this->stuff["mendiane"]) && $this->stuff["mendiane"] >= 3)
				if ($this->get_nb_player_on_my_case() >= 4)
					return ($this->client_pose_item());
		}
		else if ($this->level == 6)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] >= 1
				&& isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] >= 2
				&& isset($this->stuff["sibur"]) && $this->stuff["sibur"] >= 3
				&& isset($this->stuff["phiras"]) && $this->stuff["phiras"] >= 1)
				if ($this->get_nb_player_on_my_case() >= 6)
					return ($this->client_pose_item());
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
					return ($this->client_pose_item());
		}
		return (false);
	}

	private function		search_array($search)
	{
		if ($this->last_action != "voir")
		{
			$this->last_action = "voir";
			$this->serveur->send_msg($this->last_action);
			$this->last_action_receive = $this->serveur->receive_msg();
		}
		$receive = str_replace('{', '', $this->last_action_receive);
		$receive = str_replace('}', '', $receive);
		$map = array();
		$map = explode(',', $receive);
		$index = 0;
		while (isset($map[$index]))
		{
			$map[$index] = explode(' ', trim($map[$index]));
			$index++;
		}
		if ($this->last_action == "gauche" || $this->last_action == "droite")
			return ("avance");
		$index = 0;
		while (isset($search[$index]))
		{
			$index_case = 0;
			while (isset($map[$index_case]))
			{
				$index_object = 0;
				while (isset($map[$index_case][$index_object]))
				{
					if ($map[$index_case][$index_object] == $search[$index])
					{
						if ($index_case == 0)
						{
							if ($search[$index] !== "nourriture")
								$this->stuff = NULL;
							return ("prend " . $search[$index]);
						}
						else if ($index_case == 2
							|| $index_case == 6
							|| $index_case == 12
							|| $index_case == 20
							|| $index_case == 30
							|| $index_case == 42
							|| $index_case == 56
							|| $index_case == 72)
							return ("avance");
						else if ($index_case == 3
							|| ($index_case  > 6 && $index_case < 9)
							|| ($index_case  > 12 && $index_case < 16)
							|| ($index_case  > 20 && $index_case < 25)
							|| ($index_case  > 30 && $index_case < 36)
							|| ($index_case  > 42 && $index_case < 49)
							|| ($index_case  > 56 && $index_case < 64)
							|| ($index_case  > 72 && $index_case < 81))
							return ("droite");
						return ("gauche");
					}
					$index_object++;
				}
				$index_case++;
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
		}
		else if ($this->level == 2)
		{
			if (isset($this->stuff["linemate"]) && $this->stuff["linemate"] < 1)
				$tab_search[] = "linemate";
			if (isset($this->stuff["deraumere"]) && $this->stuff["deraumere"] < 1)
				$tab_search[] = "deraumere";
			if (isset($this->stuff["sibur"]) && $this->stuff["sibur"] < 1)
				$tab_search[] = "sibur";
			if ($this->get_nb_player_on_my_case() < 2 && empty($tab_search))
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
			if ($this->get_nb_player_on_my_case() < 2 && empty($tab_search))
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
			if ($this->get_nb_player_on_my_case() < 4 && empty($tab_search))
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
			if ($this->get_nb_player_on_my_case() < 4 && empty($tab_search))
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
			if ($this->get_nb_player_on_my_case() < 6 && empty($tab_search))
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
			if ($this->get_nb_player_on_my_case() < 6 && empty($tab_search))
				$tab_search[] = "player";
		}
		else
			$tab_search[] = "nourriture";
		return ($this->search_array($tab_search));
	}
}

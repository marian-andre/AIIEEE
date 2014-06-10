<?php
function ia($socket, $team)
{
	$requetes = array(
		"avance",
		"droite",
		"gauche",
		"voir",
		"inventaire",
		"prend",
		"pose",
		"expulse",
		"broadcast",
		"incantation",
		"fork",
		"connect_nbr",
		);
	$lvl = 1;
	while (1)
	{
		mort($socket);
		$req = rand(0, 11);
		if ($requetes[$req] == "prend" || ($requetes[$req] == "pose"))
			get_set_obj($requetes[$req], $socket);
		else if ($requetes[$req] == "broadcast")
			broadcast($socket);
		else if ($requetes[$req] == "incantation")
		{
			incantation($socket);
			$lvl++;
		}
		else
			send_req($requetes[$req], $socket);
	}
}
?>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_lvl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 17:43:52 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/11 17:43:57 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		ft_disp_lvl_7(int *q, t_game *game, int lvl)
{
	q[0] = 2;
	q[1] = 2;
	q[2] = 2;
	q[3] = 2;
	q[4] = 2;
	q[5] = 2;
	q[6] = 1;
	game->cls[num_cli].resource.linemate -= 2;
	game->cls[num_cli].resource.deraumere -= 2;
	game->cls[num_cli].resource.sibur -= 2;
	game->cls[num_cli].resource.mendiane -= 2;
	game->cls[num_cli].resource.phiras -= 2;
	game->cls[num_cli].resource.thystame -= 1;
}

void		ft_disp_lvl_6_(int *q, t_game *game, int lvl)
{
	q[0] = 1;
	q[1] = 2;
	q[2] = 3;
	q[4] = 1;
	game->cls[num_cli].resource.linemate -= 1;
	game->cls[num_cli].resource.deraumere -= 2;
	game->cls[num_cli].resource.sibur -= 3;
	game->cls[num_cli].resource.phiras -= 1;
}

void		ft_disp_lvl_4_to_5(int *q, t_game *game, int lvl)
{
	if (lvl == 4)
	{
		q[0] = 1;
		q[1] = 1;
		q[2] = 2;
		q[4] = 1;
		game->cls[num_cli].resource.linemate -= 1;
		game->cls[num_cli].resource.deraumere -= 1;
		game->cls[num_cli].resource.sibur -= 2;
		game->cls[num_cli].resource.phiras -= 1;
	}
	if (lvl == 5)
	{
		q[0] = 1;
		q[1] = 2;
		q[2] = 1;
		q[3] = 3;
		game->cls[num_cli].resource.linemate -= 1;
		game->cls[num_cli].resource.deraumere -= 2;
		game->cls[num_cli].resource.sibur -= 1;
		game->cls[num_cli].resource.mendiane -= 3;
	}
}

void		ft_disp_lvl_1_to_3(int *q, t_game *game, int lvl)
{
	if (lvl == 1)
	{
		q[0] = 1;
		game->cls[num_cli].resource.linemate -= 1;
	}
	if (lvl == 2)
	{
		q[0] = 1;
		q[1] = 1;
		q[2] = 1;
		game->cls[num_cli].resource.linemate -= 1;
		game->cls[num_cli].resource.deraumere -= 1;
		game->cls[num_cli].resource.sibur -= 1;
	}
	if (lvl == 3)
	{
		q[0] = 2;
		q[2] = 1;
		q[4] = 2;
		game->cls[num_cli].resource.linemate -= 2;
		game->cls[num_cli].resource.sibur -= 1;
		game->cls[num_cli].resource.phiras -= 2;
	}
}

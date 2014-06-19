/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_lvl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 17:43:52 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/19 18:06:22 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		ft_disp_lvl_7(int *q, t_game *game, int num_cli)
{
	q[0] = 2;
	q[1] = 2;
	q[2] = 2;
	q[3] = 2;
	q[4] = 2;
	q[5] = 2;
	q[6] = 1;
	game->map[game->cls[num_cli].y][game->cls[num_cli].x].linemate -= 2;
	game->map[game->cls[num_cli].y][game->cls[num_cli].x].deraumere -= 2;
	game->map[game->cls[num_cli].y][game->cls[num_cli].x].sibur -= 2;
	game->map[game->cls[num_cli].y][game->cls[num_cli].x].mendiane -= 2;
	game->map[game->cls[num_cli].y][game->cls[num_cli].x].phiras -= 2;
	game->map[game->cls[num_cli].y][game->cls[num_cli].x].thystame -= 1;
	ft_graph_bct(game, 0, game->cls[num_cli].x, game->cls[num_cli].y);
}

void		ft_disp_lvl_5_to_6(int *q, t_game *game, int num_cli, int lvl)
{
	if (lvl == 6)
	{
		q[0] = 1;
		q[1] = 2;
		q[2] = 3;
		q[4] = 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].linemate -= 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].deraumere -= 2;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].sibur -= 3;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].phiras -= 1;
		ft_graph_bct(game, 0, game->cls[num_cli].x, game->cls[num_cli].y);
	}
	if (lvl == 5)
	{
		q[0] = 1;
		q[1] = 2;
		q[2] = 1;
		q[3] = 3;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].linemate -= 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].deraumere -= 2;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].sibur -= 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].mendiane -= 3;
		ft_graph_bct(game, 0, game->cls[num_cli].x, game->cls[num_cli].y);
	}
}

void		ft_disp_lvl_3_to_4(int *q, t_game *game, int lvl, int num_cli)
{
	if (lvl == 3)
	{
		q[0] = 2;
		q[2] = 1;
		q[4] = 2;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].linemate -= 2;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].sibur -= 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].phiras -= 2;
		ft_graph_bct(game, 0, game->cls[num_cli].x, game->cls[num_cli].y);
	}
	if (lvl == 4)
	{
		q[0] = 1;
		q[1] = 1;
		q[2] = 2;
		q[4] = 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].linemate -= 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].deraumere -= 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].sibur -= 2;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].phiras -= 1;
		ft_graph_bct(game, 0, game->cls[num_cli].x, game->cls[num_cli].y);
	}
}

void		ft_disp_lvl_1_to_2(int *q, t_game *game, int lvl, int num_cli)
{
	if (lvl == 1)
	{
		q[0] = 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].linemate -= 1;
		ft_graph_bct(game, 0, game->cls[num_cli].x, game->cls[num_cli].y);
	}
	if (lvl == 2)
	{
		q[0] = 1;
		q[1] = 1;
		q[2] = 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].linemate -= 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].deraumere -= 1;
		game->map[game->cls[num_cli].y][game->cls[num_cli].x].sibur -= 1;
		ft_graph_bct(game, 0, game->cls[num_cli].x, game->cls[num_cli].y);
	}
}

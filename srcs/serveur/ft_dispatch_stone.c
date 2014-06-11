/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_stone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:37:50 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/11 18:18:39 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static void		ft_dispatch(t_game *game, int *q)
{
	int		x;
	int		y;
	t_map	**map;

	y = -1;
	map = game->map;
	while (++y < game.height)
	{
		x = -1;
		while (++x < game.width)
		{
			if (q[0] > 0)
				map[y][x].linemate = ft_rand_stone(q, 0, game);
			if (q[1] > 0)
				map[y][x].deraumere = ft_rand_stone(q, 1, game);
			if (q[2] > 0)
				map[y][x].sibur = ft_rand_stone(q, 2, game);
			if (q[3] > 0)
				map[y][x].phiras = ft_rand_stone(q, 3, game);
			if (q[4] > 0)
				map[y][x].mendiane = ft_rand_stone(q, 4, game);
			if (q[5] > 0)
				map[y][x].thystame = ft_rand_stone(q, 5, game);
		}
	}
}

void			ft_dispatch_stone(t_game *g, int cli)
{
	static int		q[6] = {0};

	if (g.cls[cli].lvl == 1 || g.cls[cli].lvl == 2 || g.cls[cli].lvl == 3)
		ft_disp_lvl_1_to_3(q, &g, g.cls[cli].lvl, cli);
	if (g.cls[cli].lvl == 4 || g.cls[cli].lvl == 5)
		ft_disp_lvl_4_to_5(q, &g, g.cls[cli].lvl, cli);
	if (g.cls[cli].lvl == 6)
		ft_disp_lvl_6(q, &g, g.cls[cli].lvl, cli);
	if (g.cls[cli].lvl == 7)
		ft_disp_lvl_7(q, &g, g.cls[cli].lvl, cli);
	ft_dispatch(g, q);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 10:02:56 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/19 18:05:43 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "serveur.h"
#include "libft.h"

int				ft_rand_stone(int *q, int i, t_game *game)
{
	static float	chance = 10;
	float			rolling;

	rolling = (int)(rand() % 100 + 1);
	if (rolling <= chance)
	{
		chance += 10 / (game->height * game->width);
		q[i] -= 1;
		if (q[i] > 2)
			return (ft_rand(2) + 1);
		else
			return (1);
	}
	return (0);
}

int				ft_rand(int a)
{
	return ((int)(rand() % a));
}

static void		ft_distrib(int x, int y, t_game *game)
{
	int		q[6];

	q[0] = ((game->height * game->width) * Q_LI) / 100;
	q[1] = ((game->height * game->width) * Q_DE) / 100;
	q[2] = ((game->height * game->width) * Q_SI) / 100;
	q[3] = ((game->height * game->width) * Q_PH) / 100;
	q[4] = ((game->height * game->width) * Q_ME) / 100;
	q[5] = ((game->height * game->width) * Q_TH) / 100;
	if (q[0] > 0)
		game->map[y][x].linemate = ft_rand_stone(q, 0, game);
	if (q[1] > 0)
		game->map[y][x].deraumere = ft_rand_stone(q, 1, game);
	if (q[2] > 0)
		game->map[y][x].sibur = ft_rand_stone(q, 2, game);
	if (q[3] > 0)
		game->map[y][x].phiras = ft_rand_stone(q, 3, game);
	if (q[4] > 0)
		game->map[y][x].mendiane = ft_rand_stone(q, 4, game);
	if (q[5] > 0)
		game->map[y][x].thystame = ft_rand_stone(q, 5, game);
	game->map[y][x].nourriture = ft_rand(Q_FO);
}

void			ft_resource(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
			ft_distrib(x, y, game);
	}
}

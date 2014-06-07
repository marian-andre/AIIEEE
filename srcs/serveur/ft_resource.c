/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resource.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 10:02:56 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/06 10:17:39 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "serveur.h"
#include "libft.h"

void			test(t_map **map, t_game game)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++y < game.height)
	{
		x = -1;
		while (++x < game.width)
		{
			ft_putstr("li = ");
			ft_putnbr(map[y][x].linemate);
			ft_putchar('\n');
			ft_putstr("de = ");
			ft_putnbr(map[y][x].deraumere);
			ft_putchar('\n');
			ft_putstr("si = ");
			ft_putnbr(map[y][x].sibur);
			ft_putchar('\n');
			ft_putstr("me = ");
			ft_putnbr(map[y][x].mendiane);
			ft_putchar('\n');
			ft_putstr("ph = ");
			ft_putnbr(map[y][x].phiras);
			ft_putchar('\n');
			ft_putstr("th = ");
			ft_putnbr(map[y][x].thystame);
			ft_putchar('\n');
			ft_putstr("food = ");
			ft_putnbr(map[y][x].food);
			ft_putchar('\n');
		}
	}
}

static int		ft_rand(int *q, int i, t_game game)
{
	static float	chance = 5;
	float			rolling;

	rolling = (int)(rand() % 100 + 1);
	if (rolling <= chance)
	{
		chance += 20 / (game.height * game.width);
		q[i] -= 1;
		return (1);
	}
	return (0);
}

int				ft_rand_food(int a)
{
	return ((int)(rand() % a + 1));
}

static void		ft_distrib(t_map **map, int x, int y, t_game game)
{
	int		q[6];

	q[0] = ((game.height * game.width) * 20) / 100;
	q[1] = ((game.height * game.width) * 20) / 100;
	q[2] = ((game.height * game.width) * 20) / 100;
	q[3] = ((game.height * game.width) * 10) / 100;
	q[4] = ((game.height * game.width) * 10) / 100;
	q[5] = ((game.height * game.width) * 5) / 100;
	if (q[0] > 0)
		map[y][x].linemate = ft_rand(q, 0, game);
	if (q[1] > 0)
		map[y][x].deraumere = ft_rand(q, 1, game);
	if (q[2] > 0)
		map[y][x].sibur = ft_rand(q, 2, game);
	if (q[3] > 0)
		map[y][x].phiras = ft_rand(q, 3, game);
	if (q[4] > 0)
		map[y][x].mendiane = ft_rand(q, 4, game);
	if (q[5] > 0)
		map[y][x].thystame = ft_rand(q, 5, game);
	map[y][x].food = ft_rand_food(200);
}

t_game			ft_resource(t_game game)
{
	int		x;
	int		y;
	t_map	**map;

	y = -1;
	ft_putendl("bug");
	test(game.map, game);
	map = game.map;
	while (++y < game.height)
	{
		x = -1;
		while (++x < game.width)
			ft_distrib(map, x, y, game);
	}
	ft_putendl("bug2");
	test(game.map, game);
	return (game);
}

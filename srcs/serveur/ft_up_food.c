/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_food.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 18:25:02 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/13 15:51:50 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "serveur.h"

static void	ft_loop_map(t_game *game, int x, int y)
{
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x].food == 0)
				game->map[y][x].food = ft_rand(Q_FO);
		}
	}
}

void		ft_up_food(t_game *game)
{
	int		y;
	int		x;
	int		food;

	y = -1;
	food = 0;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
			food = food + game->map[y][x].food;
	}
	if (food < (game->height * game->width) * (Q_FO / 2))
	{
		ft_loop_map(game, x, y);
		ft_graph_mct(game, 0);
	}
}

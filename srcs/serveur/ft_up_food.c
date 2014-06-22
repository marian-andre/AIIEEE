/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_food.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 18:25:02 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/22 14:12:09 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "serveur.h"

static void	ft_loop_map(t_game *game, int x, int y)
{
	int		r;

	y = -1;
	r = 0;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x].nourriture == 0)
			{
				r = ft_rand(100);
				if (r < 25)
				{
					game->map[y][x].nourriture = ft_rand(Q_FO);
					ft_graph_bct(game, 0, x, y);
				}
			}
		}
	}
}

void		ft_up_food(t_game *game)
{
	int			y;
	int			x;
	int			food;
	static int	food_base = 0;

	y = -1;
	food = 0;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
			food = food + game->map[y][x].nourriture;
	}
	if (food_base == 0)
	{
		game->nourr_base = food;
		food_base = 1;
	}
	if (food < (game->nourr_base * 80 / 100))
		ft_loop_map(game, x, y);
}

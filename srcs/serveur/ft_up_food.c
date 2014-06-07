/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_food.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 18:25:02 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/06 17:24:18 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "serveur.h"

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
	if (food < (game->height * game->width) * 100)
	{
		y = -1;
		while (++y < game->height)
		{
			x = -1;
			while (++x < game->width)
			{
				if (game->map[y][x].food == 0)
					game->map[y][x].food = ft_rand_food(200);
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_resources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 10:01:05 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/24 13:19:01 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "libft.h"

static void	ft_fill_empty(int x, int y, t_game *g)
{
	SDL_Rect	src;
	SDL_Rect	dst;

    src.x = 0;
    src.y = 0;
    src.h = MAP_SIZE_H;
    src.w = MAP_SIZE_W;
    dst.x = g->width * MAP_SIZE_W;
    dst.y = 360;
    dst.h = y * MAP_SIZE_H;
    dst.w = x * MAP_SIZE_W;
	SDL_RenderCopy(g->renderer, g->textures[23], &src, &dst);
}

void		ft_show_case(t_game *g)
{
	int			x;
	int			y;
	SDL_Rect	src;
	SDL_Rect	dst;

	y = 0;
    src.x = 0;
    src.y = 0;
    src.h = 360;
    src.w = 240;
    dst.x = g->width * MAP_SIZE_W;
    dst.y = 0;
    dst.h = 360;
    dst.w = 240;
	SDL_RenderCopy(g->renderer, g->textures[22], &src, &dst);
	while (++y <= ((g->height * MAP_SIZE_H) - 360) / MAP_SIZE_H + 1)
	{
		x = 0;
		while (++x <= 240 / MAP_SIZE_W + 1)
			ft_fill_empty(x, y, g);
	}
}

void		ft_show_resources(t_game *g, SDL_Event event)
{
	SDL_Rect pos;

//	while (1)
//	{
	if (g == g)
	{
	pos.x = event.button.x;
	pos.y = event.button.y;
	}
	ft_putnbr(pos.x);
	ft_putstr(" / ");
	ft_putnbr(pos.y);
	ft_putchar('\n');
//		}
}

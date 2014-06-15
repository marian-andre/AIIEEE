/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 16:48:28 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/15 18:01:12 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void		draw_render(t_game *game)
{
	SDL_Rect	src;
	SDL_Rect	dst;
	int			i;
	int			j;

	src.x = 0;
	src.y = 0;
	src.w = TILES_SIZE_W;
	src.h = TILES_SIZE_H;
	dst.w = TILES_SIZE_W;
	dst.h = TILES_SIZE_H;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			dst.x = j * TILES_SIZE_W;
			dst.y = i * TILES_SIZE_H;
			SDL_RenderCopy(game->renderer, game->textures[11], &src, &dst);
		}
	}
	SDL_RenderPresent(game->renderer);
}

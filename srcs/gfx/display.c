/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 16:48:28 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/15 22:16:09 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void		draw_case(t_game *game, int x, int y)
{
	SDL_Rect	dst;
	SDL_Rect	src;

	src.x = 0;
	src.y = 0;
	src.h = MAP_SIZE_H;
	src.w = MAP_SIZE_W;
	dst.x = x * MAP_SIZE_W;
	dst.y = y * MAP_SIZE_H;
	dst.h = MAP_SIZE_H;
	dst.w = MAP_SIZE_W;
	SDL_RenderCopy(game->renderer, game->textures[11], &src, &dst);
	src.h = TILES_SIZE_H;
	src.w = TILES_SIZE_W;
	dst.h = TILES_SIZE_H;
	dst.w = TILES_SIZE_W;
	//linemate
	dst.x = x * MAP_SIZE_W;
	dst.y = y * MAP_SIZE_H;
	if (game->map[y][x].linemate > 0)
		SDL_RenderCopy(game->renderer, game->textures[1], &src, &dst);
	//deraumere
	dst.x = x * MAP_SIZE_W + TILES_SIZE_W;
	dst.y = y * MAP_SIZE_H;
	if (game->map[y][x].deraumere > 0)
		SDL_RenderCopy(game->renderer, game->textures[2], &src, &dst);
	//sibur
	dst.x = (x * MAP_SIZE_W) + (2 * TILES_SIZE_W);
	dst.y = y * MAP_SIZE_H;
	if (game->map[y][x].sibur > 0)
		SDL_RenderCopy(game->renderer, game->textures[3], &src, &dst);
	//mendiane
	dst.x = x * MAP_SIZE_W;
	dst.y = (y * MAP_SIZE_H) + (3 * TILES_SIZE_H);
	if (game->map[y][x].mendiane > 0)
		SDL_RenderCopy(game->renderer, game->textures[4], &src, &dst);
	//phiras
	dst.x = (x * MAP_SIZE_W) + TILES_SIZE_W;
	dst.y = (y * MAP_SIZE_H) + (3 * TILES_SIZE_H);
	if (game->map[y][x].phiras > 0)
		SDL_RenderCopy(game->renderer, game->textures[5], &src, &dst);
	//thystame
	dst.x = (x * MAP_SIZE_W) + (2 * TILES_SIZE_W);
	dst.y = (y * MAP_SIZE_H) + (3 * TILES_SIZE_H);
	if (game->map[y][x].thystame > 0)
		SDL_RenderCopy(game->renderer, game->textures[6], &src, &dst);
	//food
	dst.x = (x * MAP_SIZE_W) + (3 * TILES_SIZE_W);
	dst.y = (y * MAP_SIZE_H) + (1.5 * TILES_SIZE_H);
	if (game->map[y][x].food > 0)
		SDL_RenderCopy(game->renderer, game->textures[0], &src, &dst);
}

void			draw_render(t_game *game)
{
	int			i;
	int			j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			draw_case(game, j, i);
	}
	SDL_RenderPresent(game->renderer);
}

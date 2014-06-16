/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 16:48:28 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/16 16:00:25 by mlemort          ###   ########.fr       */
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

static void		ft_dir_goron(t_game *game, SDL_Rect *s, SDL_Rect *d, int i)
{
	if (game->client[i].dir == NORTH)
		SDL_RenderCopy(game->renderer, game->textures[7], s, d);
	if (game->client[i].dir == SOUTH)
		SDL_RenderCopy(game->renderer, game->textures[8], s, d);
	if (game->client[i].dir == EAST)
		SDL_RenderCopy(game->renderer, game->textures[9], s, d);
	if (game->client[i].dir == WEAST)
		SDL_RenderCopy(game->renderer, game->textures[10], s, d);
}

static void		ft_draw_goron(t_game *game, int i)
{
	int			x;
	int			y;
	SDL_Rect	dst;
	SDL_Rect	src;

	x = game->client[i].x;
	y = game->client[i].y;
	src.x = 0;
	src.y = 0;
	src.h = TILES_SIZE_H;
	src.w = TILES_SIZE_W;
	dst.x = x * MAP_SIZE_W;
	dst.y = y * MAP_SIZE_H + TILES_SIZE_H;
	dst.w = TILES_SIZE_W;
	dst.h = TILES_SIZE_H;
	if (game->map[y][x].current_player < 3)
		dst.x = dst.x + (game->map[y][x].current_player * TILES_SIZE_W);
	else if (game->map[y][x].current_player < 6)
	{
		dst.x = dst.x + ((game->map[y][x].current_player - 3) * TILES_SIZE_W);
		dst.y = dst.y + TILES_SIZE_H;
	}
	if (game->map[y][x].current_player < 6)
		ft_dir_goron(game, &src, &dst, i);
	game->map[y][x].current_player++;
}

static void		ft_gorimbakus(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			game->map[i][j].current_player = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < MAX_CLI)
	{
		if (game->client[i].num_team != -1)
		{
			ft_draw_goron(game, i);
		}
		i++;
	}
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
	ft_gorimbakus(game);
	SDL_RenderPresent(game->renderer);
}

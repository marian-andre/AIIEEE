/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 16:48:28 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/16 17:06:09 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void		ft_dir_goron(t_game *game, SDL_Rect *s, SDL_Rect *d, int i)
{
	if (game->client[i].dir == NORTH)
		SDL_RenderCopy(game->renderer, game->textures[7], s, d);
	if (game->client[i].dir == SOUTH)
		SDL_RenderCopy(game->renderer, game->textures[8], s, d);
	if (game->client[i].dir == EAST)
		SDL_RenderCopy(game->renderer, game->textures[9], s, d);
	if (game->client[i].dir == WEST)
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

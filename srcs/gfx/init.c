/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:13:05 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/22 19:34:56 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphic.h"
#include "libft.h"

void		init_map(t_game *game)
{
	int		i;
	char	**array;
	char	*line;

	line = NULL;
	get_next_line(game->sock, &line);
	ft_putendl(line);
	free(line);
	ft_putendl_fd("GRAPHIC", game->sock);
	get_next_line(game->sock, &line);
	i = -1;
	if ((array = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> array in init_map");
	free(line);
	game->width = ft_atoi(array[1]);
	game->height = ft_atoi(array[2]);
	game->map = (t_map**)malloc(sizeof(t_map*) * ft_atoi(array[2]));
	while (++i < ft_atoi(array[2]))
		game->map[i] = (t_map*)malloc(sizeof(t_map) * ft_atoi(array[1]));
	ft_strdel2(&array);
}

void		init_time(t_game *game)
{
	char	**array;
	char	*line;

	line = NULL;
	get_next_line(game->sock, &line);
	if ((array = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> array in init_time");
	game->time = ft_atoi(array[1]);
	free(line);
	ft_strdel2(&array);
}
/*
void		init_textures(t_game *g)
{
	g->textures = (SDL_Texture**)malloc(sizeof(SDL_Texture*)
		* (NB_TEXTURES + 1));
	g->textures[0] = load_image(g, "srcs/gfx/image/food.bmp", 0xFFFFFF);
	g->textures[1] = load_image(g, "srcs/gfx/image/linemate.bmp", 0xFFFFFF);
	g->textures[2] = load_image(g, "srcs/gfx/image/deraumere.bmp", 0xFFFFFF);
	g->textures[3] = load_image(g, "srcs/gfx/image/sibur.bmp", 0xFFFFFF);
	g->textures[4] = load_image(g, "srcs/gfx/image/mendiane.bmp", 0xFFFFFF);
	g->textures[5] = load_image(g, "srcs/gfx/image/phiras.bmp", 0xFFFFFF);
	g->textures[6] = load_image(g, "srcs/gfx/image/thystame.bmp", 0xFFFFFF);
	g->textures[7] = load_image(g, "srcs/gfx/image/goron_N.bmp", 0xFFFFFF);
	g->textures[8] = load_image(g, "srcs/gfx/image/goron_S.bmp", 0xFFFFFF);
	g->textures[9] = load_image(g, "srcs/gfx/image/goron_E.bmp", 0xFFFFFF);
	g->textures[10] = load_image(g, "srcs/gfx/image/goron_W.bmp", 0xFFFFFF);
	g->textures[11] = load_image(g, "srcs/gfx/image/map.bmp", -1);
	g->textures[12] = load_image(g, "srcs/gfx/image/oeuf.bmp", -1);
	g->textures[13] = load_image(g, "srcs/gfx/image/lvlup.bmp", 0xFFFFFF);
	g->textures[14] = NULL;
}
*/
void		init_textures(t_game *g)
{
	g->textures = (SDL_Texture**)malloc(sizeof(SDL_Texture*)
		* (NB_TEXTURES + 1));
	g->textures[0] = load_image(g, "srcs/gfx/image/food-R2D2.bmp", 0xFFFFFF);
	g->textures[1] = load_image(g, "srcs/gfx/image/linemate_RD.bmp", 0xFFFFFF);
	g->textures[2] = load_image(g, "srcs/gfx/image/emeraude.bmp", 0xFFFFFF);
	g->textures[3] = load_image(g, "srcs/gfx/image/rubis.bmp", 0xFFFFFF);
	g->textures[4] = load_image(g, "srcs/gfx/image/diamant.bmp", 0xFFFFFF);
	g->textures[5] = load_image(g, "srcs/gfx/image/saphir.bmp", 0xFFFFFF);
	g->textures[6] = load_image(g, "srcs/gfx/image/amethyste.bmp", 0xFFFFFF);
	g->textures[7] = load_image(g, "srcs/gfx/image/RD_NORD.bmp", 0xFFFFFF);
	g->textures[8] = load_image(g, "srcs/gfx/image/RD_SUD.bmp", 0xFFFFFF);
	g->textures[9] = load_image(g, "srcs/gfx/image/RD_EST.bmp", 0xFFFFFF);
	g->textures[10] = load_image(g, "srcs/gfx/image/RD_OUEST.bmp", 0xFFFFFF);
	g->textures[11] = load_image(g, "srcs/gfx/image/till.bmp", -1);
	g->textures[12] = load_image(g, "srcs/gfx/image/oeuf_RD.bmp", -1);
	g->textures[13] = load_image(g, "srcs/gfx/image/lvl_up.bmp", 0xFFFFFF);
	g->textures[14] = NULL;
}

void		init_sdl(t_game *game)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_graphic_error("SDL initialization has failed.");
	game->window = SDL_CreateWindow("Zappy", SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									game->width * MAP_SIZE_W,
									game->height * MAP_SIZE_H,
									SDL_WINDOW_SHOWN);
	game->renderer = SDL_CreateRenderer(game->window, -1,
										SDL_RENDERER_ACCELERATED);
	if (game->window == NULL || game->renderer == NULL)
		ft_graphic_error("screen mode initialization is impossible.");
	init_textures(game);
}

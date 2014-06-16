/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:13:05 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/16 15:56:13 by mlemort          ###   ########.fr       */
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

void				init_textures(t_game *g)
{
	g->textures = (SDL_Texture**)malloc(sizeof(SDL_Texture*)
		* (NB_TEXTURES + 1));
	g->textures[0] = loadImage(g, "srcs/gfx/image/food.bmp", 0);
	g->textures[1] = loadImage(g, "srcs/gfx/image/linemate.bmp", 0xFFFFFF);
	g->textures[2] = loadImage(g, "srcs/gfx/image/deraumere.bmp", -1);
	g->textures[3] = loadImage(g, "srcs/gfx/image/sibur.bmp", -1);
	g->textures[4] = loadImage(g, "srcs/gfx/image/mendiane.bmp", -1);
	g->textures[5] = loadImage(g, "srcs/gfx/image/phiras.bmp", 0xFEFEFE);
	g->textures[6] = loadImage(g, "srcs/gfx/image/thystame.bmp", -1);
	g->textures[7] = loadImage(g, "srcs/gfx/image/goron_N.bmp", -1);
	g->textures[8] = loadImage(g, "srcs/gfx/image/goron_S.bmp", -1);
	g->textures[9] = loadImage(g, "srcs/gfx/image/goron_E.bmp", -1);
	g->textures[10] = loadImage(g, "srcs/gfx/image/goron_W.bmp", -1);
	g->textures[11] = loadImage(g, "srcs/gfx/image/map.bmp", -1);
	g->textures[12] = loadImage(g, "srcs/gfx/image/egg.bmp", -1);
	g->textures[13] = NULL;
}

void				init_sdl(t_game *game)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_graphic_error("SDL initialization has failed.");
	game->window = SDL_CreateWindow("Zappy", SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									game->width * MAP_SIZE_W,
									game->height * MAP_SIZE_H,
									SDL_WINDOW_SHOWN);
	game->renderer = SDL_CreateRenderer(game->window, -1,
										SDL_RENDERER_PRESENTVSYNC);
	if (game->window == NULL || game->renderer == NULL)
		ft_graphic_error("screen mode initialization is impossible.");
	init_textures(game);
}

void		init_case(t_game *game, char *line)
{
	char	**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> array in init_case");
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].food = ft_atoi(tab[3]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].linemate = ft_atoi(tab[4]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].deraumere = ft_atoi(tab[5]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].sibur = ft_atoi(tab[6]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].mendiane = ft_atoi(tab[7]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].phiras = ft_atoi(tab[8]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].thystame = ft_atoi(tab[9]);
	ft_strdel2(&tab);
	free(line);
}

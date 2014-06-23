/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 13:57:23 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/23 16:52:23 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "SDL.h"

# define MAP_SIZE_W 64
# define MAP_SIZE_H 64
# define TILES_SIZE_H 16
# define TILES_SIZE_W 16
# define LVL_SIZE_W 8
# define LVL_SIZE_H 8
# define NB_TXT 22
# define MAX_CLI 1000
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

typedef struct		s_map
{
	int				food;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
	int				nb_player;
	int				current_player;
}					t_map;

typedef struct		s_client
{
	int				x;
	int				y;
	int				num_team;
	int				lvl;
	int				dir;
	int				invok;
	t_map			resource;
}					t_client;

typedef struct		s_egg
{
	int				active;
	int				x;
	int				y;
	int				client;
}					t_egg;

typedef struct		s_game
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		**textures;
	t_map			**map;
	int				width;
	int				height;
	int				time;
	char			**team;
	t_client		client[MAX_CLI];
	t_egg			egg[MAX_CLI];
	int				sock;
}					t_game;

/*
** ft_graphic_error.c
*/

void				ft_graphic_error(char *msg);
void				ft_graphic_usage(void);

/*
** display.c
*/

void				draw_render(t_game *game);

/*
** tool.c
*/

t_game				*singleton(t_game *game);
void				cleanup(void);
SDL_Texture			*load_image(t_game *game, char *path, int rgb);
void				display(t_game *game);

/*
** draw_case.c
*/

void				draw_case(t_game *game, int x, int y);

/*
** init.c
*/

void				init_map(t_game *game);
void				init_time(t_game *game);
void				init_sdl(t_game *game);
void				init_textures(t_game *game);

/*
** ft_check_msg.c
*/

void				ft_check_msg(t_game *game, char *line);

/*
** ft_graph_bct.c
*/

void				ft_graph_bct(t_game *game, char *line);

/*
** ft_graph_tna.c
*/

void				ft_graph_tna(t_game *game, char *line);

/*
** ft_graph_pnw.c
*/

void				init_client(t_game *game);
void				ft_graph_pnw(t_game *game, char *line);

/*
** ft_graph_ppo.c
*/

void				ft_graph_ppo(t_game *game, char *line);

/*
** ft_graph_plv.c
*/

void				ft_graph_plv(t_game *game, char *line);

/*
** ft_graph_pin.c
*/

void				ft_graph_pin(t_game *game, char *line);

/*
** ft_graph_pex.c
*/

void				ft_graph_pex(t_game *game, char *line);

/*
** ft_graph_pic.c
*/

void				ft_graph_pic(t_game *game, char *line);

/*
** ft_graph_pbc.c
*/

void				ft_graph_pbc(t_game *game, char *line);

/*
** ft_graph_pie.c
*/

void				ft_graph_pie(t_game *game, char *line);

/*
** ft_graph_pfk.c
*/

void				ft_graph_pfk(t_game *game, char *line);
/*
** ft_graph_pdr.c
*/

void				ft_graph_pdr(t_game *game, char *line);

/*
** ft_graph_pgt.c
*/

void				ft_graph_pgt(t_game *game, char *line);

/*
** ft_graph_pdi.c
*/

void				ft_graph_pdi(t_game *game, char *line);

/*
** ft_graph_enw.c
*/

void				init_egg(t_game *game);
void				ft_graph_enw(t_game *game, char *line);

/*
** ft_graph_eht.c
*/

void				ft_graph_eht(t_game *game, char *line);

/*
** ft_graph_ebo.c
*/

void				ft_graph_ebo(t_game *game, char *line);

/*
** ft_graph_edi.c
*/

void				ft_graph_edi(t_game *game, char *line);

/*
** ft_graph_sgt.c
*/

void				ft_graph_sgt(t_game *game, char *line);

/*
** ft_graph_seg.c
*/

void				ft_graph_seg(t_game *game, char *line);

/*
** ft_graph_pdi.c
*/

void				ft_graph_smg(t_game *game, char *line);

/*
** ft_graph_suc.c
*/

void				ft_graph_suc(t_game *game, char *line);

/*
** ft_graph_sbp.c
*/

void				ft_graph_sbp(t_game *game, char *line);

#endif

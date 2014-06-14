/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 13:57:23 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/14 16:58:00 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include "SDL.h"

# define SCREEN_WIDTH 10
# define SCREEN_HEIGHT 10
# define MAX_CLI 42

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

typedef struct		s_action
{
	int				left;
	int				right;
	int				up;
	int				down;
	int				enter;
	int				erase;
	int				pause;
}					t_action;

typedef struct		s_game
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	t_map			**map;
	int				width;
	int				height;
	int				time;
	char			**team;
	t_client		client[MAX_CLI];
	t_action		*action;
}					t_game;


/*
** ft_graphic_error.c
*/

void				ft_graphic_error(char *msg);

/*
** main.c
*/

void				init(t_game *game, char *title);
void				cleanup(t_game *game);
void				draw(t_game *game);
void				delay(unsigned int frameLimit);

/*
** init.c
*/

void				init_map(t_game *game, char *line);
void				init_time(t_game *game, char *line);
void				init_case(t_game *game, char *line);
void				display(t_game *game);

/*
** ft_check_msg.c
*/

void				ft_check_msg(t_game *game, char *line);

/*
** ft_graph_tna.c
*/

int					nb_line(char **tab);
char				**ft_realloc(t_game *game, char **tab, char *team);
int					ft_check_in_team(char **team, char *name);
void				ft_graph_tna(t_game *game, char *line);

/*
** ft_graph_pnw.c
*/

void				ft_add_player(t_game *game, char **tab);
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

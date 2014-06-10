/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:04:10 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/10 13:16:14 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <sys/select.h>
# include <sys/time.h>

# define MAX_CLI 42
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

typedef struct timeval	t_time;
typedef struct s_cmd	t_cmd;

struct			s_cmd
{
	char		*cmd;
	t_time		time;
	int			fd;
	int			num_cli;
	t_cmd		*next;
};

typedef struct	s_map
{
	int			linemate;
	int			deraumere;
	int			sibur;
	int			mendiane;
	int			phiras;
	int			thystame;
	int			food;
	int			nb_player;
}				t_map;

typedef struct	s_client
{
	int			cs;
	int			graph;
	int			num_team;
	int			lvl;
	int			x;
	int			y;
	int			dir;
	t_map		resource;
}				t_client;

typedef struct	s_egg
{
	int			active;
	int			nb;
	int			x;
	int			y;
	t_client	cl;
}				t_egg;

typedef struct	s_fd
{
	int			max;
	int			nb_cli;
	fd_set		rdfs;
}				t_fd;

typedef struct	s_tab
{
	char		*line;
	int			t;
}				t_tab;

typedef struct	s_game
{
	t_tab		tab[11];
	t_cmd		*list;
	int			sock;
	int			port;
	int			width;
	int			height;
	int			max_cli;
	int			time;
	char		**team;
	t_egg		eggs[MAX_CLI];
	t_client	cls[MAX_CLI];
	t_map		**map;
}				t_game;

void			test(t_map **map, t_game game);

void			ft_add_node(t_game *g, t_cmd *cmd);
void			ft_del_node(t_game *g, t_cmd *cmd);
t_cmd			*ft_create_node(t_game *g, char *line, int i);
void			ft_init_tab(t_tab tab[11]);
long			timevaldiff(t_time starttime, t_time finishtime);
int				ft_rand_food(int a);
t_game			ft_resource(t_game game);
t_game			ft_check_args(char **argv, t_game game);
void			ft_up_food(t_game *game);
void			ft_serveur(t_game *game);
void			ft_new_client(t_game *g, t_fd *fd, char *line);
void			ft_usage(char *str);
void			ft_error(char *msg);
void			ft_exec_request(t_game *g);
void			ft_save_request(t_game *g, t_fd *fd);
void			ft_move(t_cmd *cmd, t_game *g);
void			ft_right(t_cmd *cmd, t_game *g);
void			ft_left(t_cmd *cmd, t_game *g);
void			ft_see(t_cmd *cmd);
void			ft_stock(t_cmd *cmd, t_game *g);
void			ft_take(t_cmd *cmd, t_game *g);
void			ft_put(t_cmd *cmd);
void			ft_expel(t_cmd *cmd);
void			ft_broadcast(t_cmd *cmd);
void			ft_spell(t_cmd *cmd);
void			ft_fork(t_cmd *cmd);
void			ft_nb_connect(t_game *g, int i);

void			ft_graph_msz(t_game *g, int i);
void			ft_graph_sgt(t_game *g, int i);
void			ft_graph_mct(t_game *g, int i);
void			ft_graph_tna(t_game *g, int i);
void			ft_graph_pnw(t_game *g, int num_cli);
void			ft_graph_plv(t_game *g, int i, int num_cli);
void			ft_graph_ppo(t_game *g, int num_cli);
void			ft_graph_pin(t_game *g, int i, int num_cli);
void			ft_graph_pex(t_game *g, int i, int num_cli);
void			ft_graph_pbc(t_game *g, int i, int num_cli, char *msg);
void			ft_graph_pic(t_game *g, int i, int num_cli);
void			ft_graph_pie(t_game *g, int i, int num_cli, int res);
void			ft_graph_pfk(t_game *g, int i, int num_cli);
void			ft_graph_pdr(t_game *g, int i, int num_cli, int resource);
void			ft_graph_pgt(t_game *g, int i, int num_cli, int resource);
void			ft_graph_pdi(t_game *g, int i, int num_cli);
void			ft_graph_seg(t_game *g, int i, char *team);
void			ft_graph_smg(t_game *g, int i, char *msg);
void			ft_graph_suc(t_game *g, int i);
void			ft_graph_sbp(t_game *g, int i);
void			ft_graph_bct(t_game *g, int i, int x, int y);
void			ft_graph_enw(t_game *g, int i, int num_cli);
void			ft_graph_eht(t_game *g, int i, int nb_egg);
void			ft_graph_ebo(t_game *g, int i, int nb_egg);
void			ft_graph_edi(t_game *g, int i, int nb_egg);

#endif

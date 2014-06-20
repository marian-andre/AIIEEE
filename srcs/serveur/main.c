/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:17:27 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/20 13:54:54 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>
#include "serveur.h"
#include "libft.h"

static void				ft_init_game(t_game *game)
{
	int		i;

	i = 0;
	while (i < MAX_CLI)
	{
		ft_bzero(&game->eggs[i], sizeof(t_egg));
		ft_bzero(&game->cls[i], sizeof(t_client));
		i++;
	}
	ft_init_tab(game->tab);
	game->tab[12].line = ft_strdup("birth");
	game->tab[12].t = 600;
	game->sock = 0;
	game->port = 4242;
	game->width = 20;
	game->height = 20;
	game->nourr_base = 0;
	i = 0;
	while (i < MAX_NB_TEAM)
	{
		game->max_cli[i] = 6;
		i++;
	}
	game->time = 100;
}

static void				ft_init_map(t_game *game)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	game->map = (t_map**)malloc(sizeof(t_map*) * game->height);
	while (++y < game->height)
		game->map[y] = (t_map*)malloc(sizeof(t_map) * game->width);
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			game->map[y][x].linemate = 0;
			game->map[y][x].deraumere = 0;
			game->map[y][x].sibur = 0;
			game->map[y][x].mendiane = 0;
			game->map[y][x].phiras = 0;
			game->map[y][x].thystame = 0;
			game->map[y][x].nourriture = 0;
			game->map[y][x].nb_player = 0;
		}
	}
}

static int				create_server(t_game game)
{
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == 0)
		ft_error("ERROR getprotobyname.");
	if ((game.sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		ft_error("ERROR socket.");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(game.port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(game.sock, (const struct sockaddr*)&sin, sizeof(sin)) == -1)
		ft_error("ERROR bind.");
	if (listen(game.sock, MAX_CLI) == -1)
		ft_error("ERROR listen.");
	return (game.sock);
}

static void				ft_init_cls(t_game *g)
{
	int					i;

	i = 0;
	while (i < MAX_CLI)
	{
		g->cls[i].cs = 0;
		i++;
	}
}

int						main(int argc, char **argv)
{
	t_game				game;

	singleton(&game);
	signal(SIGINT, exit);
	srand(time(NULL));
	if (argc == 1)
		ft_usage(argv[0]);
	ft_init_game(&game);
	ft_check_args(argv, &game);
	ft_init_map(&game);
	atexit(ft_quit);
	ft_resource(&game);
	game.sock = create_server(game);
	ft_init_cls(&game);
	ft_serveur(&game);
	return (0);
}

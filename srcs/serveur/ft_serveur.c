/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:07:12 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/22 16:36:59 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "serveur.h"
#include "libft.h"

static void		ft_new_connection(t_game *g, t_fd *fd)
{
	int					i;
	int					cs;
	char				*line;
	unsigned int		cslen;
	struct sockaddr_in	*csin;

	i = 0;
	line = NULL;
	cs = accept(g->sock, (struct sockaddr*)&csin, &cslen);
	if (cs < 0)
		ft_error("ERROR socket.");
	ft_putendl_fd("BIENVENUE", cs);
	get_next_line(cs, &line);
	while (i < MAX_CLI && g->cls[i].cs != MORT && g->cls[i].cs != 0)
		i++;
	fd->nb_cli = i;
	ft_new_client(g, fd, line, cs);
	free(line);
}

static void		ft_save_fd_cli(t_client *cls, t_fd *fd)
{
	int			i;

	i = -1;
	while (++i < MAX_CLI && cls[i].cs)
	{
		if (cls[i].cs != MORT)
			FD_SET(cls[i].cs, &fd->rdfs);
	}
}

static int		ft_win(t_game *g)
{
	int			i;
	int			j;
	int			nb;

	i = -1;
	nb = 0;
	while (g->team[++i])
	{
		j = -1;
		nb = 0;
		while (++j < MAX_CLI && g->cls[j].cs)
		{
			if (g->cls[j].num_team == i && g->cls[j].lvl == 8)
				nb++;
		}
		if (nb >= 6)
		{
			ft_putstr("Fin de partie, l'equipe qui gagne est : ");
			ft_putendl(g->team[i]);
			ft_graph_seg(g, g->team[i]);
			return (1);
		}
	}
	return (0);
}

void			ft_serveur(t_game *game)
{
	t_fd		fd;
	t_time		timeout;

	timeout.tv_sec = 0;
	timeout.tv_usec = 1;
	fd.max = game->sock;
	fd.nb_cli = 0;
	game->list = NULL;
	while (!ft_win(game))
	{
		ft_up_food(game);
		ft_exec_request(game);
		FD_ZERO(&fd.rdfs);
		FD_SET(game->sock, &fd.rdfs);
		ft_save_fd_cli(game->cls, &fd);
		if (select(fd.max + 1, &fd.rdfs, NULL, NULL, &timeout) == -1)
			ft_error("ERROR select.");
		if (FD_ISSET(game->sock, &fd.rdfs))
			ft_new_connection(game, &fd);
		else
			ft_save_request(game, &fd);
	}
	exit(EXIT_SUCCESS);
}

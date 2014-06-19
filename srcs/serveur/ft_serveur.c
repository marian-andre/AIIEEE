/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:07:12 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/19 15:19:41 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "serveur.h"
#include "libft.h"

static void		ft_new_connection(t_game *g, t_fd *fd)
{
	int					cs;
	char				*line;
	unsigned int		cslen;
	struct sockaddr_in	*csin;

	line = NULL;
	cs = accept(g->sock, (struct sockaddr*)&csin, &cslen);
	if (cs < 0)
		ft_error("ERROR socket.");
	ft_putendl_fd("BIENVENUE", cs);
	get_next_line(cs, &line);
	ft_new_client(g, fd, line, cs);
	free(line);
}

static void		ft_save_fd_cli(t_client *cls, t_fd *fd)
{
	int			i;

	i = 0;
	while (i < fd->nb_cli)
	{
		if (cls[i].cs != MORT)
			FD_SET(cls[i].cs, &fd->rdfs);
		i++;
	}
}

static int		ft_win(t_game *g)
{
	int			i;
	int			j;
	int			nb;

	i = 0;
	nb = 0;
	while (g->team[i])
	{
		j = 0;
		nb = 0;
		while (g->cls[j].cs)
		{
			if (g->cls[j].num_team == i && g->cls[j].lvl == 8)
				nb++;
			j++;
		}
		if (nb >= 6)
			return (1);
		i++;
	}
	return (0);
}

void			ft_serveur(t_game *game)
{
	t_fd		fd;
	t_time		timeout;

	timeout.tv_sec = 0;
	timeout.tv_usec = 100;
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
}

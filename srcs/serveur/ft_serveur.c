/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:07:12 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/11 15:25:42 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "serveur.h"
#include "libft.h"

static void		ft_new_connection(t_game *g, t_fd *fd)
{
	char				*line;
	unsigned int		cslen;
	struct sockaddr_in	*csin;

	line = NULL;
	g->cls[fd->nb_cli].cs = accept(g->sock, (struct sockaddr*)&csin, &cslen);
	if (g->cls[fd->nb_cli].cs < 0)
		ft_error("ERROR socket.");
	ft_putendl_fd("BIENVENUE", g->cls[fd->nb_cli].cs);
	get_next_line(g->cls[fd->nb_cli].cs, &line);
	ft_new_client(g, fd, line);
	free(line);
}

static void		ft_save_fd_cli(t_client *cls, t_fd *fd)
{
	int			i;

	i = 0;
	while (i < fd->nb_cli)
	{
		FD_SET(cls[i].cs, &fd->rdfs);
		i++;
	}
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
	while (1)
	{
		ft_exec_request(game, &fd);
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

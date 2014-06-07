/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:55:30 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 09:10:16 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static void	ft_check_cmd(int i, t_game *g, t_fd *fd, char *line)
{
	if (ft_strcmp(line, "avance") == 0)
		ft_move(i, g, fd, line);
	else if (ft_strcmp(line, "droite") == 0)
		ft_right(i, g, fd, line);
	else if (ft_strcmp(line, "gauche") == 0)
		ft_left(i, g, fd, line);
	else if (ft_strcmp(line, "voir") == 0)
		ft_see(i, g, fd, line);
	else if (ft_strcmp(line, "inventaire") == 0)
		ft_stock(i, g, fd, line);
	else if (ft_strncmp(line, "prend", 5) == 0)
		ft_take(i, g, fd, line);
	else if (ft_strncmp(line, "pose", 4) == 0)
		ft_put(i, g, fd, line);
	else if (ft_strcmp(line, "expulse") == 0)
		ft_expel(i, g, fd, line);
	else if (ft_strncmp(line, "broadcast", 9) == 0)
		ft_broadcast(i, g, fd, line);
	else if (ft_strcmp(line, "incantation") == 0)
		ft_spell(i, g, fd, line);
	else if (ft_strcmp(line, "fork") == 0)
		ft_fork(i, g, fd, line);
	else if (ft_strcmp(line, "connect_nbr") == 0)
		ft_nb_connect(i, g, fd, line);
}

static void	ft_recep_message(int i, t_game *g, t_fd *fd)
{
	char	*line;

	line = NULL;
	if (get_next_line(g->cls[i].cs, &line) > 0)
	{
		ft_putstr("command <");
		ft_putstr(line);
		ft_putstr("> from client number ");
		ft_putnbr(i);
		ft_putendl(".");
	}
	else
	{
		close(g->cls[i].cs);
		ft_memmove(g->cls + i, g->cls + i + 1,
					(fd->nb_cli - i - 1) * sizeof(t_client));
		fd->nb_cli--;
	}
	ft_check_cmd(i, g, fd, line);
	free(line);
}

void		ft_exec_request(t_game *g, t_fd *fd)
{
	int			i;

	i = 0;
	while (i < fd->nb_cli)
	{
		if (FD_ISSET(g->cls[i].cs, &fd->rdfs))
		{
			ft_recep_message(i, g, fd);
			break ;
		}
		i++;
	}
}

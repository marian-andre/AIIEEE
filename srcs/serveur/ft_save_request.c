/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 15:55:30 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/09 19:09:45 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static void	ft_recep_message(int i, t_game *g, t_fd *fd)
{
	char	*line;
	t_cmd	*cmd;

	line = NULL;
	if (get_next_line(g->cls[i].cs, &line) > 0)
	{
		ft_putstr("command <");
		ft_putstr(line);
		ft_putstr("> from client number ");
		ft_putnbr(i);
		ft_putendl(".");
		if (ft_strcmp(line, "connect_nbr") == 0)
			ft_nb_connect(g, i);
		else
		{
			cmd = ft_create_node(g, line, i);
			ft_add_node(g, cmd);
		}
		free(line);
	}
	else
	{
		close(g->cls[i].cs);
		ft_memmove(g->cls + i, g->cls + i + 1,
					(fd->nb_cli - i - 1) * sizeof(t_client));
		fd->nb_cli--;
	}
}

void		ft_save_request(t_game *g, t_fd *fd)
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

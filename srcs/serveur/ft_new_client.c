/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 17:06:42 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 11:07:41 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "serveur.h"
#include "libft.h"

static int		ft_check_team(t_game *g, char *line)
{
	int			i;

	i = 0;
	while (g->team[i])
	{
		if (ft_strcmp(g->team[i], line) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static void		ft_check_rand(t_game *g, int num_cli)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = rand() % g->width;
	y = rand() % g->height;
	while (g->cls[i].cs)
	{
		if (g->cls[i].x == x && g->cls[i].y == y)
		{
			x = rand() % g->width;
			y = rand() % g->height;
		}
		else
			i++;
	}
	g->cls[num_cli].x = x;
	g->cls[num_cli].y = y;
	g->map[y][x].nb_player++;
}

static void		ft_send(t_game *g, t_fd *fd)
{
	char		*line;

	g->cls[fd->nb_cli].lvl = 1;
	g->cls[fd->nb_cli].graph = 0;
	g->cls[fd->nb_cli].dir = (rand() % 4) + 1;
	g->cls[fd->nb_cli].resource.linemate = 0;
	g->cls[fd->nb_cli].resource.deraumere = 0;
	g->cls[fd->nb_cli].resource.sibur = 0;
	g->cls[fd->nb_cli].resource.mendiane = 0;
	g->cls[fd->nb_cli].resource.phiras = 0;
	g->cls[fd->nb_cli].resource.thystame = 0;
	g->cls[fd->nb_cli].resource.food = 10;
	ft_check_rand(g, fd->nb_cli);
	ft_graph_pnw(g, fd->nb_cli);
	line = ft_itoa(g->cls[fd->nb_cli].x);
	line = ft_strjoin(line, " ");
	line = ft_strjoin(line, ft_itoa(g->cls[fd->nb_cli].y));
	ft_putendl_fd(ft_itoa(g->max_cli), g->cls[fd->nb_cli].cs);
	ft_putendl_fd(line, g->cls[fd->nb_cli].cs);
	free(line);
	if (g->cls[fd->nb_cli].cs > fd->max)
		fd->max = g->cls[fd->nb_cli].cs;
	FD_SET(g->cls[fd->nb_cli].cs, &fd->rdfs);
	fd->nb_cli++;
}

static void		ft_init_graph(t_game *g, t_fd *fd)
{
	g->cls[fd->nb_cli].graph = 1;
	ft_graph_msz(g, fd->nb_cli);
	ft_graph_sgt(g, fd->nb_cli);
	ft_graph_mct(g, fd->nb_cli);
	ft_graph_tna(g, fd->nb_cli);
	if (g->cls[fd->nb_cli].cs > fd->max)
		fd->max = g->cls[fd->nb_cli].cs;
	FD_SET(g->cls[fd->nb_cli].cs, &fd->rdfs);
	fd->nb_cli++;
}

void			ft_new_client(t_game *g, t_fd *fd, char *line)
{
	t_cmd		*cmd;

	if (ft_strcmp(line, "GRAPHIC") == 0)
		ft_init_graph(g, fd);
	else if ((g->cls[fd->nb_cli].num_team = ft_check_team(g, line)) == -1)
	{
		ft_putendl_fd("ERROR wrong team name", g->cls[fd->nb_cli].cs);
		close(g->cls[fd->nb_cli].cs);
		g->cls[fd->nb_cli].cs = 0;
	}
	else
	{
		cmd = ft_create_node(g, "life", fd->nb_cli);
		ft_add_node(g, cmd);
		ft_send(g, fd);
	}
}

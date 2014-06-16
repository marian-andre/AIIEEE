/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 17:06:42 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/16 14:17:36 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static void		ft_send(t_game *g, t_fd *fd)
{
	char		*line;
	char		*tmp;

	ft_check_rand(g, fd->nb_cli);
	ft_graph_pnw(g, fd->nb_cli);
	line = ft_itoa(g->width);
	line = ft_strjoin_free(line, " ", 1);
	line = ft_strjoin_free(line, ft_itoa(g->height), 3);
	tmp = ft_itoa(g->max_cli[g->cls[fd->nb_cli].num_team]
					- ft_count_nb_co(g, fd->nb_cli));
	ft_putendl_fd(tmp, g->cls[fd->nb_cli].cs);
	ft_putendl_fd(line, g->cls[fd->nb_cli].cs);
	free(tmp);
	free(line);
	if (g->cls[fd->nb_cli].cs > fd->max)
		fd->max = g->cls[fd->nb_cli].cs;
	FD_SET(g->cls[fd->nb_cli].cs, &fd->rdfs);
	fd->nb_cli++;
}

static void		ft_init_cli(t_game *g, t_fd *fd, int cs)
{
	t_cmd		*cmd;

	g->cls[fd->nb_cli].cs = cs;
	cmd = ft_create_node(g, "life", fd->nb_cli);
	ft_add_node(g, cmd);
	g->cls[fd->nb_cli].lvl = 1;
	g->cls[fd->nb_cli].graph = 0;
	g->cls[fd->nb_cli].resource.linemate = 0;
	g->cls[fd->nb_cli].resource.deraumere = 0;
	g->cls[fd->nb_cli].resource.sibur = 0;
	g->cls[fd->nb_cli].resource.mendiane = 0;
	g->cls[fd->nb_cli].resource.phiras = 0;
	g->cls[fd->nb_cli].resource.thystame = 0;
	g->cls[fd->nb_cli].resource.food = 10;
	g->cls[fd->nb_cli].dir = (rand() % 4) + 1;
	ft_send(g, fd);
}

static void		ft_init_egg(t_game *g, t_fd *fd, int i, int cs)
{
	char		*line;
	char		*tmp;

	g->eggs[i].cl.cs = cs;
	g->cls[fd->nb_cli] = g->eggs[i].cl;
	ft_add_node(g, ft_create_node(g, "life", fd->nb_cli));
	g->eggs[i].active = 0;
	ft_graph_pnw(g, fd->nb_cli);
	line = ft_itoa(g->width);
	line = ft_strjoin_free(line, " ", 1);
	line = ft_strjoin_free(line, ft_itoa(g->height), 3);
	tmp = ft_itoa(g->max_cli[g->cls[fd->nb_cli].num_team]
					- ft_count_nb_co(g, fd->nb_cli));
	ft_putendl_fd(tmp, g->cls[fd->nb_cli].cs);
	ft_putendl_fd(line, g->cls[fd->nb_cli].cs);
	free(tmp);
	free(line);
	if (g->cls[fd->nb_cli].cs > fd->max)
		fd->max = g->cls[fd->nb_cli].cs;
	FD_SET(g->cls[fd->nb_cli].cs, &fd->rdfs);
	fd->nb_cli++;
}

void			ft_new_client(t_game *g, t_fd *fd, char *line, int cs)
{
	int			i;

	i = 0;
	if (ft_strcmp(line, "GRAPHIC") == 0)
		ft_init_graph(g, fd, cs);
	else if ((g->cls[fd->nb_cli].num_team = ft_check_team(g, line)) == -1)
	{
		ft_putendl_fd("ERROR wrong team name", cs);
		close(cs);
		cs = 0;
	}
	else if (g->max_cli[g->cls[fd->nb_cli].num_team]
				- ft_count_nb_co(g, fd->nb_cli) < 0)
	{
		ft_putendl_fd("ERROR this team is full.", cs);
		close(cs);
		cs = 0;
	}
	else if ((i = ft_check_eggs(g, line)) != -1)
		ft_init_egg(g, fd, i, cs);
	else
		ft_init_cli(g, fd, cs);
}

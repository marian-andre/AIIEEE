/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 12:12:49 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/19 17:01:47 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		ft_init_graph(t_game *g, t_fd *fd, int cs)
{
	int		i;

	i = 0;
	g->cls[fd->nb_cli].cs = cs;
	g->cls[fd->nb_cli].graph = 1;
	g->cls[fd->nb_cli].num_team = 66;
	ft_graph_msz(g, fd->nb_cli);
	ft_graph_sgt(g, fd->nb_cli);
	ft_graph_mct(g, fd->nb_cli);
	ft_graph_tna(g, fd->nb_cli);
	while (i < MAX_CLI && g->cls[i].cs)
	{
		if (g->cls[i].graph == 0)
			ft_graph_pnw(g, i);
		i++;
	}
	if (g->cls[fd->nb_cli].cs > fd->max)
		fd->max = g->cls[fd->nb_cli].cs;
	FD_SET(g->cls[fd->nb_cli].cs, &fd->rdfs);
	fd->nb_cli++;
}

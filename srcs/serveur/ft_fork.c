/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/13 20:16:23 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_fork(t_cmd *cmd, t_game *g)
{
	static int		i = 0;

	g->eggs[i].active = 1;
	g->eggs[i].nb = i;
	g->eggs[i].x = g->cls[cmd->num_cli].x;
	g->eggs[i].y = g->cls[cmd->num_cli].y;
	g->eggs[i].cl = g->cls[cmd->num_cli];
	i++;
	ft_putendl_fd("ok", cmd->fd);
	ft_add_node(g, ft_create_node(g, "birth", cmd->num_cli));
	ft_graph_pfk(g, cmd->num_cli);
}

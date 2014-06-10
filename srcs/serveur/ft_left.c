/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:38:39 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/10 11:09:13 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_left(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		if (g->cls[cmd->num_cli].dir == NORTH)
			g->cls[cmd->num_cli].dir = WEST;
		else if (g->cls[cmd->num_cli].dir == EAST)
			g->cls[cmd->num_cli].dir = NORTH;
		else if (g->cls[cmd->num_cli].dir == SOUTH)
			g->cls[cmd->num_cli].dir = EAST;
		else if (g->cls[cmd->num_cli].dir == WEST)
			g->cls[cmd->num_cli].dir = SOUTH;
		ft_putendl_fd("ok", cmd->fd);
		ft_graph_ppo(g, cmd->num_cli);
	}
}

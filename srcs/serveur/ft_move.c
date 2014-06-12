/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 11:05:55 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static void		ft_north_south(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].dir == NORTH)
	{
		if (g->cls[cmd->num_cli].y == 0)
			g->cls[cmd->num_cli].y = g->height - 1;
		else
			g->cls[cmd->num_cli].y--;
	}
	else if (g->cls[cmd->num_cli].dir == SOUTH)
	{
		if (g->cls[cmd->num_cli].y == g->height - 1)
			g->cls[cmd->num_cli].y = 0;
		else
			g->cls[cmd->num_cli].y++;
	}
}

void			ft_move(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].nb_player--;
		ft_north_south(cmd, g);
		if (g->cls[cmd->num_cli].dir == EAST)
		{
			if (g->cls[cmd->num_cli].x == g->width - 1)
				g->cls[cmd->num_cli].x = 0;
			else
				g->cls[cmd->num_cli].x++;
		}
		else if (g->cls[cmd->num_cli].dir == WEST)
		{
			if (g->cls[cmd->num_cli].x == 0)
				g->cls[cmd->num_cli].x = g->width - 1;
			else
				g->cls[cmd->num_cli].x--;
		}
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].nb_player++;
		ft_putendl_fd("ok", cmd->fd);
		ft_graph_ppo(g, cmd->num_cli);
	}
}

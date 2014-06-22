/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:12:45 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/22 18:00:42 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "serveur.h"
#include "libft.h"

static void		ft_drop_all(t_game *g, int num_cli)
{
	int		x;
	int		y;

	x = g->cls[num_cli].x;
	y = g->cls[num_cli].y;
	g->map[y][x].linemate += g->cls[num_cli].resource.linemate;
	g->map[y][x].deraumere += g->cls[num_cli].resource.deraumere;
	g->map[y][x].sibur += g->cls[num_cli].resource.sibur;
	g->map[y][x].mendiane += g->cls[num_cli].resource.mendiane;
	g->map[y][x].phiras += g->cls[num_cli].resource.phiras;
	g->map[y][x].thystame += g->cls[num_cli].resource.thystame;
	ft_graph_bct(g, 0, x, y);
}

static void		ft_death(t_cmd *cmd, t_game *g)
{
	ft_drop_all(g, cmd->num_cli);
	g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].nb_player--;
	ft_putstr("\033[31;01mClient ");
	ft_putnbr(cmd->num_cli);
	ft_putendl(" died.\033[00m");
	ft_putendl_fd("mort", cmd->fd);
	ft_graph_pdi(g, cmd->num_cli);
	close(g->cls[cmd->num_cli].cs);
	g->cls[cmd->num_cli].cs = MORT;
	g->cls[cmd->num_cli].num_team = MORT;
}

void			ft_life(t_cmd *cmd, t_game *g)
{
	t_cmd	*tmp;

	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		g->cls[cmd->num_cli].resource.nourriture--;
		if (g->cls[cmd->num_cli].resource.nourriture <= 0)
			ft_death(cmd, g);
		else
		{
			tmp = ft_create_node(g, "life", cmd->num_cli, 0);
			ft_add_node(g, tmp);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/17 14:10:49 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static void	ft_take_thystame(t_cmd *cmd, t_game *g)
{
	if (g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].thystame > 0)
	{
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].thystame--;
		g->cls[cmd->num_cli].resource.thystame++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_take_graph(cmd, g, 6);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

static void	ft_take_food(t_cmd *cmd, t_game *g)
{
	if (g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].nourriture > 0)
	{
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].nourriture--;
		g->cls[cmd->num_cli].resource.nourriture++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_take_graph(cmd, g, 0);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void		ft_send_take_graph(t_cmd *cmd, t_game *g, int resource)
{
	ft_graph_pgt(g, cmd->num_cli, resource);
	ft_graph_pin(g, cmd->num_cli);
	ft_graph_bct(g, 0, g->cls[cmd->num_cli].x, g->cls[cmd->num_cli].y);
}

void		ft_take(t_cmd *cmd, t_game *g)
{
	char	**split;

	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		split = ft_strsplit(cmd->cmd, ' ');
		if (ft_strcmp("linemate", split[1]) == 0)
			ft_take_linemate(cmd, g);
		else if (ft_strcmp("deraumere", split[1]) == 0)
			ft_take_deraumere(cmd, g);
		else if (ft_strcmp("sibur", split[1]) == 0)
			ft_take_sibur(cmd, g);
		else if (ft_strcmp("mendiane", split[1]) == 0)
			ft_take_mendiane(cmd, g);
		else if (ft_strcmp("phiras", split[1]) == 0)
			ft_take_phiras(cmd, g);
		else if (ft_strcmp("thystame", split[1]) == 0)
			ft_take_thystame(cmd, g);
		else if (ft_strcmp("nourriture", split[1]) == 0)
			ft_take_food(cmd, g);
		else
			ft_putendl_fd("ko", cmd->fd);
		ft_strdel2(&split);
	}
}

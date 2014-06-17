/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/17 14:08:53 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static void	ft_put_thystame(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].resource.thystame > 0)
	{
		g->cls[cmd->num_cli].resource.thystame--;
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].thystame++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_put_graph(cmd, g, 6);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

static void	ft_put_food(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].resource.nourriture > 0)
	{
		g->cls[cmd->num_cli].resource.nourriture--;
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].nourriture++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_put_graph(cmd, g, 0);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void		ft_send_put_graph(t_cmd *cmd, t_game *g, int resource)
{
	ft_graph_pdr(g, cmd->num_cli, resource);
	ft_graph_pin(g, cmd->num_cli);
	ft_graph_bct(g, 0, g->cls[cmd->num_cli].x, g->cls[cmd->num_cli].y);
}

void		ft_put(t_cmd *cmd, t_game *g)
{
	char	**split;

	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		split = ft_strsplit(cmd->cmd, ' ');
		if (ft_strcmp("linemate", split[1]) == 0)
			ft_put_linemate(cmd, g);
		else if (ft_strcmp("deraumere", split[1]) == 0)
			ft_put_deraumere(cmd, g);
		else if (ft_strcmp("sibur", split[1]) == 0)
			ft_put_sibur(cmd, g);
		else if (ft_strcmp("mendiane", split[1]) == 0)
			ft_put_mendiane(cmd, g);
		else if (ft_strcmp("phiras", split[1]) == 0)
			ft_put_phiras(cmd, g);
		else if (ft_strcmp("thystame", split[1]) == 0)
			ft_put_thystame(cmd, g);
		else if (ft_strcmp("nourriture", split[1]) == 0)
			ft_put_food(cmd, g);
		else
			ft_putendl_fd("ko", cmd->fd);
		ft_strdel2(&split);
	}
}

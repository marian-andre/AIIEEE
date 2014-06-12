/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_resource.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 18:51:43 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 12:49:13 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void	ft_take_linemate(t_cmd *cmd, t_game *g)
{
	if (g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].linemate > 0)
	{
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].linemate--;
		g->cls[cmd->num_cli].resource.linemate++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_take_graph(cmd, g, 1);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void	ft_take_deraumere(t_cmd *cmd, t_game *g)
{
	if (g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].deraumere > 0)
	{
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].deraumere--;
		g->cls[cmd->num_cli].resource.deraumere++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_take_graph(cmd, g, 2);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void	ft_take_sibur(t_cmd *cmd, t_game *g)
{
	if (g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].sibur > 0)
	{
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].sibur--;
		g->cls[cmd->num_cli].resource.sibur++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_take_graph(cmd, g, 3);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void	ft_take_mendiane(t_cmd *cmd, t_game *g)
{
	if (g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].mendiane > 0)
	{
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].mendiane--;
		g->cls[cmd->num_cli].resource.mendiane++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_take_graph(cmd, g, 4);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void	ft_take_phiras(t_cmd *cmd, t_game *g)
{
	if (g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].phiras > 0)
	{
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].phiras--;
		g->cls[cmd->num_cli].resource.phiras++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_take_graph(cmd, g, 5);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

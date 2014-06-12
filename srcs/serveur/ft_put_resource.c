/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_resource.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 09:36:14 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 13:20:01 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_put_linemate(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].resource.linemate > 0)
	{
		g->cls[cmd->num_cli].resource.linemate--;
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].linemate++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_put_graph(cmd, g, 1);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void		ft_put_deraumere(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].resource.deraumere > 0)
	{
		g->cls[cmd->num_cli].resource.deraumere--;
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].deraumere++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_put_graph(cmd, g, 2);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void		ft_put_sibur(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].resource.sibur > 0)
	{
		g->cls[cmd->num_cli].resource.sibur--;
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].sibur++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_put_graph(cmd, g, 3);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void		ft_put_mendiane(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].resource.mendiane > 0)
	{
		g->cls[cmd->num_cli].resource.mendiane--;
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].mendiane++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_put_graph(cmd, g, 4);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

void		ft_put_phiras(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].resource.phiras > 0)
	{
		g->cls[cmd->num_cli].resource.phiras--;
		g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].phiras++;
		ft_putendl_fd("ok", cmd->fd);
		ft_send_put_graph(cmd, g, 5);
	}
	else
		ft_putendl_fd("ko", cmd->fd);
}

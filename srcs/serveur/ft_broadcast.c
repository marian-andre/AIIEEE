/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broadcast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/13 20:32:15 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static int		ft_dir(t_game *g, int num_cli, int card)
{
	int		dir;

	dir = g->cls[num_cli].dir;
	if ((dir == NORTH && card == SOUTH) || (dir == SOUTH && card == NORTH)
		|| (dir == WEST && card == EAST) || (dir == EAST && card == WEST))
		return (5);
	if ((dir == EAST && card == NORTH) || (dir == SOUTH && card == EAST)
		|| (dir == WEST && card == SOUTH) || (dir == NORTH && card == WEST))
		return (3);
	if ((dir == NORTH && card == NORTH) || (dir == SOUTH && card == SOUTH)
		|| (dir == WEST && card == WEST) || (dir == EAST && card == EAST))
		return (1);
	return (7);
}

static int		ft_get_k(t_game *g, int num_cli, int i)
{
	t_var	var;

	if (g->cls[num_cli].x == g->cls[i].x && g->cls[num_cli].y == g->cls[i].y)
		return (0);
	var.new_x = g->cls[num_cli].x - g->cls[i].x;
	var.new_y = g->cls[num_cli].y - g->cls[i].y;
	if (abs(var.new_x) < abs(var.new_y))
	{
		if (var.new_y > 0)
			return (ft_dir(g, i, SOUTH));
		else
			return (ft_dir(g, i, NORTH));
	}
	else
	{
		if (var.new_x > 0)
			return (ft_dir(g, i, EAST));
		else
			return (ft_dir(g, i, WEST));
	}
}

void			ft_broadcast(t_cmd *cmd, t_game *g)
{
	int		k;
	int		i;

	if (g->cls[cmd->num_cli].cs == MORT)
		return ;
	i = 0;
	while (i < MAX_CLI && g->cls[i].cs)
	{
		if (g->cls[i].cs != MORT)
		{
			k = ft_get_k(g, cmd->num_cli, i);
			ft_putstr_fd("message ", g->cls[i].cs);
			ft_putnbr_fd(k, g->cls[i].cs);
			ft_putstr_fd(",", g->cls[i].cs);
			ft_putendl_fd(&cmd->cmd[10], g->cls[i].cs);
		}
		i++;
	}
	ft_graph_pbc(g, cmd->num_cli, &cmd->cmd[10]);
}

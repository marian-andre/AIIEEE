/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/23 19:12:06 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static int		ft_find_k(int dir_o, int dir_v)
{
	if ((dir_o == NORTH && dir_v == SOUTH)
		|| (dir_o == SOUTH && dir_v == NORTH)
		|| (dir_o == EAST && dir_v == WEST)
		|| (dir_o == WEST && dir_v == EAST))
		return (1);
	else if ((dir_o == NORTH && dir_v == WEST)
		|| (dir_o == SOUTH && dir_v == EAST)
		|| (dir_o == EAST && dir_v == NORTH)
		|| (dir_o == WEST && dir_v == SOUTH))
		return (3);
	else if ((dir_o == NORTH && dir_v == NORTH)
		|| (dir_o == SOUTH && dir_v == SOUTH)
		|| (dir_o == EAST && dir_v == EAST)
		|| (dir_o == WEST && dir_v == WEST))
		return (5);
	else
		return (7);
}

static void		ft_get_out(t_game *g, int i, int dir)
{
	if (dir == NORTH)
		g->cls[i].x -= 1;
	else if (dir == SOUTH)
		g->cls[i].x += 1;
	else if (dir == EAST)
		g->cls[i].y += 1;
	else if (dir == WEST)
		g->cls[i].y -= 1;
	if (g->cls[i].y < 0)
		g->cls[i].y = g->height - 1;
	if (g->cls[i].y >= g->height)
		g->cls[i].y = 0;
	if (g->cls[i].x < 0)
		g->cls[i].x = g->width - 1;
	if (g->cls[i].x >= g->width)
		g->cls[i].x = 0;
	ft_putstr_fd("deplacement ", g->cls[i].cs);
	ft_putnbr_fd(ft_find_k(dir, g->cls[i].dir), g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

void			ft_expel(t_cmd *cmd, t_game *g)
{
	int		i;
	int		x;
	int		y;

	if (g->cls[cmd->num_cli].cs == MORT)
		return ;
	x = g->cls[cmd->num_cli].x;
	y = g->cls[cmd->num_cli].y;
	i = -1;
	while (++i < MAX_CLI && g->cls[i].cs)
	{
		if (cmd->num_cli != i && g->cls[i].cs != MORT
			&& g->cls[i].x == x && g->cls[i].y == y)
			ft_get_out(g, i, g->cls[cmd->num_cli].dir);
	}
	ft_graph_pex(g, cmd->num_cli);
}

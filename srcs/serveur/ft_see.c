/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/11 16:35:54 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"
#include <stdlib.h>

static char		*check_case(t_game *g, t_var var, char *msg, int k)
{
	int		i;
	char	*del;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].linemate)
	{
		del = msg;
		msg = ft_strjoin(msg, " linemate");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].deraumere)
	{
		del = msg;
		msg = ft_strjoin(msg, " deraumere");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].sibur)
	{
		del = msg;
		msg = ft_strjoin(msg, " sibur");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].mendiane)
	{
		del = msg;
		msg = ft_strjoin(msg, " mendiane");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].phiras)
	{
		del = msg;
		msg = ft_strjoin(msg, " phiras");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].thystame)
	{
		del = msg;
		msg = ft_strjoin(msg, " thystame");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].food)
	{
		del = msg;
		msg = ft_strjoin(msg, " nourriture");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].nb_player - k)
	{
		del = msg;
		msg = ft_strjoin(msg, " joueur");
		free(del);
	}
	return (msg);
}

static t_var	init_var(t_game *g, t_cmd *cmd, t_var var)
{
	var.i = 0;
	var.j = 0;
	var.x = g->cls[cmd->num_cli].x;
	var.y = g->cls[cmd->num_cli].y;
	var.new_x = g->cls[cmd->num_cli].x;
	var.new_y = g->cls[cmd->num_cli].y;
	var.lvl = g->cls[cmd->num_cli].lvl;
	return (var);
}

static void		get_true_pos(t_game *g, t_cmd *cmd, t_var *var)
{
	if (g->cls[cmd->num_cli].dir == NORTH)
	{
		if ((var->x + var->j) >= g->width)
			var->new_x = var->x + var->j - g->width;
		else if ((var->x + var->j) < 0)
			var->new_x = g->width - (var->x + var->j);
		else
			var->new_x = var->x + var->j;
		if ((var->y - var->i) < 0)
			var->new_y = var->y - var->i + g->height;
		else
			var->new_y = var->y - var->i;
	}
	else if (g->cls[cmd->num_cli].dir == SOUTH)
	{
		if ((var->x - var->j) >= g->width)
			var->new_x = var->x - var->j - g->width;
		else if ((var->x - var->j) < 0)
			var->new_x = g->width - (var->x - var->j);
		else
			var->new_x = var->x - var->j;
		if ((var->y + var->i) >= g->height)
			var->new_y = var->y + var->i - g->height;
		else
			var->new_y = var->y + var->i;
	}
	else if (g->cls[cmd->num_cli].dir == EAST)
	{
		if ((var->y - var->j) >= g->height)
			var->new_y = var->y - var->j - g->height;
		else if ((var->y - var->j) < 0)
			var->new_y = g->height - (var->y - var->j);
		else
			var->new_y = var->y - var->j;
		if ((var->x + var->i) >= g->width)
			var->new_x = var->x + var->i - g->width;
		else
			var->new_x = var->x + var->i;
	}
	else if (g->cls[cmd->num_cli].dir == WEST)
	{
		if ((var->y + var->j) >= g->width)
			var->new_y = var->y + var->j - g->width;
		else if ((var->y + var->j) < 0)
			var->new_y = g->width - (var->y + var->j);
		else
			var->new_y = var->y + var->j;
		if ((var->x - var->i) < 0)
			var->new_x = var->x - var->i + g->width;
		else
			var->new_x = var->x - var->i;
	}
}

void			ft_see(t_cmd *cmd, t_game *g)
{
	t_var	var;
	char	*msg;
	char	*del;

	msg = NULL;
	var = init_var(g, cmd, var);
	msg = check_case(g, var, msg, 1);
	var.i = 1;
	del = msg;
	msg = ft_strtrim(msg);
	free(del);
	del = msg;
	msg = ft_strjoin("{", msg);
	free(del);
	del = msg;
	msg = ft_strjoin(msg, ",");
	free(del);
	while (var.i <= var.lvl)
	{
		var.j = 0 - var.i;
		while (var.j <= var.i)
		{
			get_true_pos(g, cmd, &var);
			msg = check_case(g, var, msg, 0);
			if (var.j != var.i)
			{
				del = msg;
				msg = ft_strjoin(msg, ",");
				free(del);
			}
			var.j++;
		}
		var.i++;
	}
	del = msg;
	msg = ft_strjoin(msg, "}");
	free(del);
	ft_putendl_fd(msg, cmd->fd);
}

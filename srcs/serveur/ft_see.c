/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 19:43:58 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static char		*check_case(t_game *g, t_var var, char *msg, int k)
{
	linemate_deraumere(g, &msg, var);
	sibur_mendiane(g, &msg, var);
	phiras_thystame(g, &msg, var);
	nourriture_joueur(g, &msg, var, k);
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
		ft_north(g, var);
	else if (g->cls[cmd->num_cli].dir == SOUTH)
		ft_south(g, var);
	else if (g->cls[cmd->num_cli].dir == EAST)
		ft_east(g, var);
	else if (g->cls[cmd->num_cli].dir == WEST)
		ft_west(g, var);
}

static void		ft_while(t_game *g, t_cmd *cmd, t_var var, char **msg)
{
	while (var.i <= var.lvl)
	{
		var.j = 0 - var.i;
		while (var.j <= var.i)
		{
			get_true_pos(g, cmd, &var);
			*msg = check_case(g, var, *msg, 0);
			if (var.j != var.i || var.i != var.lvl)
				*msg = ft_strjoin_free(*msg, ",", 1);
			var.j++;
		}
		var.i++;
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
	msg = ft_strjoin_free("{", msg, 2);
	msg = ft_strjoin_free(msg, ",", 1);
	ft_while(g, cmd, var, &msg);
	msg = ft_strjoin_free(msg, "}", 1);
	ft_putendl_fd(msg, cmd->fd);
}

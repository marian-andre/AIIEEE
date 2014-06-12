/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbidden_forest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:49:23 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/12 16:08:20 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

void	linemate_deraumere(t_game *g, char **msg, t_var var)
{
	char	*del;
	int		i;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].linemate)
	{
		del = *msg;
		*msg = ft_strjoin(*msg, " linemate");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].deraumere)
	{
		del = *msg;
		*msg = ft_strjoin(*msg, " deraumere");
		free(del);
	}
}

void	sibur_mendiane(t_game *g, char **msg, t_var var)
{
	int		i;
	char	*del;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].sibur)
	{
		del = *msg;
		*msg = ft_strjoin(*msg, " sibur");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].mendiane)
	{
		del = *msg;
		*msg = ft_strjoin(*msg, " mendiane");
		free(del);
	}
}

void	phiras_thystame(t_game *g, char **msg, t_var var)
{
	int		i;
	char	*del;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].phiras)
	{
		del = *msg;
		*msg = ft_strjoin(*msg, " phiras");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].thystame)
	{
		del = *msg;
		*msg = ft_strjoin(*msg, " thystame");
		free(del);
	}
}

void	nourriture_joueur(t_game *g, char **msg, t_var var, int k)
{
	int		i;
	char	*del;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].food)
	{
		del = *msg;
		*msg = ft_strjoin(*msg, " nourriture");
		free(del);
	}
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].nb_player - k)
	{
		del = *msg;
		*msg = ft_strjoin(*msg, " joueur");
		free(del);
	}
}

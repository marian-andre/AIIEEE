/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbidden_forest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:49:23 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/17 14:12:16 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

void	linemate_deraumere(t_game *g, char **msg, t_var var)
{
	int		i;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].linemate)
		*msg = ft_strjoin_free(*msg, " linemate", 1);
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].deraumere)
		*msg = ft_strjoin_free(*msg, " deraumere", 1);
}

void	sibur_mendiane(t_game *g, char **msg, t_var var)
{
	int		i;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].sibur)
		*msg = ft_strjoin_free(*msg, " sibur", 1);
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].mendiane)
		*msg = ft_strjoin_free(*msg, " mendiane", 1);
}

void	phiras_thystame(t_game *g, char **msg, t_var var)
{
	int		i;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].phiras)
		*msg = ft_strjoin_free(*msg, " phiras", 1);
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].thystame)
		*msg = ft_strjoin_free(*msg, " thystame", 1);
}

void	nourriture_joueur(t_game *g, char **msg, t_var var, int k)
{
	int		i;

	i = -1;
	while (++i < g->map[var.new_y][var.new_x].nourriture)
		*msg = ft_strjoin_free(*msg, " nourriture", 1);
	i = -1;
	while (++i < g->map[var.new_y][var.new_x].nb_player - k)
		*msg = ft_strjoin_free(*msg, " joueur", 1);
}

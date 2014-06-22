/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amazonie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:18:39 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/22 15:12:26 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	ft_north(t_game *g, t_var *var)
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

void	ft_south(t_game *g, t_var *var)
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

void	ft_east(t_game *g, t_var *var)
{
	if ((var->y + var->j) >= g->height)
		var->new_y = var->y + var->j - g->height;
	else if ((var->y + var->j) < 0)
		var->new_y = g->height - (var->y - var->j);
	else
		var->new_y = var->y + var->j;
	if ((var->x + var->i) >= g->width)
		var->new_x = var->x + var->i - g->width;
	else
		var->new_x = var->x + var->i;
}

void	ft_west(t_game *g, t_var *var)
{
	if ((var->y - var->j) >= g->height)
		var->new_y = var->y - var->j - g->height;
	else if ((var->y - var->j) < 0)
		var->new_y = g->height - (var->y + var->j);
	else
		var->new_y = var->y - var->j;
	if ((var->x - var->i) < 0)
		var->new_x = var->x - var->i + g->width;
	else
		var->new_x = var->x - var->i;
}

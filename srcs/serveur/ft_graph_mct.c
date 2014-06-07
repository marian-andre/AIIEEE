/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_mct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 19:44:11 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/05 19:49:36 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_mct(t_game *g, int i)
{
	int		x;
	int		y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			ft_graph_bct(g, i, x, y);
			x++;
		}
		y++;
	}
}

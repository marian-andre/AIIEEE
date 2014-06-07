/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_tna.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 09:13:56 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 09:21:02 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_tna(t_game *g, int i)
{
	int		team;

	team = 0;
	while (g->team[team])
	{
		ft_putstr_fd("tna ", g->cls[i].cs);
		ft_putendl_fd(g->team[team], g->cls[i].cs);
		team++;
	}
}

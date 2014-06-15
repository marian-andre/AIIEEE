/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_connect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/15 19:43:27 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "serveur.h"
#include "libft.h"

int			ft_count_nb_co(t_game *g, int i)
{
	int		nb;
	int		j;

	nb = 0;
	j = 0;
	while (g->cls[j].cs)
	{
		if (g->cls[j].num_team == g->cls[i].num_team)
			nb++;
		j++;
	}
	return (nb);
}

void		ft_nb_connect(t_game *g, int i)
{
	int		nb;

	nb = ft_count_nb_co(g, i);
	dprintf(g->cls[i].cs, "%d\n", g->max_cli[g->cls[i].num_team] - nb);
}

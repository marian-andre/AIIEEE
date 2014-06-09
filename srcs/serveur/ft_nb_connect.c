/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_connect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/09 18:55:52 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "serveur.h"
#include "libft.h"

void		ft_nb_connect(t_game *g, int i)
{
	int		nb;
	int		j;

	j = 0 ;
	nb = 0;
	while (g->cls[j].cs)
	{
		if (g->cls[j].num_team == g->cls[i].num_team)
			nb++;
		j++;
	}
	dprintf(g->cls[i].cs, "%d\n", g->max_cli - nb);
}

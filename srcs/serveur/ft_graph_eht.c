/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_eht.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 13:36:15 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/17 16:53:38 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_eht(t_game *g, int nb_egg)
{
	int		i;

	i = 0;
	while (g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			ft_putstr_fd("eht ", g->cls[i].cs);
			ft_putnbr_fd(nb_egg, g->cls[i].cs);
			ft_putchar_fd('\n', g->cls[i].cs);
		}
		i++;
	}
}

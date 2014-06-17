/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:59:06 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/17 14:18:31 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_pdi(t_game *g, int num_cli)
{
	int		i;

	i = 0;
	while (g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			ft_putstr_fd("pdi ", g->cls[i].cs);
			ft_putnbr_fd(num_cli, g->cls[i].cs);
			ft_putchar_fd('\n', g->cls[i].cs);
		}
		i++;
	}
}

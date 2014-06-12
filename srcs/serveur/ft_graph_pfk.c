/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pfk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:41:38 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 15:51:22 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_pfk(t_game *g, int num_cli)
{
	int		i;

	i = 0;
	while (g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			ft_putstr_fd("pfk ", g->cls[i].cs);
			ft_putnbr_fd(num_cli, g->cls[i].cs);
			ft_putchar_fd('\n', g->cls[i].cs);
		}
		i++;
	}
}

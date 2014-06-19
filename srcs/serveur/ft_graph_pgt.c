/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pgt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:43:56 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/19 17:00:20 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_pgt(t_game *g, int num_cli, int resource)
{
	int		i;

	i = 0;
	while (i < MAX_CLI && g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			ft_putstr_fd("pgt ", g->cls[i].cs);
			ft_putnbr_fd(num_cli, g->cls[i].cs);
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putnbr_fd(resource, g->cls[i].cs);
			ft_putchar_fd('\n', g->cls[i].cs);
		}
		i++;
	}
}

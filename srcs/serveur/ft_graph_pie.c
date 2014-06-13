/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:22:29 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/13 12:09:14 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_pie(t_game *g, int num_cli, int res)
{
	int		i;

	i = 0;
	while (g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			ft_putstr_fd("pie ", g->cls[i].cs);
			ft_putnbr_fd(g->cls[num_cli].x, g->cls[i].cs);
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putnbr_fd(g->cls[num_cli].y, g->cls[i].cs);
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putnbr_fd(res, g->cls[i].cs);
			ft_putchar_fd('\n', g->cls[i].cs);
		}
		i++;
	}
}

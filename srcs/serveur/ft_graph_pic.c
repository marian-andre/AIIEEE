/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:04:31 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 14:15:03 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_pic(t_game *g, int i, int num_cli)
{
	int		j;

	j = 0;
	ft_putstr_fd("pic ", g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].x, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].y, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].lvl, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(num_cli, g->cls[i].cs);
	while (g->cls[j].cs)
	{
		if (j != num_cli && g->cls[j].x == g->cls[num_cli].x
			&& g->cls[j].y == g->cls[num_cli].y)
		{
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putnbr_fd(j, g->cls[i].cs);
		}
		j++;
	}
	ft_putchar_fd('\n', g->cls[i].cs);
}

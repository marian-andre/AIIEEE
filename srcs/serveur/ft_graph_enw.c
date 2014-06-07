/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_enw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:39:04 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 18:50:59 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_enw(t_game *g, int i, int num_cli)
{
	int		j;

	j = 0;
	ft_putstr_fd("enw ", g->cls[i].cs);
	while (g->eggs[j].nb)
	{
		if (g->eggs[j].active == 1 && g->eggs[j].cl.cs == g->cls[num_cli].cs
			&& g->eggs[j].x == g->cls[num_cli].x
			&& g->eggs[j].y == g->cls[num_cli].y)
			break ;
		j++;
	}
	ft_putnbr_fd(g->eggs[j].nb, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[j].cs);
	ft_putnbr_fd(num_cli, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[j].cs);
	ft_putnbr_fd(g->eggs[j].x, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[j].cs);
	ft_putnbr_fd(g->eggs[j].y, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[j].cs);
}

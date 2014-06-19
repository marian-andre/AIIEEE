/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pnw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 09:21:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/19 17:01:07 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_pnw(t_game *g, int num_cli)
{
	int		i;

	i = 0;
	while (i < MAX_CLI && g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			ft_putstr_fd("pnw ", g->cls[i].cs);
			ft_putnbr_fd(num_cli, g->cls[i].cs);
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putnbr_fd(g->cls[num_cli].x, g->cls[i].cs);
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putnbr_fd(g->cls[num_cli].y, g->cls[i].cs);
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putnbr_fd(g->cls[num_cli].dir, g->cls[i].cs);
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putnbr_fd(g->cls[num_cli].lvl, g->cls[i].cs);
			ft_putchar_fd(' ', g->cls[i].cs);
			ft_putstr_fd(g->team[g->cls[num_cli].num_team], g->cls[i].cs);
			ft_putchar_fd('\n', g->cls[i].cs);
		}
		i++;
	}
}

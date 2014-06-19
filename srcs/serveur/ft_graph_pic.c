/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:04:31 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/19 17:00:32 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static void	ft_send_pic(t_game *g, int i, int num_cli)
{
	ft_putstr_fd("pic ", g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].x, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].y, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].lvl, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(num_cli, g->cls[i].cs);
}

void		ft_graph_pic(t_game *g, int num_cli)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAX_CLI && g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			j = 0;
			ft_send_pic(g, i, num_cli);
			while (g->cls[j].cs)
			{
				if (j != num_cli && g->cls[j].x == g->cls[num_cli].x
					&& g->cls[j].y == g->cls[num_cli].y
					&& g->cls[i].lvl == g->cls[num_cli].lvl)
				{
					ft_putchar_fd(' ', g->cls[i].cs);
					ft_putnbr_fd(j, g->cls[i].cs);
				}
				j++;
			}
			ft_putchar_fd('\n', g->cls[i].cs);
		}
		i++;
	}
}

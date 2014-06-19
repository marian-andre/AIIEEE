/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_bct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 19:18:39 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/19 16:58:19 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static void	ft_send_bct(t_game *g, int i, int x, int y)
{
	ft_putstr_fd("bct ", g->cls[i].cs);
	ft_putnbr_fd(x, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(y, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->map[y][x].nourriture, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->map[y][x].linemate, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->map[y][x].deraumere, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->map[y][x].sibur, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->map[y][x].mendiane, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->map[y][x].phiras, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->map[y][x].thystame, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

void		ft_graph_bct(t_game *g, int i, int x, int y)
{
	if (i == 0)
	{
		while (i < MAX_CLI && g->cls[i].cs)
		{
			if (g->cls[i].graph == 1)
				ft_send_bct(g, i, x, y);
			i++;
		}
	}
	else
		ft_send_bct(g, i, x, y);
}

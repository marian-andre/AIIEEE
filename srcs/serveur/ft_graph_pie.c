/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:22:29 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 14:41:26 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_pie(t_game *g, int i, int num_cli, int res)
{
	ft_putstr_fd("pie ", g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].x, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].y, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(res, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

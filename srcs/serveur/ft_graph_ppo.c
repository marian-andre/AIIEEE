/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_ppo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 10:31:59 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 10:54:39 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_ppo(t_game *g, int i, int num_cli)
{
	ft_putstr_fd("ppo ", g->cls[i].cs);
	ft_putnbr_fd(num_cli, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].x, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].y, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->cls[num_cli].dir, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

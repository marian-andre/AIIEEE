/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_msz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 18:59:33 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/05 19:42:15 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_msz(t_game *g, int i)
{
	ft_putstr_fd("msz ", g->cls[i].cs);
	ft_putnbr_fd(g->width, g->cls[i].cs);
	ft_putstr_fd(" ", g->cls[i].cs);
	ft_putnbr_fd(g->height, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

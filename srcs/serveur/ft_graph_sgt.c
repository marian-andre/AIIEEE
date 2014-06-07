/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_sgt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 19:09:46 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 10:11:55 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_sgt(t_game *g, int i)
{
	ft_putstr_fd("sgt ", g->cls[i].cs);
	ft_putnbr_fd(g->time, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_eht.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 13:36:15 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/07 15:08:47 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_eht(t_game *g, int i, int nb_egg)
{
	ft_putstr_fd("eht ", g->cls[i].cs);
	ft_putnbr_fd(nb_egg, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_ebo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 15:09:21 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/07 15:10:44 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_ebo(t_game *g, int i, int nb_egg)
{
	ft_putstr_fd("ebo ", g->cls[i].cs);
	ft_putnbr_fd(nb_egg, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

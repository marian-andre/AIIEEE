/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_edi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 15:11:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/07 15:14:31 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_edi(t_game *g, int i, int nb_egg)
{
	ft_putstr_fd("edi ", g->cls[i].cs);
	ft_putnbr_fd(nb_egg, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

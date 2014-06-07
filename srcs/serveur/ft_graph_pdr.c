/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pdr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:43:56 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 14:57:06 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_pdr(t_game *g, int i, int num_cli, int resource)
{
	ft_putstr_fd("pdr ", g->cls[i].cs);
	ft_putnbr_fd(num_cli, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(resource, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

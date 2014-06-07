/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_seg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:06:18 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 15:08:17 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_seg(t_game *g, int i, char *team)
{
	ft_putstr_fd("seg ", g->cls[i].cs);
	ft_putendl_fd(team, g->cls[i].cs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_smg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:09:04 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 15:39:35 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_smg(t_game *g, int i, char *msg)
{
	ft_putstr_fd("smg ", g->cls[i].cs);
	ft_putendl_fd(msg, g->cls[i].cs);
}

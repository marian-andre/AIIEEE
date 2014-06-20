/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_seg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:06:18 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/20 02:19:00 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_seg(t_game *g, char *team)
{
	int		i;

	i = 0;
	while (i < MAX_CLI && g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			ft_putstr_fd("seg ", g->cls[i].cs);
			ft_putendl_fd(team, g->cls[i].cs);
		}
		i++;
	}
}

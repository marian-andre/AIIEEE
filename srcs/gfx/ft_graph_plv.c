/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_plv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:00:10 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/14 15:49:50 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_plv(t_game *game, char *line)
{
	int		i;
	char	**tab;

	i = ft_atoi(tab[1]);
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_plv");
	game->client[i].lvl = ft_atoi(tab[2]);
	ft_strdel2(&tab);
}

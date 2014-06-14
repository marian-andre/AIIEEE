/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_ppo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:59:59 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/14 17:21:30 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_ppo(t_game *game, char *line)
{
	int		i;
	char	**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_ppo");
	i = ft_atoi(tab[1]);
	game->client[i].x = ft_atoi(tab[2]);
	game->client[i].y = ft_atoi(tab[3]);
	game->client[i].dir = ft_atoi(tab[4]);
	ft_putendl("ppo end");
	ft_strdel2(&tab);
}

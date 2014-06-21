/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_bct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 21:07:36 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/21 16:21:00 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "libft.h"

void		ft_graph_bct(t_game *game, char *line)
{
	char	**tab;
	int		x;
	int		y;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> tab in ft_graph_bct");
	x = ft_atoi(tab[1]);
	y = ft_atoi(tab[2]);
	game->map[y][x].food = ft_atoi(tab[3]);
	game->map[y][x].linemate = ft_atoi(tab[4]);
	game->map[y][x].deraumere = ft_atoi(tab[5]);
	game->map[y][x].sibur = ft_atoi(tab[6]);
	game->map[y][x].mendiane = ft_atoi(tab[7]);
	game->map[y][x].phiras = ft_atoi(tab[8]);
	game->map[y][x].thystame = ft_atoi(tab[9]);
	ft_strdel2(&tab);
}

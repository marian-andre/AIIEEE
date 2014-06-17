/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:20 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/17 15:24:47 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_pdi(t_game *game, char *line)
{
	int		i;
	char	**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pdi");
	i = ft_atoi(tab[1]);
	game->map[game->client[i].y][game->client[i].x].nb_player--;
	game->client[i].x = 0;
	game->client[i].y = 0;
	game->client[i].num_team = -1;
	game->client[i].lvl = 0;
	game->client[i].dir = 0;
	game->client[i].resource.food = 0;
	game->client[i].resource.linemate = 0;
	game->client[i].resource.deraumere = 0;
	game->client[i].resource.sibur = 0;
	game->client[i].resource.mendiane = 0;
	game->client[i].resource.phiras = 0;
	game->client[i].resource.thystame = 0;
	ft_strdel2(&tab);
}

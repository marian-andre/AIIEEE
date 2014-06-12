/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:00:37 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/12 18:40:49 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_pex(t_game *game, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pex");
	while (game->client[i] && game-client[i].num_team != ft_atoi(tab[1]))
		i++;
	if (game->client[i])
	{
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
	}
}

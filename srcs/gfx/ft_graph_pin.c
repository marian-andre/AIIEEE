/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:00:25 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/12 19:45:50 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_pin(t_game *game, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pin");
	while (game->client[i] && game-client[i].num_team != ft_atoi(tab[1]))
		i++;
	if (game->client[i])
	{
		game->client[i].x = ft_atoi(tab[2]);
		game->client[i].y = ft_atoi(tab[3]);
		game->client[i].resource.food = ft_atoi(tab[4]);
		game->client[i].resource.linemate = ft_atoi(tab[5]);
		game->client[i].resource.deraumere = ft_atoi(tab[6]);
		game->client[i].resource.sibur = ft_atoi(tab[7]);
		game->client[i].resource.mendiane = ft_atoi(tab[8]);
		game->client[i].resource.phiras = ft_atoi(tab[9]);
		game->client[i].resource.thystame = ft_atoi(tab[10]);
	}
}
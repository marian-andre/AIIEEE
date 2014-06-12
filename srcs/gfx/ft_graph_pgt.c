/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pgt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:13 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/12 18:43:44 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_pgt(t_game *game, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pgt");
	while (game->client[i] && game-client[i].num_team != ft_atoi(tab[1]))
		i++;
	if (game->client[i])
	{
		if (ft_atoi(tab[2]) == 0)
			game->client[i].resource.food++;
		else if (ft_atoi(tab[2]) == 1)
			game->client[i].resource.linemate++;
		else if (ft_atoi(tab[2]) == 2)
			game->client[i].resource.deraumere++;
		else if (ft_atoi(tab[2]) == 3)
			game->client[i].resource.sibur++;
		else if (ft_atoi(tab[2]) == 4)
			game->client[i].resource.mendiane++;
		else if (ft_atoi(tab[2]) == 5)
			game->client[i].resource.phiras++;
		else if (ft_atoi(tab[2]) == 6)
			game->client[i].resource.thystame++;
	}
}

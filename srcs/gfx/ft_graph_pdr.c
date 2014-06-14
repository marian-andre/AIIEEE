/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pdr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:05 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/14 15:01:29 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_pdr(t_game *game, char *line)
{
	int		i;
	char	**tab;

	i = ft_atoi(tab[1]);
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pdr");
	if (game->client[i].lvl > 0)
	{
		if (ft_atoi(tab[2]) == 1 && game->client[i].resource.linemate > 0)
			game->client[i].resource.linemate--;
		else if (ft_atoi(tab[2]) == 2 && game->client[i].resource.deraumere > 0)
			game->client[i].resource.deraumere--;
		else if (ft_atoi(tab[2]) == 3 && game->client[i].resource.sibur > 0)
			game->client[i].resource.sibur--;
		else if (ft_atoi(tab[2]) == 4 && game->client[i].resource.mendiane > 0)
			game->client[i].resource.mendiane--;
		else if (ft_atoi(tab[2]) == 5 && game->client[i].resource.phiras > 0)
			game->client[i].resource.phiras--;
		else if (ft_atoi(tab[2]) == 6 && game->client[i].resource.thystame > 0)
			game->client[i].resource.thystame--;
	}
	ft_strdel2(&tab);
}

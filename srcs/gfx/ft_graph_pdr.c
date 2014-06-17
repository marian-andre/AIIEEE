/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pdr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:05 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/17 15:26:27 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

static void		ft_core_pdr(t_game *game, int i, char **tab)
{
	if (ft_atoi(tab[2]) == 3 && game->client[i].resource.sibur > 0)
	{
		game->map[game->client[i].y][game->client[i].x].sibur++;
		game->client[i].resource.sibur--;
	}
	if (ft_atoi(tab[2]) == 4 && game->client[i].resource.mendiane > 0)
	{
		game->map[game->client[i].y][game->client[i].x].mendiane++;
		game->client[i].resource.mendiane--;
	}
	if (ft_atoi(tab[2]) == 5 && game->client[i].resource.phiras > 0)
	{
		game->map[game->client[i].y][game->client[i].x].phiras++;
		game->client[i].resource.phiras--;
	}
	if (ft_atoi(tab[2]) == 6 && game->client[i].resource.thystame > 0)
	{
		game->map[game->client[i].y][game->client[i].x].thystame++;
		game->client[i].resource.thystame--;
	}
}

void			ft_graph_pdr(t_game *game, char *line)
{
	int			i;
	char		**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pdr");
	i = ft_atoi(tab[1]);
	if (game->client[i].lvl > 0)
	{
		if (ft_atoi(tab[2]) == 1 && game->client[i].resource.linemate > 0)
		{
			game->map[game->client[i].y][game->client[i].x].linemate++;
			game->client[i].resource.linemate--;
		}
		if (ft_atoi(tab[2]) == 2 && game->client[i].resource.deraumere > 0)
		{
			game->map[game->client[i].y][game->client[i].x].deraumere++;
			game->client[i].resource.deraumere--;
		}
		ft_core_pdr(game, i, tab);
	}
	ft_strdel2(&tab);
}

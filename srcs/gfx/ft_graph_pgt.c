/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pgt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:13 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/17 15:25:08 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

static void		ft_core2_pgt(t_game *game, int i, char **tab)
{
	if (ft_atoi(tab[2]) == 3)
	{
		if (game->map[game->client[i].y][game->client[i].x].sibur > 0)
		{
			game->map[game->client[i].y][game->client[i].x].sibur--;
			game->client[i].resource.food++;
		}
	}
	if (ft_atoi(tab[2]) == 4)
	{
		if (game->map[game->client[i].y][game->client[i].x].mendiane > 0)
		{
			game->map[game->client[i].y][game->client[i].x].mendiane--;
			game->client[i].resource.mendiane++;
		}
	}
	if (ft_atoi(tab[2]) == 5)
	{
		if (game->map[game->client[i].y][game->client[i].x].phiras > 0)
		{
			game->map[game->client[i].y][game->client[i].x].phiras--;
			game->client[i].resource.phiras++;
		}
	}
}

static void		ft_core_pgt(t_game *game, int i, char **tab)
{
	if (ft_atoi(tab[2]) == 0)
	{
		if (game->map[game->client[i].y][game->client[i].x].food > 0)
		{
			game->map[game->client[i].y][game->client[i].x].food--;
			game->client[i].resource.food++;
		}
	}
	if (ft_atoi(tab[2]) == 1)
	{
		if (game->map[game->client[i].y][game->client[i].x].linemate > 0)
		{
			game->map[game->client[i].y][game->client[i].x].linemate--;
			game->client[i].resource.linemate++;
		}
	}
	if (ft_atoi(tab[2]) == 2)
	{
		if (game->map[game->client[i].y][game->client[i].x].deraumere > 0)
		{
			game->map[game->client[i].y][game->client[i].x].deraumere--;
			game->client[i].resource.food++;
		}
	}
}

void			ft_graph_pgt(t_game *game, char *line)
{
	int			i;
	char		**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pgt");
	i = ft_atoi(tab[1]);
	ft_core_pgt(game, i, tab);
	ft_core2_pgt(game, i, tab);
	if (ft_atoi(tab[2]) == 6)
	{
		if (game->map[game->client[i].y][game->client[i].x].thystame > 0)
		{
			game->map[game->client[i].y][game->client[i].x].thystame--;
			game->client[i].resource.food++;
		}
	}
	ft_strdel2(&tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pgt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:13 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/14 15:49:14 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

static void		ft_core2_pgt(t_game *game, int i, char **tab)
{
	if (ft_atoi(tab[2]) == 3)
	{
		if (game->map[game->client[i].x][game->client[i].y].sibur > 0)
		{
			game->map[game->client[i].x][game->client[i].y].sibur--;
			game->client[i].resource.food++;
		}
	}
	if (ft_atoi(tab[2]) == 4)
	{
		if (game->map[game->client[i].x][game->client[i].y].mendiane > 0)
		{
			game->map[game->client[i].x][game->client[i].y].mendiane--;
			game->client[i].resource.mendiane++;
		}
	}
	if (ft_atoi(tab[2]) == 5)
	{
		if (game->map[game->client[i].x][game->client[i].y].phiras > 0)
		{
			game->map[game->client[i].x][game->client[i].y].phiras--;
			game->client[i].resource.phiras++;
		}
	}
}

static void		ft_core_pgt(t_game *game, int i, char **tab)
{
	if (ft_atoi(tab[2]) == 0)
	{
		if (game->map[game->client[i].x][game->client[i].y].food > 0)
		{
			game->map[game->client[i].x][game->client[i].y].food--;
			game->client[i].resource.food++;
		}
	}
	if (ft_atoi(tab[2]) == 1)
	{
		if (game->map[game->client[i].x][game->client[i].y].linemate > 0)
		{
			game->map[game->client[i].x][game->client[i].y].linemate--;
			game->client[i].resource.linemate++;
		}
	}
	if (ft_atoi(tab[2]) == 2)
	{
		if (game->map[game->client[i].x][game->client[i].y].deraumere > 0)
		{
			game->map[game->client[i].x][game->client[i].y].deraumere--;
			game->client[i].resource.food++;
		}
	}
}

void			ft_graph_pgt(t_game *game, char *line)
{
	int			i;
	char		**tab;

	i = ft_atoi(tab[1]);
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pgt");
	if (game->client[i].lvl > 0)
	{
		ft_core_pgt(game, i, tab);
		ft_core2_pgt(game, i, tab);
		if (ft_atoi(tab[2]) == 6)
		{
			if (game->map[game->client[i].x][game->client[i].y].thystame > 0)
			{
				game->map[game->client[i].x][game->client[i].y].thystame--;
				game->client[i].resource.food++;
			}
		}
	}
	ft_strdel2(&tab);
}

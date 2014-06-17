/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pnw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:59:50 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/17 15:25:52 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

static int		ft_nb_team(t_game *game, char *team)
{
	int		i;

	i = 0;
	while (ft_strcmp(team, game->team[i]) != 0)
		i++;
	return (i);
}

static void		ft_add_player(t_game *game, char **tab)
{
	int		i;

	i = ft_atoi(tab[1]);
	game->client[i].x = ft_atoi(tab[2]);
	game->client[i].y = ft_atoi(tab[3]);
	game->client[i].num_team = ft_nb_team(game, tab[1]);
	game->client[i].lvl = ft_atoi(tab[5]);
	game->client[i].dir = ft_atoi(tab[4]);
}

void			init_client(t_game *game)
{
	int		i;

	i = -1;
	while (++i < MAX_CLI)
	{
		game->client[i].x = 0;
		game->client[i].y = 0;
		game->client[i].num_team = -1;
		game->client[i].lvl = 0;
		game->client[i].dir = 0;
		game->client[i].invok = 0;
		game->client[i].resource.food = 0;
		game->client[i].resource.linemate = 0;
		game->client[i].resource.deraumere = 0;
		game->client[i].lvl = 0;
		game->client[i].resource.sibur = 0;
		game->client[i].resource.mendiane = 0;
		game->client[i].resource.phiras = 0;
		game->client[i].resource.thystame = 0;
	}
}

void			ft_graph_pnw(t_game *game, char *line)
{
	char		**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pnw");
	ft_add_player(game, tab);
	ft_strdel2(&tab);
}

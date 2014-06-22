/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_enw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:30 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/22 14:14:14 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "libft.h"

static void			ft_add_egg(t_game *game, char **tab)
{
	game->egg[ft_atoi(tab[1])].client = ft_atoi(tab[2]);
	game->egg[ft_atoi(tab[1])].x = ft_atoi(tab[3]);
	game->egg[ft_atoi(tab[1])].y = ft_atoi(tab[4]);
}

void				init_egg(t_game *game)
{
	int				i;

	i = -1;
	while (++i < MAX_CLI)
	{
		game->egg[i].active = 0;
		game->egg[i].x = -1;
		game->egg[i].y = -1;
		game->egg[i].client = -1;
	}
}

void				ft_graph_enw(t_game *game, char *line)
{
	char			**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> tab in ft_graph_enw");
	ft_add_egg(game, tab);
	ft_strdel2(&tab);
}

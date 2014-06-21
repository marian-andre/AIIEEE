/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_enw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:30 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/21 18:15:35 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "libft.h"

static void			ft_add_egg(t_game *game, char **tab)
{
ft_putendl("pipi");
	game->egg[ft_atoi(tab[1])].client = ft_atoi(tab[2]);
ft_putendl("pipi");
	game->egg[ft_atoi(tab[1])].x = ft_atoi(tab[3]);
ft_putendl("pipi");
	game->egg[ft_atoi(tab[1])].y = ft_atoi(tab[4]);
ft_putendl("pipi");
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
ft_putendl("----------------");
	ft_putendl(line);
ft_putendl("----------------");
	ft_add_egg(game, tab);
ft_putendl("papa");
	ft_strdel2(&tab);
}


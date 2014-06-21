/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_tna.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:59:14 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/21 16:19:24 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

int				nb_line(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char			**ft_realloc(t_game *game, char **tab, char *team)
{
	int			i;
	int			length;
	char		**new;

	i = -1;
	length = nb_line(game->team);
	if ((new = (char**)malloc(sizeof(char*) * (length + 2))) == NULL)
		ft_graphic_error("malloc failed -> new in ft_realloc");
	while (tab[++i])
		new[i] = ft_strdup(tab[i]);
	new[i++] = ft_strdup(team);
	new[i] = NULL;
	return (new);
}

void			ft_graph_tna(t_game *game, char *line)
{
	static int	first = 1;
	char		**tab;

	if (first == 1)
	{
		game->team = (char**)malloc(sizeof(char*));
		game->team[0] = NULL;
		first = 0;
	}
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> tab in ft_graph_tna");
	game->team = ft_realloc(game, game->team, tab[1]);
	ft_strdel2(&tab);
}

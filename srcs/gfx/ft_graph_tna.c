/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_tna.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:59:14 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/12 20:00:54 by rkorimba         ###   ########.fr       */
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

char			**ft_realloc(char **tab, char *team)
{
	int			i;
	int			length;
	char		**new;

	i = -1;
	length = nb_line(game->team);
	if (new = (char**)malloc(sizeof(char*) * length + 2))
		ft_graphic_error("malloc failed -> new in ft_realloc");
	while (tab[++i])
		new[i] = ft_strdup(tab[i]);
	new[i++] = ft_strdup(team);
	new[i] = '\0';
}

int				ft_check_in_team(char **team, char *name)
{
	int			i;

	i = -1;
	while (team[++i])
	{
		if (ft_strcmp(team[i], name) == 0)
			return (1);
	}
	return (0);
}

void			ft_graph_tna(t_game *game, char *line)
{
	static int	first = 1;
	int			i;
	char		**tab;

	if (first == 1)
	{
		game->team = (char**)malloc(sizeof(char*));
		i = -1;
		game->team[0] = ft_memalloc(1);
		first = 0;
	}
	if (tab = ft_strsplit(line, ' ') == NULL)
		ft_graphic_error("parse error -> tab in ft_graph tna");
	if (!ft_check_in_team(game->team, tab[1]))
		game->team = ft_realloc(game->team, tab[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:01:24 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/14 17:20:03 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_pic(t_game *game, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_pic");
	while (i < MAX_CLI)
	{
		if (game->client[i].x == ft_atoi(tab[1])
			&& game->client[i].y == ft_atoi(tab[2]))
			break ;
		i++;
	}
	game->client[i].invok = ft_atoi(tab[3]);
	ft_putendl("pic end");
	ft_strdel2(&tab);
}

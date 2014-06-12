/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_pic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:01:24 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/12 20:05:14 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_ppo(t_game *game, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_ppo");
	while (game->client[i])
	{
		if (game-client[i].x == ft_atoi(tab[1])
			&& game->client[i].y == ft_atoi(tab[2]))
			break;
		i++;
	if (game->client[i])
		game->client[i].invok = ft_atoi(tab[3]);
}

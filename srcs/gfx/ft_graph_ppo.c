/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_ppo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:59:59 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/14 15:04:31 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"

void		ft_graph_ppo(t_game *game, char *line)
{
	int		i;
	char	**tab;

	i = ft_atoi(tab[1]);
	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("malloc failed -> tab in ft_graph_ppo");
	if (game->client[i].lvl > 0)
	{
		game->client[i].x = ft_atoi(tab[2]);
		game->client[i].y = ft_atoi(tab[3]);
		game->client[i].dir = ft_atoi(tab[4]);
	}
	ft_strdel2(&tab);
	ft_putstr("ppo ");
	ft_putnbr(ft_atoi(tab[1]));
	ft_putchar('\n');
}

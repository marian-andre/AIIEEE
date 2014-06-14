/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:13:05 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/14 13:18:25 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphic.h"
#include "libft.h"

void		init_map(t_game *game, char *line)
{
	int		i;
	char	**array;

	i = -1;
	if ((array = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> array in init_map");
	game->width = ft_atoi(array[1]);
	game->height = ft_atoi(array[2]);
	game->map = (t_map**)malloc(sizeof(t_map*) * ft_atoi(array[2]));
	while (++i < ft_atoi(array[2]))
		game->map[i] = (t_map*)malloc(sizeof(t_map) * ft_atoi(array[1]));
	ft_strdel2(&array);
}

void		init_time(t_game *game, char *line)
{
	char	**array;

	if ((array = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> array in init_time");
	game->time = ft_atoi(array[1]);
	ft_strdel2(&array);
}

void		init_case(t_game *game, char *line)
{
	char	**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> array in init_case");
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].food = ft_atoi(tab[3]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].linemate = ft_atoi(tab[4]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].deraumere = ft_atoi(tab[5]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].sibur = ft_atoi(tab[6]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].mendiane = ft_atoi(tab[7]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].phiras = ft_atoi(tab[8]);
	game->map[ft_atoi(tab[2])][ft_atoi(tab[1])].thystame = ft_atoi(tab[9]);
	ft_strdel2(&tab);
}

void		display(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			ft_putnbr(game->map[i][j].food);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].linemate);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].deraumere);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].sibur);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].mendiane);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].phiras);
			ft_putchar(' ');
			ft_putnbr(game->map[i][j].thystame);
			ft_putchar(' ');
			ft_putchar('\n');
		}
		ft_putchar('\n');
	}
}

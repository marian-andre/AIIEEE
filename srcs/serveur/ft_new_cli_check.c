/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_cli_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:19:09 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/15 20:15:28 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

int			ft_check_team(t_game *g, char *line)
{
	int		i;

	i = 0;
	while (g->team[i])
	{
		if (ft_strcmp(g->team[i], line) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_check_rand(t_game *g, int num_cli)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = rand() % g->width;
	y = rand() % g->height;
	while (i < MAX_CLI)
	{
		if (g->cls[i].x == x && g->cls[i].y == y)
		{
			x = rand() % g->width;
			y = rand() % g->height;
		}
		else
			i++;
	}
	g->cls[num_cli].x = x;
	g->cls[num_cli].y = y;
	g->map[y][x].nb_player++;
}

int			ft_check_eggs(t_game *g, char *line)
{
	int			i;

	i = 0;
	while (i < MAX_CLI)
	{
		if (g->eggs[i].cl.num_team == ft_check_team(g, line)
			&& g->eggs[i].active == 1)
			return (i);
		i++;
	}
	return (-1);
}

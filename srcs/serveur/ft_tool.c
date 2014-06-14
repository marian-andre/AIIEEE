/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:13:29 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/14 16:33:23 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "serveur.h"

long		timevaldiff(t_time starttime, t_time finishtime)
{
	long	usec;

	usec = (finishtime.tv_sec - starttime.tv_sec) * 1000000;
	usec += (finishtime.tv_usec - starttime.tv_usec);
	return (usec);
}

t_game		*singleton(t_game *game)
{
	static t_game	*g;

	if (game)
		g = game;

	return (g);
}

void		ft_quit(void)
{
	t_game		*game;
	int			i;

	game = singleton(NULL);
	i = -1;
	while (++i < 13)
		free(game->tab[i].line);
	i = -1;
	while (i < game->height)
		free(game->map[i]);
	free(game->map);
	i = -1;
	while (game->team[++i])
		free(game->team[i]);
	free(game->team);
	close(game->sock);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:13:29 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/19 18:24:05 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

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
	ft_putendl("free game.tab ok");
	ft_putnbr(game->height);
	ft_putchar('\n');
	i = -1;
	while (++i < game->height)
		free(game->map[i]);
	ft_putendl("free game.map[i] ok");
	free(game->map);
	ft_putendl("free game.map ok");
	i = -1;
	while (game->team[++i])
		free(game->team[i]);
	ft_putendl("free game.team[i] ok");
	free(game->team);
	ft_putendl("free game.team ok");
	close(game->sock);
}

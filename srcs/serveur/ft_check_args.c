/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 15:17:49 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/06 10:16:16 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static void		ft_check_team_name(char **argv, int j)
{
	int			i;

	while (argv[j] && argv[j][0] != '-')
	{
		i = j + 1;
		while (argv[i] && argv[j][0] != '-')
		{
			if (ft_strcmp(argv[j], argv[i]) == 0)
				ft_error("ERROR bad argument.");
			i++;
		}
		j++;
	}
}

static int		ft_fill_team(char **argv, t_game *game, int j)
{
	int			i;
	int			count;

	i = j;
	count = 0;
	ft_check_team_name(argv, j);
	while (argv[i] && argv[i][0] != '-')
	{
		i++;
		count++;
	}
	if ((game->team = (char**)malloc(sizeof(char*) * (count + 1))) == NULL)
		ft_error("ERROR malloc create team.");
	i = 0;
	while (argv[j] && argv[j][0] != '-')
	{
		if (ft_strcmp(argv[j], "GRAPHIC") == 0)
			ft_error("ERROR you can't use 'GRAPHIC' as a team name.");
		game->team[i] = ft_strdup(argv[j]);
		i++;
		j++;
	}
	game->team[i] = '\0';
	return (j - 2);
}

static int		ft_fill_game(char **argv, int i, t_game *game)
{
	if (ft_strcmp(argv[i], "-p") == 0 && ft_isdigit_str(argv[i + 1]) == 1)
		game->port = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-x") == 0 && ft_isdigit_str(argv[i + 1]) == 1)
		game->width = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-y") == 0 && ft_isdigit_str(argv[i + 1]) == 1)
		game->height = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-c") == 0 && ft_isdigit_str(argv[i + 1]) == 1)
		game->max_cli = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-t") == 0 && ft_isdigit_str(argv[i + 1]) == 1)
		game->time = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-n") == 0 && argv[i + 1])
		i = ft_fill_team(argv, game, i + 1);
	else
		ft_error("ERROR bad argument.");
	i++;
	return (i);
}

t_game			ft_check_args(char **argv, t_game game)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	if (argv[1][0] != '-')
		ft_error("ERROR bad argument.");
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i + 1])
		{
			if (ft_strcmp(argv[i], "-n") == 0 && argv[i + 1]
				&& argv[i + 1][0] != '-')
				count++;
			i = ft_fill_game(argv, i, &game);
		}
		i++;
	}
	if (count != 1)
		ft_error("ERROR bad arguments.");
	return (game);
}

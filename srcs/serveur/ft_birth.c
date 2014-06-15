/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_birth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:59:24 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/15 20:04:16 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

void		ft_birth(t_cmd *cmd, t_game *g)
{
//	int		i;

//	i = 0;
	ft_putendl_fd("birth ok", cmd->fd);
	g->max_cli[g->cls[cmd->num_cli].num_team]++;
/*	while (g->cls[i].cs)
		i++;
	g->cls[i].cs = 100;
	g->cls[i].lvl = 1;
	g->cls[i].graph = 0;
	g->cls[i].num_team = g->cls[cmd->num_cli].num_team;
	g->cls[i].resource.linemate = 0;
	g->cls[i].resource.deraumere = 0;
	g->cls[i].resource.sibur = 0;
	g->cls[i].resource.mendiane = 0;
	g->cls[i].resource.phiras = 0;
	g->cls[i].resource.thystame = 0;
	g->cls[i].resource.food = 10;
	g->cls[i].dir = (rand() % 4) + 1;
*/}

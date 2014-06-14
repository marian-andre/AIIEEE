/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:01:35 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/14 15:17:26 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static void		ft_check_cmd_2(t_cmd *cmd, t_game *g)
{
	if (ft_strcmp(cmd->cmd, "expulse") == 0)
		ft_expel(cmd, g);
	else if (ft_strncmp(cmd->cmd, "broadcast", 9) == 0)
		ft_broadcast(cmd, g);
	else if (ft_strcmp(cmd->cmd, "incantation") == 0)
		ft_spell(cmd, g);
	else if (ft_strcmp(cmd->cmd, "fork") == 0)
		ft_fork(cmd, g);
	else if (ft_strcmp(cmd->cmd, "life") == 0)
		ft_life(cmd, g);
	else if (ft_strcmp(cmd->cmd, "birth") == 0)
		ft_birth(cmd, g);
}

static void		ft_check_cmd(t_cmd *cmd, t_game *g)
{
	if (ft_strcmp(cmd->cmd, "avance") == 0)
		ft_move(cmd, g);
	else if (ft_strcmp(cmd->cmd, "droite") == 0)
		ft_right(cmd, g);
	else if (ft_strcmp(cmd->cmd, "gauche") == 0)
		ft_left(cmd, g);
	else if (ft_strcmp(cmd->cmd, "voir") == 0)
		ft_see(cmd, g);
	else if (ft_strcmp(cmd->cmd, "inventaire") == 0)
		ft_stock(cmd, g);
	else if (ft_strncmp(cmd->cmd, "prend", 5) == 0)
		ft_take(cmd, g);
	else if (ft_strncmp(cmd->cmd, "pose", 4) == 0)
		ft_put(cmd, g);
	else
		ft_check_cmd_2(cmd, g);
}

void			ft_exec_request(t_game *g)
{
	t_cmd		*tmp;
	t_time		now;

	tmp = g->list;
	while (tmp)
	{
		gettimeofday(&now, NULL);
		if (timevaldiff(now, tmp->time) <= 0)
		{
			ft_check_cmd(tmp, g);
			ft_del_node(g, tmp);
		}
		tmp = tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/10 18:39:41 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "serveur.h"
#include "libft.h"

void		ft_expel(t_cmd *cmd, t_game *g)
{
	int		i;
	int		x;
	int		y;
	t_cmd	avance;

	avance.fd = open("/dev/null", O_WRONLY);
	x = g->cls[cmd->num_cli].x;
	y = g->cls[cmd->num_cli].y;
	if (g->map[x][y].nb_player == 1)
		ft_putendl_fd("ko", cmd->fd);
	else
	{
		i = -1;
		while (++i < MAX_CLI && g->cls[i]->fd)
		{
			if (i != cmd->num_cli && g->cls[i].x == x && g->cls[i].y == y)
			{
				avance.num_cli = i;
				ft_move(&avance, g);
			}
		}
		ft_putendl_fd("ok", cmd->fd);
	}
	ft_graph_pex(g, cmd->num_cli);
}

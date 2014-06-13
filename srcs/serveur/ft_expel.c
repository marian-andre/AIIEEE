/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/13 16:32:30 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "serveur.h"
#include "libft.h"

void		ft_expel(t_cmd *cmd, t_game *g)
{
	t_var	var;
	t_cmd	avance;

	if (g->cls[cmd->num_cli].cs == 50)
		return ;
	avance.fd = open("/dev/null", O_WRONLY);
	var.x = g->cls[cmd->num_cli].x;
	var.y = g->cls[cmd->num_cli].y;
	var.i = -1;
	while (++var.i < MAX_CLI && g->cls[var.i].cs)
	{
		if (var.i != cmd->num_cli && g->cls[var.i].x == var.x
				&& g->cls[var.i].y == var.y)
		{
			avance.num_cli = var.i;
			ft_move(&avance, g);
		}
	}
	ft_putendl_fd("ok", cmd->fd);
	ft_graph_pex(g, cmd->num_cli);
	close(avance.fd);
}

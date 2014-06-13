/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broadcast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/13 19:35:02 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "serveur.h"
#include "libft.h"

static int		ft_get_k(t_game *g, int num_cli, int i)
{
	(void)g;
	(void)num_cli;
	(void)i;
	return (0);
}

void			ft_broadcast(t_cmd *cmd, t_game *g)
{
	int		k;
	int		i;

	if (g->cls[cmd->num_cli].cs == MORT)
		return ;
	i = 0;
	while (i < MAX_CLI && g->cls[i].cs)
	{
		if (g->cls[i].cs != MORT)
		{
			k = ft_get_k(g, cmd->num_cli, i);
			ft_putstr_fd("message ", g->cls[i].cs);
			ft_putnbr_fd(k, g->cls[i].cs);
			ft_putstr_fd(",", g->cls[i].cs);
			ft_putendl_fd(&cmd->cmd[10], g->cls[i].cs);
			free(del);
		}
		i++;
	}
	ft_graph_pbc(g, cmd->num_cli, &cmd->cmd[10]);
}

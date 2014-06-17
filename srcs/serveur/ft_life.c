/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:12:45 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/17 14:07:47 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "serveur.h"
#include "libft.h"

static void	ft_death(t_cmd *cmd, t_game *g)
{
	g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].nb_player--;
	ft_putstr("Client ");
	ft_putnbr(cmd->num_cli);
	ft_putendl(" died.");
	ft_putendl_fd("mort", cmd->fd);
	close(g->cls[cmd->num_cli].cs);
	g->cls[cmd->num_cli].cs = MORT;
}

void		ft_life(t_cmd *cmd, t_game *g)
{
	t_cmd	*tmp;

	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		ft_putstr("nourriture = ");
		ft_putnbr(g->cls[cmd->num_cli].resource.nourriture);
		ft_putstr(", t = ");
		ft_putnbr(g->tab[11].t);
		ft_putstr(", client num ");
		ft_putnbr(cmd->num_cli);
		ft_putchar('\n');
		g->cls[cmd->num_cli].resource.nourriture--;
		if (g->cls[cmd->num_cli].resource.nourriture <= 0)
			ft_death(cmd, g);
		else
		{
			tmp = ft_create_node(g, "life", cmd->num_cli);
			ft_add_node(g, tmp);
		}
	}
}

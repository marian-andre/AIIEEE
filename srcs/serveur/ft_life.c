/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:12:45 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 20:18:03 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "serveur.h"
#include "libft.h"

static void	ft_death(t_cmd *cmd, t_game *g, t_fd *fd)
{
	g->map[g->cls[cmd->num_cli].y][g->cls[cmd->num_cli].x].nb_player--;
	ft_putstr("Client ");
	ft_putnbr(cmd->num_cli);
	ft_putendl(" died.");
	ft_putendl_fd("mort", cmd->fd);
	close(g->cls[cmd->num_cli].cs);
//	ft_memmove(g->cls + cmd->num_cli, g->cls + cmd->num_cli + 1,
//				(fd->nb_cli - cmd->num_cli - 1) * sizeof(t_client));
	g->cls[cmd->num_cli].cs = -1;
	g->cls[cmd->num_cli].num_team = -1;
	fd->nb_cli--;
}

void		ft_life(t_cmd *cmd, t_game *g, t_fd *fd)
{
	t_cmd	*tmp;

	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		ft_putstr("food = ");
		ft_putnbr(g->cls[cmd->num_cli].resource.food);
		ft_putstr(", t = ");
		ft_putnbr(g->tab[11].t);
		ft_putchar('\n');
		g->cls[cmd->num_cli].resource.food--;
		if (g->cls[cmd->num_cli].resource.food == 0)
			ft_death(cmd, g, fd);
		else
		{
			tmp = ft_create_node(g, "life", cmd->num_cli);
			ft_add_node(g, tmp);
		}
	}
}

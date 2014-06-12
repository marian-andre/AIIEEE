/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 11:25:20 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static int	ft_check_co_wizards(t_cmd *cmd, t_game *g)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (g->cls[i].cs > 0)
	{
		if (g->cls[i].x == g->cls[cmd->num_cli].x
			&& g->cls[i].y == g->cls[cmd->num_cli].y
			&& g->cls[i].lvl == g->cls[cmd->num_cli].lvl)
			nb++;
		i++;
	}
	return (nb);
}

void		ft_spell(t_cmd *cmd, t_game *g)
{
	int		nb;

	nb = ft_check_co_wizards(cmd, g);
	if (g->cls[cmd->num_cli].lvl == 1)
		ft_putendl_fd("ok", cmd->fd);
	if (g->cls[cmd->num_cli].lvl == 2 && nb >= 2)
		ft_putendl_fd("ok", cmd->fd);
	if (g->cls[cmd->num_cli].lvl == 3 && nb >= 2)
		ft_putendl_fd("ok", cmd->fd);
	if (g->cls[cmd->num_cli].lvl == 4 && nb >= 4)
		ft_putendl_fd("ok", cmd->fd);
	if (g->cls[cmd->num_cli].lvl == 5 && nb >= 4)
		ft_putendl_fd("ok", cmd->fd);
	if (g->cls[cmd->num_cli].lvl == 6 && nb >= 6)
		ft_putendl_fd("ok", cmd->fd);
	if (g->cls[cmd->num_cli].lvl == 7 && nb >= 6)
		ft_putendl_fd("ok", cmd->fd);
	else
	{
		ft_putendl_fd("ko", cmd->fd);
		nb = -1;
	}
	if (nb != -1)
		ft_dispatch_stone(g, cmd->num_cli);
}

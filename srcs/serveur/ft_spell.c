/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/23 17:10:25 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static void	ft_print_lvl(t_game *g, t_cmd *cmd)
{
	ft_putstr_fd("niveau actuel : ", cmd->fd);
	ft_putnbr_fd(g->cls[cmd->num_cli].lvl, cmd->fd);
	ft_putchar_fd('\n', cmd->fd);
}

static int	ft_co_wizards(t_cmd *cmd, t_game *g, int lvl_up)
{
	int		nb;
	int		i;
	int		lvl;

	nb = 0;
	i = -1;
	lvl = g->cls[cmd->num_cli].lvl;
	if (lvl_up > 0)
		lvl = lvl_up;
	while (++i < MAX_CLI && g->cls[i].cs > 0)
	{
		if (g->cls[i].x == g->cls[cmd->num_cli].x
			&& g->cls[i].y == g->cls[cmd->num_cli].y
			&& g->cls[i].lvl == lvl
			&& g->cls[i].cs != MORT)
			nb++;
	}
	if (lvl_up > 0)
	{
		g->cls[cmd->num_cli].lvl++;
		ft_print_lvl(g, cmd);
	}
	return (nb);
}

static void	ft_end_of_spell(t_game *g, t_cmd *cmd)
{
	ft_co_wizards(cmd, g, g->cls[cmd->num_cli].lvl);
	ft_graph_pie(g, cmd->num_cli, g->cls[cmd->num_cli].lvl);
	ft_graph_plv(g, cmd->num_cli);
	ft_dispatch_stone(g, cmd->num_cli);
}

void		ft_spell(t_cmd *cmd, t_game *g)
{
	int		nb;

	if (g->cls[cmd->num_cli].cs == MORT)
		return ;
	nb = ft_co_wizards(cmd, g, 0);
	ft_graph_pic(g, cmd->num_cli);
	if (g->cls[cmd->num_cli].lvl == 1)
		ft_end_of_spell(g, cmd);
	else if (g->cls[cmd->num_cli].lvl == 2 && nb >= 2)
		ft_end_of_spell(g, cmd);
	else if (g->cls[cmd->num_cli].lvl == 3 && nb >= 2)
		ft_end_of_spell(g, cmd);
	else if (g->cls[cmd->num_cli].lvl == 4 && nb >= 4)
		ft_end_of_spell(g, cmd);
	else if (g->cls[cmd->num_cli].lvl == 5 && nb >= 4)
		ft_end_of_spell(g, cmd);
	else if (g->cls[cmd->num_cli].lvl == 6 && nb >= 6)
		ft_end_of_spell(g, cmd);
	else if (g->cls[cmd->num_cli].lvl == 7 && nb >= 6)
		ft_end_of_spell(g, cmd);
	else
		ft_print_lvl(g, cmd);
}

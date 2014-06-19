/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_stone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:37:50 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/19 18:07:07 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

static int		ft_check_ret(t_game *game, int *q, int *ret, int i)
{
	int		tmp;

	tmp = ft_rand_stone(q, i, *game);
	*ret += tmp;
	return (tmp); 
}

static void		ft_dispatch(t_game *g, int *q, int ret, int y)
{
	int		x;

	while (++y < g->height)
	{
		x = -1;
		ret = 0;
		while (++x < g->width)
		{
			if (q[0] > 0)
				g->map[y][x].linemate += ft_check_ret(g, q, &ret, 0);
			if (q[1] > 0)
				g->map[y][x].deraumere += ft_check_ret(g, q, &ret, 1);
			if (q[2] > 0)
				g->map[y][x].sibur += ft_check_ret(g, q, &ret, 2);
			if (q[3] > 0)
				g->map[y][x].phiras += ft_check_ret(g, q, &ret, 3);
			if (q[4] > 0)
				g->map[y][x].mendiane += ft_check_ret(g, q, &ret, 4);
			if (q[5] > 0)
				g->map[y][x].thystame += ft_check_ret(g, q, &ret, 5);
			if (ret > 0)
				ft_graph_bct(g, 0, x, y);
		}
	}
}

void			ft_dispatch_stone(t_game *g, int cli)
{
	static int		q[6] = {0};
	int				ret;

	ret = 0;
	if (g->cls[cli].lvl == 1 || g->cls[cli].lvl == 2) 
		ft_disp_lvl_1_to_2(q, g, g->cls[cli].lvl, cli);
	if (g->cls[cli].lvl == 4 || g->cls[cli].lvl == 3)
		ft_disp_lvl_3_to_4(q, g, g->cls[cli].lvl, cli);
	if (g->cls[cli].lvl == 6 || g->cls[cli].lvl == 5)
		ft_disp_lvl_5_to_6(q, g, cli, g->cls[cli].lvl);
	if (g->cls[cli].lvl == 7)
		ft_disp_lvl_7(q, g, cli);
	ft_dispatch(g, q, ret, -1);
}

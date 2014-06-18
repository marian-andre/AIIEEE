/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:08:40 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/18 21:14:04 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "graphic.h"
#include "string.h"

static void		ft_core_msg(t_game *game, char *line)
{
	if (ft_strncmp("tna", line, 3) == 0)
		ft_graph_tna(game, line);
	else if (ft_strncmp("pnw", line, 3) == 0)
		ft_graph_pnw(game, line);
	else if (ft_strncmp("ppo", line, 3) == 0)
		ft_graph_ppo(game, line);
	else if (ft_strncmp("plv", line, 3) == 0)
		ft_graph_plv(game, line);
	else if (ft_strncmp("pin", line, 3) == 0)
		ft_graph_pin(game, line);
	else if (ft_strncmp("pex", line, 3) == 0)
		ft_graph_pex(game, line);
	else if (ft_strncmp("pbc", line, 3) == 0)
		ft_graph_pbc(game, line);
	else if (ft_strncmp("pic", line, 3) == 0)
		ft_graph_pic(game, line);
	else if (ft_strncmp("pie", line, 3) == 0)
		ft_graph_pie(game, line);
	else if (ft_strncmp("pfk", line, 3) == 0)
		ft_graph_pfk(game, line);
	else if (ft_strncmp("pdr", line, 3) == 0)
		ft_graph_pdr(game, line);
	else if (ft_strncmp("pgt", line, 3) == 0)
		ft_graph_pgt(game, line);
}

void			ft_check_msg(t_game *game, char *line)
{
	ft_core_msg(game, line);
	if (ft_strncmp("pdi", line, 3) == 0)
		ft_graph_pdi(game, line);
	else if (ft_strncmp("enw", line, 3) == 0)
		ft_graph_enw(game, line);
	else if (ft_strncmp("eht", line, 3) == 0)
		ft_graph_eht(game, line);
	else if (ft_strncmp("ebo", line, 3) == 0)
		ft_graph_ebo(game, line);
	else if (ft_strncmp("edi", line, 3) == 0)
		ft_graph_edi(game, line);
	else if (ft_strncmp("sgt", line, 3) == 0)
		ft_graph_sgt(game, line);
	else if (ft_strncmp("seg", line, 3) == 0)
		ft_graph_seg(game, line);
	else if (ft_strncmp("smg", line, 3) == 0)
		ft_graph_smg(game, line);
	else if (ft_strncmp("suc", line, 3) == 0)
		ft_graph_suc(game, line);
	else if (ft_strncmp("sbp", line, 3) == 0)
		ft_graph_sbp(game, line);
	else if (ft_strncmp("bct", line, 3) == 0)
		ft_graph_bct(game, line);
}

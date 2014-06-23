/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_birth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:59:24 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/23 17:14:06 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

void		ft_birth(t_cmd *cmd, t_game *g)
{
	if (g->max_cli[g->cls[cmd->num_cli].num_team] <= 13)
	{
		ft_graph_eht(g, cmd->num_egg);
		g->max_cli[g->cls[cmd->num_cli].num_team]++;
	}
	else
		ft_graph_edi(g, cmd->num_egg);
}

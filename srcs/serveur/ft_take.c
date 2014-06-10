/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/10 16:59:36 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_take(t_cmd *cmd, t_game *g)
{
	char	**split;

	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		split = ft_strsplit(cmd->cmd, ' ');
		if (ft_strcmp("linemate", split[1]) == 0)
			return ;
		else if (ft_strcmp("deraumere", split[1]) == 0)
			return ;
		else if (ft_strcmp("sibur", split[1]) == 0)
			return ;
		else if (ft_strcmp("mendiane", split[1]) == 0)
			return ;
		else if (ft_strcmp("phiras", split[1]) == 0)
			return ;
		else if (ft_strcmp("thystame", split[1]) == 0)
			return ;
		else if (ft_strcmp("food", split[1]) == 0)
			return ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_birth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 15:59:24 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/15 20:16:33 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

void		ft_birth(t_cmd *cmd, t_game *g)
{
	ft_putendl_fd("birth ok", cmd->fd);
	g->max_cli[g->cls[cmd->num_cli].num_team]++;
}

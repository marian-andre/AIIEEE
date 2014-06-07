/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:38:39 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/05 17:17:26 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_left(int i, t_game *g, t_fd *fd, char *cmd)
{
	if (g->cls[i].cs && fd->max)
		ft_putendl_fd(cmd, g->cls[i].cs);
}

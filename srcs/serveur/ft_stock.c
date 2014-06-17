/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/17 14:10:04 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_stock(t_cmd *cmd, t_game *g)
{
	if (g->cls[cmd->num_cli].cs == cmd->fd)
	{
		ft_putstr_fd("{linemate ", cmd->fd);
		ft_putnbr_fd(g->cls[cmd->num_cli].resource.linemate, cmd->fd);
		ft_putstr_fd(", deraumere ", cmd->fd);
		ft_putnbr_fd(g->cls[cmd->num_cli].resource.deraumere, cmd->fd);
		ft_putstr_fd(", sibur ", cmd->fd);
		ft_putnbr_fd(g->cls[cmd->num_cli].resource.sibur, cmd->fd);
		ft_putstr_fd(", mendiane ", cmd->fd);
		ft_putnbr_fd(g->cls[cmd->num_cli].resource.mendiane, cmd->fd);
		ft_putstr_fd(", phiras ", cmd->fd);
		ft_putnbr_fd(g->cls[cmd->num_cli].resource.phiras, cmd->fd);
		ft_putstr_fd(", thystame ", cmd->fd);
		ft_putnbr_fd(g->cls[cmd->num_cli].resource.thystame, cmd->fd);
		ft_putstr_fd(", nourriture ", cmd->fd);
		ft_putnbr_fd(g->cls[cmd->num_cli].resource.nourriture, cmd->fd);
		ft_putendl_fd("}", cmd->fd);
	}
}

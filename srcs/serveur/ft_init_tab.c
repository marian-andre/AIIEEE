/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:24:28 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/11 15:12:01 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void	ft_init_tab(t_tab tab[12])
{
	tab[0].line = ft_strdup("voir");
	tab[0].t = 7;
	tab[1].line = ft_strdup("avance");
	tab[1].t = 7;
	tab[2].line = ft_strdup("droite");
	tab[2].t = 7;
	tab[3].line = ft_strdup("gauche");
	tab[3].t = 7;
	tab[4].line = ft_strdup("inventaire");
	tab[4].t = 1;
	tab[5].line = ft_strdup("prend");
	tab[5].t = 7;
	tab[6].line = ft_strdup("pose");
	tab[6].t = 7;
	tab[7].line = ft_strdup("expulse");
	tab[7].t = 7;
	tab[8].line = ft_strdup("broadcast");
	tab[8].t = 7;
	tab[9].line = ft_strdup("incantation");
	tab[9].t = 300;
	tab[10].line = ft_strdup("fork");
	tab[10].t = 42;
	tab[11].line = ft_strdup("life");
	tab[11].t = 126;
}

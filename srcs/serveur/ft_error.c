/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:09:25 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/16 15:39:45 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "serveur.h"

void		ft_usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" -p <port> -x <width >= 10> -y <height >= 10>");
	ft_putendl(" -n <team> [<team>] [<team>] ... -c <nb> -t <t>");
	ft_putendl("	-p numero de port (par defaut : 4242)");
	ft_putendl("	-x largeur du Monde (par defaut : 20)");
	ft_putendl("	-y hauteur du Monde (par defaut : 20)");
	ft_putendl("	-n nom_equipe_1 nom_equipe_2 ...");
	ft_putstr("	-c nombre de client autorises au commencement du jeu ");
	ft_putendl("(par defaut 6)");
	ft_putendl("	-t diviseur de l'unite de temps (par defaut : 100)");
	exit(0);
}

void		ft_error(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

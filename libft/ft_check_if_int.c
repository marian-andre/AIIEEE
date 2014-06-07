/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:01 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:01 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_if_int(char *nbr)
{
	double	d;

	if (nbr[0] == '-')
	{
		if (ft_strlen(nbr) > 11)
			return (0);
	}
	else
	{
		if (ft_strlen(nbr) > 10)
			return (0);
	}
	d = ft_atoi_double(nbr);
	if (d >= -2147483648 && d <= 2147483647)
		return (1);
	return (0);
}

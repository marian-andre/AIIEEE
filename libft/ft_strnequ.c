/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:03 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:03 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while (ft_tolower((int)*s1) == ft_tolower((int)*s2) && n--)
		{
			if (*s1 == '\0' || n == 0)
				return (1);
			s1++;
			s2++;
		}
	}
	return (0);
}

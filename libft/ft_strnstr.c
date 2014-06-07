/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:03 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:03 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	if (!s1 || !s2 || !n)
		return (NULL);
	len = ft_strlen(s2);
	if (n < len)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i <= (n - len))
	{
		if (ft_strncmp(&s1[i], s2, len) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}

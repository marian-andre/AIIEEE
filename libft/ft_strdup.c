/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:03 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/17 19:40:39 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	dest = NULL;
	if (s1)
	{
		if ((dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			dest[i] = s1[i];
		dest[i] = '\0';
	}
	return (dest);
}

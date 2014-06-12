/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:03 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/12 19:38:29 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_free(char *res, char *s1, char *s2, int opt)
{
	if (opt == 1)
		free(s1);
	else if (opt == 2)
		free(s2);
	else if (opt == 3)
	{
		free(s1);
		free(s2);
	}
	return (res);
}

char			*ft_strjoin_free(char *s1, char *s2, int opt)
{
	size_t	len;
	char	*dest;

	dest = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (dest)
		{
			dest = ft_strcpy(dest, s1);
			dest = ft_strcat(dest, s2);
		}
	}
	else if (s1)
		return (ft_free(ft_strdup(s1), s1, s2, opt));
	else if (s2)
		return (ft_free(ft_strdup(s2), s1, s2, opt));
	return (ft_free(dest, s1, s2, opt));
}

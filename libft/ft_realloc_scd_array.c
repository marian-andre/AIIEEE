/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_scd_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:02 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:02 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_rea_scd_array(char **src, int add)
{
	char	**ret;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	ret = (char**)malloc(sizeof(char*) * (i + add + 1));
	ret[i + add] = '\0';
	while (i >= 0)
	{
		ret[i] = src[i];
		i--;
	}
	free(src);
	return (ret);
}

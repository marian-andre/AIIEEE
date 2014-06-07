/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:03 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:03 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			ft_strdel2(char ***array)
{
	int		i;

	i = 0;
	if (array)
	{
		while ((*array)[i])
			free((*array)[i++]);
	}
	free(*array);
	*array = NULL;
}

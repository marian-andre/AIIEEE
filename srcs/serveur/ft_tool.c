/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:13:29 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/12 11:12:01 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

long	timevaldiff(t_time starttime, t_time finishtime)
{
	long	usec;

	usec = (finishtime.tv_sec - starttime.tv_sec) * 1000000;
	usec += (finishtime.tv_usec - starttime.tv_usec);
	return (usec);
}

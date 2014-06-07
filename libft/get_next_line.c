/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:52:23 by jgranet           #+#    #+#             */
/*   Updated: 2014/05/17 20:16:30 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

static size_t	get_len(char *str)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j == 0)
	{
		if (str[i] != '\n')
			i++;
		else
			j = 1;
	}
	return (i);
}

static int		compare(char **tmp, char ***line)
{
	if (*tmp)
	{
		*tmp = ft_strsub(*tmp, (get_len(*tmp) + 1),
						((ft_strlen(*tmp) - get_len(*tmp) + 1)));
		if (get_len(*tmp) != ft_strlen(*tmp))
		{
			**line = ft_strjoin(**line, (ft_strsub(*tmp, 0, get_len(*tmp))));
			ft_strdel(tmp);
			return (1);
		}
		else
			**line = ft_strjoin(**line, *tmp);
	}
	return (0);
}

static int		return_value(int ret)
{
	static int		i = 0;

	if (ret == 0)
	{
		if (i == 0)
		{
			i++;
			return (1);
		}
	}
	else if (ret == -1)
		return (-1);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	int				ret;
	static char		*tmp;

	*line = NULL;
	if (compare(&tmp, &line) == 1)
		return (1);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_strdel(&tmp);
		tmp = ft_strdup(buf);
		if (get_len(buf) != ft_strlen(tmp))
		{
			*line = ft_strjoin(*line, (ft_strsub(buf, 0, get_len(buf))));
			return (1);
		}
		else
			*line = ft_strjoin(*line, buf);
	}
	ft_strdel(&tmp);
	return (return_value(ret));
}

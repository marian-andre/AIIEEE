/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:55:36 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/17 17:20:22 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static t_time		ft_add_timval(t_game *g, t_time now, int t)
{
	float	usec;
	t_time	res;

	res.tv_sec = now.tv_sec + (t / g->time);
	usec = (float)t / (float)g->time;
	usec = (usec - floor(usec)) * 1000000;
	if (usec + now.tv_usec >= 1000000)
	{
		res.tv_sec++;
		usec += now.tv_usec - 1000000;
		res.tv_usec = usec;
	}
	else
		res.tv_usec = usec + now.tv_usec;
	return (res);
}

static t_time		ft_get_cd(t_game *g, char *line)
{
	int		i;
	t_time	res;

	res.tv_sec = 0;
	res.tv_usec = 0;
	i = 0;
	while (i < 13)
	{
		if (ft_strncmp(line, g->tab[i].line, ft_strlen(g->tab[i].line)) == 0)
		{
			gettimeofday(&res, NULL);
			res = ft_add_timval(g, res, g->tab[i].t);
			return (res);
		}
		i++;
	}
	return (res);
}

void				ft_del_node(t_game *g, t_cmd *cmd)
{
	t_cmd	*tmp;

	if (cmd == g->list)
		g->list = cmd->next;
	else
	{
		tmp = g->list;
		while (tmp->next != cmd)
			tmp = tmp->next;
		tmp->next = cmd->next;
	}
	free(cmd->cmd);
	free(cmd);
}

void				ft_add_node(t_game *g, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = g->list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cmd;
	}
	else
		g->list = cmd;
}

t_cmd				*ft_create_node(t_game *g, char *line, int i, int num_egg)
{
	t_cmd	*cmd;

	if ((cmd = (t_cmd *)malloc(sizeof(t_cmd))) == NULL)
		ft_error("ERROR malloc");
	cmd->cmd = ft_strdup(line);
	cmd->num_cli = i;
	cmd->num_egg = num_egg;
	cmd->next = NULL;
	cmd->fd = g->cls[i].cs;
	cmd->time = ft_get_cd(g, line);
	return (cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dbl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:03 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:03 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_data			*create_list(void)
{
	t_data		*root;

	root = (t_data *)malloc(sizeof(*root));
	if (root != NULL)
	{
		root->data = "NULL";
		root->index = 0;
		root->next = root;
		root->prev = root;
	}
	return (root);
}

void			add_forward(t_data *elem, void *data)
{
	t_data		*new;

	new = (t_data *)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->data = data;
		new->index = elem->index + 1;
		new->prev = elem;
		new->next = elem->next;
		elem->next->prev = new;
		elem->next = new;
	}
}

void			add_backward(t_data *elem, void *data)
{
	t_data		*new;

	new = (t_data *)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->data = data;
		new->index = elem->index - 1;
		new->prev = elem->prev;
		new->next = elem;
		elem->prev->next = new;
		elem->prev = new;
	}
}

void			add_head(t_data *root, void *data)
{
	add_forward(root, data);
}

void			add_tail(t_data *root, void *data)
{
	add_backward(root, data);
}

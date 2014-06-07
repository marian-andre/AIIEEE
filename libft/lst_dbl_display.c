/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dbl_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:03 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:03 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			display_list(t_data *root)
{
	int			i;
	t_data		*tmp;

	i = 0;
	tmp = root->next;
	while (tmp->index != 0)
	{
		ft_printf("List_double[%d] : %s\n", i, tmp->data);
		tmp = tmp->next;
		i++;
	}
}

t_data			*fill_list(int argc, char **argv)
{
	int				i;
	t_data			*root;
	t_data			*tmp;

	root = create_list();
	i = 0;
	tmp = root;
	while (i < argc - 1)
	{
		add_forward(tmp, argv[i + 1]);
		tmp = tmp->next;
		i++;
	}
	return (root);
}

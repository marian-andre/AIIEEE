/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:02 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:02 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *dp)
{
	t_list	*cur;
	t_list	*last;

	cur = dp;
	if (cur)
	{
		dp = dp->next;
		cur->next = NULL;
		while (dp)
		{
			last = cur;
			cur = dp;
			dp = dp->next;
			cur->next = last;
		}
	}
	return (cur);
}

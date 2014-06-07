/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:02 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:02 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putz_pf(va_list ap, int nbb)
{
	int		i;

	i = 0;
	ap = ap + 0;
	while (i++ < nbb - 1)
		ft_putchar(' ');
	ft_putchar('Z');
	return (i + 1);
}

int		ft_puthexa_min_pf(va_list ap, int nbb)
{
	int		i;
	int		nb;
	int		nb2;

	i = 0;
	nb = va_arg(ap, unsigned int);
	nb2 = ft_return_nb_nb(nb, "0123456789abcdef");
	while (i++ < nbb - nb2)
		ft_putchar(' ');
	return (ft_putnbr_base_u(nb, "0123456789abcdef") + i);
}

int		ft_puthexa_max_pf(va_list ap, int nbb)
{
	int		i;
	int		nb;
	int		nb2;

	i = 0;
	nb = va_arg(ap, unsigned int);
	nb2 = ft_return_nb_nb(nb, "0123456789ABCDEF");
	while (i++ < nbb - nb2)
		ft_putchar(' ');
	return (ft_putnbr_base_u(nb, "0123456789ABCDEF") + i);
}

int		ft_puthexa_pf(va_list ap, int nbb)
{
	void		*nb;
	int			i;
	int			nb2;

	i = 0;
	nb = va_arg(ap, void*);
	nb2 = ft_return_nb_nb((long)nb, "0123456789abcdef") + 2;
	while (i++ < nbb - nb2)
		ft_putchar(' ');
	ft_putstr("0x");
	return (ft_putnbr_base((long)nb, "0123456789abcdef") + i + 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declima.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:39:54 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 15:39:55 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_d(va_list ar, t_flags *f, int fd)
{
	int				i;
	long long int	d;
	char			*s;

	d = va_arg(ar, long long int);
	if ((unsigned long long)d == 9223372036854775808U)
	{
		ft_putstr("-9223372036854775808");
		return (ft_strlen("-9223372036854775808"));
	}
	if (f->w == 0 && f->tchn_t == 1 && f->tchn == 0 && f->space == 1 && d == 0)
	{
		s = ft_memalloc(2);
		s[0] = ' ';
		return (ft_printnbr(s, fd));
	}
	if (f->w == 0 && f->tchn_t == 1 && f->tchn == 0 && f->plus == 1 && d == 0)
	{
		s = ft_memalloc(2);
		s[0] = '+';
		return (ft_printnbr(s, fd));
	}
	i = ft_putnbrlln(d, f, fd, 0);
	return (i);
}

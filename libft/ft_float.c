/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:56:19 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 15:56:20 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_float(va_list ar, t_flags *f, int fd)
{
	int		i;
	int		z;

	i = 0;
	z = f->tchn == 0 && f->tchn_t != 1 ? 6 : f->tchn;
	i += ft_putnbrf(ar, f, z, fd);
	return (i);
}

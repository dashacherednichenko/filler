/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:52:06 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/30 14:52:09 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putcharn(char c, t_flags *f, int i, int fd)
{
	int w;
	int z;

	i = 1;
	(f->min == 1 && f->w >= 0) ? f->w = -f->w : 0;
	w = f->w;
	z = f->zr;
	while (i < f->w)
	{
		z == 1 ? ft_putchar_fd('0', fd) : ft_putchar_fd(' ', fd);
		i++;
	}
	ft_putchar_fd(c, fd);
	while (w + i < 0)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
	return (i);
}

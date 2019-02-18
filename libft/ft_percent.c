/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:55:56 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/04 14:55:59 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_percent(char c, t_flags *f, int fd)
{
	int i;

	if (f->percent != -1)
		i = ft_putcharn(c, f, 0, fd);
	else
		i = 0;
	return (i);
}

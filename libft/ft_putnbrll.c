/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:32:57 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/03 14:33:02 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrll(long long int n, int i)
{
	unsigned long long int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		i++;
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		i++;
		i = ft_putnbrll(nb / 10, i);
		ft_putchar(nb % 10 + '0');
	}
	else
	{
		ft_putchar(nb + '0');
		i++;
	}
	return (i);
}

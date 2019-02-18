/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:11:05 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/06 16:11:07 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(unsigned long long value, int base)
{
	size_t len;

	len = 1;
	while (value >= (unsigned)base)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char			*ft_uitoa_base(unsigned long long int value, int base)
{
	char					*str;
	size_t					len;
	unsigned long long int	nb;

	if (base < 2 || base > 16)
		return (NULL);
	nb = value;
	len = ft_len(nb, base);
	str = ft_strnew(len + 1);
	while (nb >= (unsigned)base)
	{
		if ((nb % base) <= 10)
			str[(len--) - 1] = (nb % base) + 48;
		else
			str[(len--) - 1] = 'A' + ((nb % base) - 10);
		nb = nb / base;
	}
	if (nb >= 10)
		nb = nb - 10 - 48 + 'A';
	str[len - 1] = nb + 48;
	return (str);
}

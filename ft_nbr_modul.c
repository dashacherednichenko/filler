/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_modul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:41:36 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/18 19:41:37 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

int 				ft_nbr_modul(int x, int y)
{
	int nb;

	nb = x - y;
	nb < 0 ? nb = -nb : 0;
	return (nb);
}

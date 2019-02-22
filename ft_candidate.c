/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_candidate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:35:12 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/22 17:35:13 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

int	ft_cand(t_fill *f, int x, int y, int d)
{
	f->cand_x = x;
	f->cand_y = y;
	f->c_d = d;
	return (1);
}

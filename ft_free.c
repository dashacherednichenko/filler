/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:02:35 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/22 12:02:37 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

void	ft_free_map(t_fill *f)
{
	int x;

	x = 0;
	while (x < f->x)
	{
		free(f->mp[x]);
		x++;
	}
	free(f->mp);
}

int		ft_obnul_piece(t_fill *f)
{
	int x;

	x = 0;
	while (x < f->p_x_first)
	{
		free(f->piece[x]);
		x++;
	}
	f->cand_x = 0;
	f->cand_y = 0;
	f->c_d = 0;
	free(f->piece);
	return (0);
}

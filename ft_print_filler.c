/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:26:13 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/20 18:26:15 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

int	ft_printmap(int fd, t_fill *f)
{
	int x;
	int y;

	x = 0;
	while (x < f->x)
	{
		y = 0;
		while (y < f->y)
		{
			ft_fdprintf(fd, "%3d ", f->map[x][y]);
			y++;
		}
		ft_fdprintf(fd, "\n");
		x++;
	}
	return (0);
}

int	ft_printpiece(int fd, t_fill *f)
{
	int x;
	int y;

	x = 0;
	while (x < f->p_x)
	{
		y = 0;
		while (y < f->p_y)
		{
			ft_fdprintf(fd, "%3d ", f->piece[x][y]);
			y++;
		}
		ft_fdprintf(fd, "\n");
		x++;
	}
	return (0);
}

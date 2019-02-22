/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:18:35 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/20 18:18:36 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

int				ft_init_piece(int x, t_fill *f, char *line)
{
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < f->p_y)
	{
		if (line[i] == '.')
			f->piece[x][y] = 0;
		else if (line[i] == '*')
			f->piece[x][y] = -20;
		y++;
		i++;
	}
	return (0);
}

static int		ft_check_column(t_fill *f, int y)
{
	int x;

	x = 0;
	while (x < f->p_x)
	{
		if (f->piece[x][y] == -20)
			return (0);
		x++;
	}
	return (1);
}

int				ft_cut_columns_piece(t_fill *f)
{
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < f->p_y)
	{
		if (ft_check_column(f, y) == 0)
			i++;
		else if (ft_check_column(f, y) == 0 && i != 0)
		{
			f->p_y = y;
			return (0);
		}
		y++;
	}
	return (0);
}

int				ft_check_piece(int x, int y, t_fill *f)
{
	int px;
	int py;
	int ix;
	int iy;
	int i;
	int d;

	px = 0;
	i = 0;
	ix = x;
	d = 0;
	while (px < f->p_x)
	{
		py = 0;
		iy = y;
		while (py < f->p_y)
		{
			if (f->piece[px][py] == -20)
			{
				if (f->map[ix][iy] == -20)
				{
					i++;
					if (i > 1)
						return (0);
				}
				else if (f->map[ix][iy] == -10 && f->piece[px][py] == -20)
					return (0);
				else if (f->map[ix][iy] != -10 && f->map[ix][iy] != -20)
				{
					d += f->map[ix][iy];
				}
			}
			if (i > 1)
				return (0);
			py++;
			iy++;
		}
		if (i > 1)
			return (0);
		px++;
		ix++;
	}
	if (i == 1 && (f->cand_dist == 0 || f->cand_dist > d))
	{
		f->cand_x = x;
		f->cand_y = y;
		f->cand_dist = d;
		return (1);
	}
	else
		return (0);
}

int				ft_place_piece(t_fill *f)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	f->cand_y = 0;
	f->cand_x = 0;
	f->cand_dist = 0;
	while (x < f->x && (x + f->p_x) <= f->x)
	{
		y = 0;
		while (y < f->y && (y + f->p_y) <= f->y)
		{
			if (ft_check_piece(x, y, f) == 1)
				i++;
			y++;
		}
		x++;
	}
	if (i > 0)
	{
		ft_printf("%d %d\n", f->cand_x, f->cand_y);
		ft_obnul_piece(f);
		return (1);
	}
	ft_printf("0 0\n");
	ft_obnul_piece(f);
	return (0);
}

int				ft_createpiece(t_fill *f, char *line)
{
	int i;
	int x;

	x = 0;
	i = 6;
	f->p_x = ft_atoi(&line[i]);
	f->p_x_first = f->p_x;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	f->p_y = ft_atoi(&line[i]);
	f->piece = (int**)malloc(sizeof(int*) * f->p_x);
	while (x < f->p_x)
	{
		f->piece[x] = (int*)malloc(sizeof(int) * f->p_y);
		x++;
	}
	return (0);
}

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

int g_px;
int g_py;
int g_i;

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

int				ft_cut_columns_piece(t_fill *f, char *line)
{
	int y;
	int i;

	i = 0;
	y = 0;
	free(line);
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

int				ft_check_piece(int x, int y, t_fill *f, int d)
{
	int b;
	int z;

	g_px = -1;
	g_i = 0;
	while (++g_px < f->p_x)
	{
		b = x + g_px;
		g_py = 0;
		while (g_py < f->p_y)
		{
			z = y + g_py;
			if (f->piece[g_px][g_py] == -20)
			{
				if (f->mp[b][z] == -20)
					if (g_i++ > 1)
						return (0);
				if (f->mp[b][z] == -10 && f->piece[g_px][g_py] == -20)
					return (0);
				f->mp[b][z] != -10 && f->mp[b][z] != -20 ? d += f->mp[b][z] : 0;
			}
			g_py++;
		}
	}
	return (g_i == 1 && (f->c_d == 0 || f->c_d > d)) ? ft_cand(f, x, y, d) : 0;
}

int				ft_place_piece(t_fill *f, int x, int i)
{
	int y;

	f->cand_y = 0;
	f->cand_x = 0;
	f->c_d = 0;
	while (x < f->x && (x + f->p_x) <= f->x)
	{
		y = 0;
		while (y < f->y && (y + f->p_y) <= f->y)
		{
			if (ft_check_piece(x, y, f, 0) == 1)
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

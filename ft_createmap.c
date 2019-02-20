/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:17:24 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/18 14:17:29 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

int ft_printmap(int fd, t_fill *f)
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

int ft_printpiece(int fd, t_fill *f)
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

int	ft_first_initmap(int fd, int x, t_fill *f, char *line)
{
	int y;
	int i;

	y = 0;
	i = 4;
	while (y < f->y)
	{
		if (line[i] == '.')
			f->map[x][y] = 0;
		else if (line[i] == f->pl || line[i] == f->pl + 32)
		{
			f->map[x][y] = -20;
		}
		else if (line[i] == f->en || line[i] == f->en + 32)
		{
			f->map[x][y] = -10;
		}
//		ft_fdprintf(fd, "%d", f->map[x][y]);
		y++;
		i++;
	}
//	ft_fdprintf(fd, "\n");
	return (0);
}
//int	ft_second_initmap(int fd, int x, t_fill *f, char *line)
//{
//	int y;
//	int i;
//
//	y = 0;
//	i = 4;
//	while (y < f->y)
//	{
//		if (line[i] == '.')
//			f->map[x][y] = 0;
//		else if (line[i] == f->pl || line[i] == f->pl + 32)
//		{
//			f->map[x][y] = -20;
//		}
//		else if (line[i] == f->en || line[i] == f->en + 32)
//		{
//			f->map[x][y] = -10;
//		}
////		ft_fdprintf(fd, "%d", f->map[x][y]);
//		y++;
//		i++;
//	}
////	ft_fdprintf(fd, "\n");
//	return (0);
//}

int	ft_initmap(int fd, t_fill *f)
{
	int x;
	int y;

	x = 0;
	while (x < f->x)
	{
		y = 0;
		while (y < f->y)
		{
			if (f->map[x][y] == -10)
			{
				ft_calc_distance(fd, x, y, f);
			}
			y++;
		}
		x++;
	}
//	ft_printmap(fd, f);
	return (0);
}

int 				ft_calc_distance(int fd, int zx, int zy, t_fill *f)
{
	int x;
	int y;
	int z;

	x = 0;
	while (x < f->x)
	{
		y = 0;
		while (y < f->y)
		{
			if (f->map[x][y] != -10 && f->map[x][y] != -20)
			{

				z = ft_nbr_modul(x,  zx) + ft_nbr_modul(y,  zy);
				if (f->map[x][y] == 0 || z < f->map[x][y])
					f->map[x][y] = z;
			}
			y++;
		}
		x++;
	}
	return (0);
}



int					ft_createmap(t_fill *f, char *line)
{
	int i;
	int x;

	x = 0;
	i = 8;
	f->x = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	f->y = ft_atoi(&line[i]);
	f->map = (int**)malloc(sizeof(int*) * f->x);
	while (x < f->x)
	{
		f->map[x] = (int*)malloc(sizeof(int) * f->y);
		x++;
	}
	return (0);
}

int					ft_createpiece(t_fill *f, char *line)
{
	int i;
	int x;

	x = 0;
	i = 6;
	f->p_x = ft_atoi(&line[i]);
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

int					ft_init_piece(int fd, int x, t_fill *f, char *line)
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

int					ft_cut_columns_piece(int fd, t_fill *f)
{
	int x;
	int y;
	int i;
	int xi;

	x = 0;
	i = 0;

	while (x < f->p_x)
	{
		y = 0;
		while (y < f->p_y)
		{
			if (f->piece[x][y] == -20 && y == f->p_y - 1)
			{
				return (0);
			}
			if (f->piece[x][y] == -20)
				i++;
			else if (f->piece[x][y] == 0 && i != 0)
			{
				xi = x;
				while (xi < f->p_x)
				{
					if (f->piece[xi][y] == -20)
					{
						xi = x;
						i++;
						break;
					}
					xi++;
				}
				if ((xi == f->p_x && i != 0) || (y == f->p_y - 1 && i != 0))
				{
					f->p_y = y + 1;
					return (0);
				}
			}
			y++;
		}
		x++;
	}
	return (0);
}

int ft_check_piece(int x, int y, t_fill *f)
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
					i++;
				else if (f->map[ix][iy] == -10)
					return (0);
				else
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
	if (i == 1 && (f->cand_dist == 0 || f->cand_dist >= d))
	{
		f->cand_x = x;
		f->cand_y = y;
		f->cand_dist = d;
		return (1);
	}
	else
		return (0);
}

int ft_place_piece(int fd, t_fill *f)
{
	int x;
	int y;

	x = 0;
	while (x < f->x && (x + f->p_x) < f->x)
	{
		y = 0;
		while (y < f->y && (y + f->p_y) < f->y)
		{
			if (ft_check_piece(x , y, f) == 1)
			{
				ft_printf("%d %d\n", f->cand_x, f->cand_y);
				return (1);
			}
			y++;
		}
		x++;
	}
	ft_printf("0 0\n");
	return (0);
}
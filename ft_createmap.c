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
		y++;
		i++;
	}
	return (0);
}

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
	return (0);
}

int	ft_calc_distance(int fd, int zx, int zy, t_fill *f)
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
				z = ft_nbr_modul(x, zx) + ft_nbr_modul(y, zy);
				if (f->map[x][y] == 0 || z < f->map[x][y])
					f->map[x][y] = z;
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	ft_createmap(t_fill *f, char *line)
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

int	next_createmap(t_fill *f)
{
	int x;

	x = 0;
	f->map = (int**)malloc(sizeof(int*) * f->x);
	while (x < f->x)
	{
		f->map[x] = (int*)malloc(sizeof(int) * f->y);
		x++;
	}
	return (0);
}

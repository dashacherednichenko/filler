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

int	ft_first_initmap(int x, t_fill *f, char *line)
{
	int y;
	int i;

	y = 0;
	i = 4;
	while (y < f->y)
	{
		if (line[i] == '.')
			f->mp[x][y] = 0;
		else if (line[i] == f->pl || line[i] == f->pl + 32)
			f->mp[x][y] = -20;
		else if (line[i] == f->en || line[i] == f->en + 32)
			f->mp[x][y] = -10;
		y++;
		i++;
	}
	free(line);
	return (0);
}

int	ft_initmap(t_fill *f)
{
	int x;
	int y;

	x = 0;
	while (x < f->x)
	{
		y = 0;
		while (y < f->y)
		{
			if (f->mp[x][y] == -10)
				ft_calc_distance(x, y, f);
			y++;
		}
		x++;
	}
	return (0);
}

int	ft_calc_distance(int zx, int zy, t_fill *f)
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
			if (f->mp[x][y] != -10 && f->mp[x][y] != -20)
			{
				z = ft_nbr_modul(x, zx) + ft_nbr_modul(y, zy);
				if (f->mp[x][y] == 0 || z < f->mp[x][y])
					f->mp[x][y] = z;
			}
			y++;
		}
		x++;
	}
	return (0);
}

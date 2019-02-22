/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:26:32 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/22 17:26:33 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

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
	f->mp = (int**)malloc(sizeof(int*) * f->x);
	while (x < f->x)
	{
		f->mp[x] = (int*)malloc(sizeof(int) * f->y);
		x++;
	}
	free(line);
	return (0);
}

int	next_createmap(t_fill *f)
{
	int x;

	x = 0;
	f->mp = (int**)malloc(sizeof(int*) * f->x);
	while (x < f->x)
	{
		f->mp[x] = (int*)malloc(sizeof(int) * f->y);
		x++;
	}
	return (0);
}

int	ft_createpiece(t_fill *f, char *line)
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

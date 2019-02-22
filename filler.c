/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:07:18 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/18 11:07:23 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"
#define PL "$$$ exec p"
#define MP "Plateau "

int g_t;
int g_r;
int g_ii;

static char	*ft_jump2line(char *l)
{
	free(l);
	get_next_line(0, &l);
	free(l);
	get_next_line(0, &l);
	return (l);
}

static char	*ft_read_piece(char *l, t_fill *f, int i)
{
	while (++i < g_r)
	{
		free(l);
		get_next_line(0, &l);
		if (i > 0 && !ft_strchr(l, '*') && g_ii != 0 && g_t == 0)
		{
			f->p_x = i;
			g_t++;
		}
		else if (!ft_strchr(l, '*') && g_ii == 0)
			ft_init_piece(i, f, l);
		else if (ft_strchr(l, '*'))
		{
			ft_init_piece(i, f, l);
			g_ii++;
		}
	}
	return (l);
}

int			ft_filler(char *l, t_fill *f, int x, int i)
{
	g_t = 0;
	get_next_line(0, &l) >= 0 && !ft_strncmp(PL, l, 10) ? ft_in_pl(f, l) : 0;
	get_next_line(0, &l) >= 0 && !ft_strncmp(MP, l, 8) ? ft_cr_mp(f, l) : 0;
	if (get_next_line(0, &l) >= 0)
	{
		free(l);
		while (get_next_line(0, &l) >= 0)
		{
			(!ft_strncmp(MP, l, 8)) ? l = ft_jump2line(l) : 0;
			x < f->x ? ft_first_initmap(x++, f, l) : 0;
			if (!ft_strncmp("Piece ", l, 6))
			{
				i = ft_initmap(f) - 1;
				g_ii = ft_createpiece(f, l);
				g_r = f->p_x;
				l = ft_read_piece(l, f, i);
				x = ft_cut_columns_piece(f, l);
				if (ft_place_piece(f, 0, 0) == 0)
					break ;
				g_t = 0;
			}
		}
	}
	return (1);
}

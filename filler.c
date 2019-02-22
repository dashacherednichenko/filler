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

int	ft_filler(char *line, t_fill *f, int x, int i)
{
	int		ii;
	int		r;
	int		t;

	t = 0;
	if (get_next_line(0, &line) >= 0 && !ft_strncmp("$$$ exec p", line, 10))
		ft_init_players(f, line);
	if (get_next_line(0, &line) >= 0 && !ft_strncmp("Plateau ", line, 8))
		ft_createmap(f, line);
	if (get_next_line(0, &line) >= 0)
	{
		free(line);
		while (get_next_line(0, &line) >= 0)
		{
			if (!ft_strncmp("Plateau ", line, 8))
			{
				free(line);
				get_next_line(0, &line);
				free(line);
				get_next_line(0, &line);
			}
			if (x < f->x)
				ft_first_initmap(x++, f, line);
			if (!ft_strncmp("Piece ", line, 6))
			{
				ft_initmap(f);
				ft_createpiece(f, line);
				i = 0;
				ii = 0;
				r = f->p_x;
				while (i < r)
				{
					free(line);
					get_next_line(0, &line);
					if (i > 0 && !ft_strchr(line, '*') && ii != 0 && t == 0)
					{
						f->p_x = i;
						t++;
					}
					else if (!ft_strchr(line, '*') && ii == 0)
						ft_init_piece(i, f, line);
					else if (ft_strchr(line, '*'))
					{
						ft_init_piece(i, f, line);
						ii++;
					}
					i++;
				}
				free(line);
				ft_cut_columns_piece(f);
				if (ft_place_piece(f, 0, 0) == 0)
					break ;
				x = 0;
				t = 0;
			}
		}
	}
	return (1);
}

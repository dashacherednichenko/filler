/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:06:43 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/18 11:06:47 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

int main(void)
{
	int		fd;
	char	*line;
	t_fill	*f;
	int		x;
	int		i;
	int		ii;
	int		r;
	int 	t;

	x = 0;
	t = 0;
	f = (t_fill*)malloc(sizeof(t_fill));
	fd = open("test", O_RDWR| O_TRUNC);
	if (get_next_line(0, &line) >= 0 && !ft_strncmp("$$$ exec p", line, 10))
	{
		ft_init_players(f, line);
		free(line);
	}
	if (get_next_line(0, &line) >= 0 && !ft_strncmp("Plateau ", line, 8))
	{
		ft_createmap(f, line);
		free(line);
	}
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
			{
				ft_first_initmap(x++, f, line);
				free(line);
			}
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
//						ft_init_piece(fd, i, f, line);
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
				if (ft_place_piece(f) == 0)
					break;
				x = 0;
				t = 0;
			}
		}
	}
	ft_free_map(f);
	free(f);
	system("leaks -q dpiven.filler > leaks");
	return (0);
}

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

int ft_obnul_piece(t_fill *f)
{
	int x;

	x = 0;
	while (x < f->p_x)
	{
		free(f->piece[x]);
		x++;
	}
	f->cand_x = 0;
	f->cand_y = 0;
	f->cand_dist = 0;
	return (0);
}

int main(void)
{
	int		fd;
	char	*line;
	t_fill	*f;
	int		x;
	int		i;
	int		ii;
	int r;

	x = 0;
	f = (t_fill*)malloc(sizeof(t_fill));
	fd = open("test", O_RDWR| O_TRUNC);
	if (get_next_line(0, &line) >= 0 && !ft_strncmp("$$$ exec p", line, 10))
		ft_init_players(f, line);
	if (get_next_line(0, &line) >= 0 && !ft_strncmp("Plateau ", line, 8))
		ft_createmap(f, line);
	if (get_next_line(0, &line) >= 0)
	{
		while (get_next_line(0, &line) >= 0)
		{
			if (!ft_strncmp("Plateau ", line, 8))
			{
				get_next_line(0, &line);
				get_next_line(0, &line);
			}
			if (x < f->x)
			{
				ft_first_initmap(fd, x, f, line);
//				ft_fdprintf(fd, "%s\n", line);
				x++;
			}
			if (!ft_strncmp("Piece ", line, 6))
			{
				ft_initmap(fd, f);
				ft_createpiece(f, line);
//				ft_fdprintf(fd, "X%d\n", f->p_x);
//				ft_fdprintf(fd, "Y%d\n", f->p_y);
				i = 0;
				ii = 0;
				r = f->p_x;
				while (i < r)
				{
					(get_next_line(0, &line));
					if (i > 0 && !ft_strchr(line, '*') && ii != 0)
					{
//						while (i < f->p_x)
//							free(f->piece[f->p_x--]);
						f->p_x = i;
					}
					else if (!ft_strchr(line, '*') && ii == 0)
					{
						ft_init_piece(fd, i, f, line);
//						ii++;
					}
					else if (ft_strchr(line, '*'))
					{
						ft_init_piece(fd, i, f, line);
						ii++;
					}
					i++;
				}
				ft_cut_columns_piece(fd, f);
				ft_printpiece(fd, f);
				ft_fdprintf(fd, "X%d\n", f->p_x);
				ft_fdprintf(fd, "Y%d\n", f->p_y);
				if (ft_place_piece(fd, f) == 0)
				{
					ft_printpiece(fd, f);
					ft_obnul_piece(f);
//					x = 0;
					break ;
				}
				ft_obnul_piece(f);
				x = 0;
//				i++;
			}

		}
	}
	ft_printmap(fd, f);
//	system("leaks dpiven.filler");
	return 0;
}

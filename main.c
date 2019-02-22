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
				ft_first_initmap(fd, x, f, line);
				free(line);
//				ft_fdprintf(fd, "%s\n", line);
				x++;
			}
			if (!ft_strncmp("Piece ", line, 6))
			{
				ft_initmap(fd, f);
				ft_createpiece(f, line);
				i = 0;
				ii = 0;
				r = f->p_x;
				while (i < r)
				{
					free(line);
					get_next_line(0, &line);
					if (i > 0 && !ft_strchr(line, '*') && ii != 0)
						f->p_x = i;
					else if (!ft_strchr(line, '*') && ii == 0)
						ft_init_piece(fd, i, f, line);
					else if (ft_strchr(line, '*'))
					{
						ft_init_piece(fd, i, f, line);
						ii++;
					}
					i++;
				}
				free(line);
				ft_cut_columns_piece(fd, f);
				ft_printpiece(fd, f);
				if (ft_place_piece(fd, f) == 0)
				{

					break ;
				}
//				ft_obnul_piece(f);
				x = 0;
			}
		}
	}
	ft_printmap(fd, f);
	ft_free_map(f);
	free (f);
	system("leaks -q dpiven.filler > leaks");
	return (0);
}

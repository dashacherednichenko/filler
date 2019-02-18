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
	t_fill	*fill;
	int 	i;

	fill = (t_fill*)malloc(sizeof(t_fill));
	fd = open("test", O_RDWR| O_TRUNC);
	if (get_next_line(0, &line) >= 0 && ft_strncmp("$$$ exec p", line, 10) == 0)
	{
		fill->player = line[10] == '1' ? 1 : 2;
		fill->pl = line[10] == '1' ? 'O' : 'X';
		fill->en = line[10] == '1' ? 'X' : 'O';
		fill->enemy = line[10] == '1' ? 2 : 1;
//		ft_fdprintf(fd, "PLAY %d %c\n", fill->player, fill->pl);
//		ft_fdprintf(fd, "ENEM %d %c\n", fill->enemy, fill->en);
	}
	if (get_next_line(0, &line) >= 0 && ft_strncmp("Plateau ", line, 8) == 0)
	{
		i = 8;
		fill->x = ft_atoi(&line[i]);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		fill->y = ft_atoi(&line[i]);
//		ft_fdprintf(fd, "X %d\n", fill->x);
//		ft_fdprintf(fd, "Y %d\n", fill->y);
	}
	while (get_next_line(0, &line) >= 0)
	{
		ft_fdprintf(fd, "%s\n", line);
	}

//	system("leaks dpiven.filler");
	return 0;
}

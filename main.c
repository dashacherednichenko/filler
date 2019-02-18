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

int main(void)
{
	int fd;
	char *line;

	fd = open("test", O_RDWR| O_TRUNC);
	while (get_next_line(0, &line) > 0)
	{
		ft_fdprintf(fd, "%s\n", line);
	}
//	system("leaks dpiven.filler");
	return 0;
}

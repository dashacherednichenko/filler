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

int	main(void)
{
	int		fd;
	char	*line;
	t_fill	*f;
	int		x;

	x = 0;
	line = NULL;
	f = (t_fill*)malloc(sizeof(t_fill));
	fd = open("test", O_RDWR | O_TRUNC);
	ft_filler(line, f, x, 0);
	ft_free_map(f);
	free(f);
	system("leaks -q dpiven.filler > leaks");
	return (0);
}

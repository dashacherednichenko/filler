/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:30:46 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/18 14:30:47 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "libfiller.h"

int	ft_in_pl(t_fill *f, char *line)
{
	f->player = line[10] == '1' ? 1 : 2;
	f->pl = line[10] == '1' ? 'O' : 'X';
	f->en = line[10] == '1' ? 'X' : 'O';
	f->enemy = line[10] == '1' ? 2 : 1;
	free(line);
	return (0);
}

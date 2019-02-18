/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:18:25 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 18:18:26 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_txt(char *s, t_flags *f, int i, int fd)
{
	while (s[i] != '%' && s[i])
	{
		ft_putchar_fd(s[i++], fd);
		f->l++;
	}
	return (i);
}

int	ft_precision(char *s, t_flags *f, int i)
{
	f->tchn_t = 1;
	f->tchn = ft_isdigit(s[++i]) ? ft_atoi(&s[i]) : 0;
	i = ft_nb_pass(s, i);
	return (i);
}

int	ft_nb_pass(char *s, int i)
{
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i - 1);
}

int	ft_width(char *s, t_flags *f, int i)
{
	f->w = ft_atoi(&s[i]);
	i = ft_nb_pass(s, i);
	return (i);
}

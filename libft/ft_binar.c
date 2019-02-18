/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:57:52 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/08 14:57:53 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int g_u = 0;

static int	ft_print_bin(char *s, int fd, t_flags *f, char *tmp)
{
	int i;
	int ii;

	i = 0;
	ii = 0;
	while (s[ii])
	{
		ft_putchar_fd(s[ii++], fd);
		if (f->plus == 1 && ii % 8 == 0 && s[ii])
		{
			ft_putchar_fd(' ', fd);
			i++;
		}
		i++;
	}
	free(s);
	if (tmp)
		free(tmp);
	return (i);
}

int			ft_bin(va_list ar, t_flags *f, int j, int fd)
{
	int				ji;
	char			*s;
	long long int	d;
	char			*tmp;

	d = va_arg(ar, long long int);
	f->mod && !ft_strcmp(f->mod, "h") ? j = 16 : 0;
	f->mod && !ft_strcmp(f->mod, "h") ? d = (short int)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? j = 8 : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? d = (unsigned char)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (long int)d : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? j = 64 : 0;
	!f->mod ? d = (int)d : 0;
	ji = j;
	tmp = ft_memalloc(j-- + 1);
	s = ft_itoa_base(d, 2);
	g_u = ft_strlen(s);
	f->plus == 1 ? f->zr = 1 : 0;
	if (f->plus == 0)
		return (ft_print_bin(s, fd, f, tmp));
	while (j >= 0)
		tmp[j--] = '0';
	while (g_u >= 0)
		tmp[ji--] = s[g_u--];
	return (ft_print_bin(tmp, fd, f, s));
}

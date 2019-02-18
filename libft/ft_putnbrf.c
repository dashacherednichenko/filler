/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:32:57 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/03 14:33:02 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int g_x = 0;
int g_f = 0;

static char	*ft_ost(char *str, double nb, int z, int i)
{
	while (i < z)
	{
		nb = (nb * 10);
		str[i++] = (int)(nb) + '0';
		nb = (nb - (long long)nb);
	}
	str[i] = '\0';
	nb = nb * 10;
	z--;
	g_x = ((int)(nb) >= 5) ? 1 : 0;
	while (g_x == 1 && z >= 0)
	{
		if (str[z] < '9')
		{
			str[z] = str[z] + 1;
			g_x = 0;
		}
		else
		{
			str[z] = '0';
			g_x = 1;
		}
		z--;
	}
	return (str);
}

static int	ft_addost_f(char *str, char *s1, t_flags *f, int minus)
{
	int t;

	minus == 1 ? s1 = ft_strjoinfree("-", s1, 2) : 0;
	if (f->tchn_t == 1 && f->tchn == 0 && f->resh != 1)
		free(str);
	else
	{
		s1 = ft_strjoinfree(s1, ".", 1);
		s1 = ft_strjoinfree(s1, str, 3);
	}
	t = ft_puts_n(s1, ft_nultchn(f), minus, g_f);
	free(s1);
	return (t);
}

static char	*ft_nan(long double ld, t_flags *f)
{
	char *s;

	if (ld != ld)
	{
		f->plus = 0;
		f->space = 0;
		f->zr = 0;
		return (ft_strdup("nan"));
	}
	else if (ld * 2 == ld && ld != 0)
	{
		f->zr = 0;
		s = ld < 0.0 ? ft_strdup("-inf") : ft_strdup("inf");
		f->plus == 1 ? f->space = 0 : 0;
		f->plus == 1 ? s = ft_strjoinfree("+", s, 2) : 0;
		f->space == 1 ? s = ft_strjoinfree(" ", s, 2) : 0;
		return (s);
	}
	return (0);
}

int			ft_putnbrf(va_list ar, t_flags *f, int z, int fd)
{
	char				*s1;
	long double			ld;
	int					minus;
	char				*str;

	g_f = fd;
	ld = f->mod && !ft_strcmp(f->mod, "L") ?\
		va_arg(ar, long double) : va_arg(ar, double);
	if (ft_nan(ld, f) != 0)
		return (ft_puts_n(ft_nan(ld, f), f, 0, fd));
	minus = ((*(((char*)&ld) + 9)) >> 7) ? 1 : 0;
	ld < 0 ? ld = -1 * ld : 0;
	str = ft_memalloc(z + 1);
	str = ft_ost(str, ((double)ld - (long long)ld), z, 0);
	g_x == 1 ? ld = ld + 1 : 0;
	s1 = ft_itoa_baseld(ld, 10);
	if ((f->plus == 1 || f->space == 1) && minus != 1)
		s1 = f->plus == 1 ?\
			ft_strjoinfree("+", s1, 2) : ft_strjoinfree(" ", s1, 2);
	return (ft_addost_f(str, s1, f, minus));
}

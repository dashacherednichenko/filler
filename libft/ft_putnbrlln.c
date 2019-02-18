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

int g_i = 0;
int g_ii = 0;

static char	*ft_putzero_s(char *s, int z)
{
	while (z >= 0)
		s[z--] = '0';
	return (s);
}

static char	*ft_putzr_sg(char *s, int z, t_flags *f)
{
	while (z > 0)
		s[z--] = '0';
	g_ii == 1 ? s[z] = '-' : 0;
	f->plus == 1 && g_ii != 1 ? s[z] = '+' : 0;
	f->space == 1 && g_ii != 1 ? s[z] = ' ' : 0;
	f->zr == 1 && f->w > g_i ? s[0] = '0' : 0;
	return (s);
}

static int	ft_d_flags(t_flags *f)
{
	int z;

	g_ii == 1 || f->plus == 1 ? f->space = 0 : 0;
	f->tchn < 0 ? f->tchn_t = 0 : 0;
	f->tchn_t == 1 || f->min == 1 ? f->zr = 0 : 0;
	z = f->tchn < g_i ? g_i : f->tchn;
	(f->min == 1 && f->w < 0) ? f->w = -(f->w) : 0;
	g_ii == 1 || f->plus == 1 || f->space == 1 ? z++ : 0;
	return (z);
}

char		*ft_putnbrn(char *s, t_flags *f)
{
	int		z;
	char	*tmp;
	char	c;

	z = f->tchn;
	c = f->zr == 1 ? '0' : ' ';
	z < g_i ? z = g_i : 0;
	g_ii == 1 || f->plus == 1 || f->space == 1 ? f->w-- : 0;
	tmp = (char *)malloc(sizeof(char) * (f->w - z + 1));
	tmp[(f->w-- - z)] = '\0';
	while ((f->w - z) >= 0)
		tmp[f->w-- - z] = c;
	s = f->min != 1 ? ft_strjoinfree(tmp, s, 3) : ft_strjoinfree(s, tmp, 3);
	(f->zr == 1 && g_ii == 1) ? s[0] = '-' : 0;
	(f->plus == 1 && g_ii != 1 && f->tchn_t != 1 &&\
		(!f->w || f->zr == 1)) ? s[0] = '+' : 0;
	(f->plus != 1 && f->min != 1 && f->space == 1) ? s[0] = ' ' : 0;
	return (s);
}

int			ft_putnbrlln(long long int n, t_flags *f, int fd, int z)
{
	char	*s;

	f->tp == 'D' ? f->mod = 0 : 0;
	f->mod && !ft_strcmp(f->mod, "h") ? n = (short)n : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? n = (char)n : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? n = (long)n : 0;
	(!f->mod && f->tp != 'D') ||\
		(f->mod && !ft_strcmp(f->mod, "L")) ? n = (int)n : 0;
	g_ii = n < 0 ? 1 : 0;
	g_ii == 1 ? n = -n : 0;
	g_i = ft_calc_nbr(n);
	z = ft_d_flags(f);
	if (f->tchn_t == 1 && !f->tchn && n == 0 && !f->w && f->space != 1)
		return (0);
	s = ft_memalloc(1 + z--);
	while (n >= 10)
	{
		s[z--] = (n % 10 + '0');
		n = n / 10;
	}
	s[z--] = (f->tchn_t == 1 && !f->tchn && n == 0 && f->w) ? ' ' : n + '0';
	(g_ii != 1 && f->plus != 1 && f->space != 1) ? s = ft_putzero_s(s, z) : 0;
	(g_ii == 1 || f->plus == 1 || f->space == 1) ? s = ft_putzr_sg(s, z, f) : 0;
	(f->w > f->tchn && f->w > g_i) ? s = ft_putnbrn(s, f) : 0;
	return (ft_printnbr(s, fd));
}

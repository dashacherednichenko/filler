/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:31:51 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 14:31:52 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *g_s = 0;

static char	*ft_srtfinall(char *s, t_flags *f, int i, int d)
{
	char	*tmp;

	tmp = f->zr == 1 ? ft_strtemp(f->w, i, '0') : ft_strtemp(f->w, i, ' ');
	s = f->min == 1 ? ft_strjoinfree(s, tmp, 3) : ft_strjoinfree(tmp, s, 3);
	if (f->tp == 'x' || f->tp == 'X')
		f->resh == 1 && d != 0 && f->zr == 1 ? s[1] = 'X' : 0;
	if (f->tp == 'o' || f->tp == 'O')
		f->resh == 1 && d != 0 && f->zr == 1 ? s[0] = '0' : 0;
	return (s);
}

static char	*ft_strprecis(char *s, t_flags *f, int i, int d)
{
	char	*tmp;

	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ? tmp = ft_strtemp(f->tchn, i, '0') : 0;
	(f->tchn_t == 1 && f->tchn > i) ? s = ft_strjoinfree(tmp, s, 3) : 0;
	f->resh == 1 && d != 0 && !f->zr ? s = ft_strjoinfree("0X", s, 2) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	return (s);
}

int			ft_octal(long long int d, t_flags *f, int i, int fd)
{
	f->mod && !ft_strcmp(f->mod, "h") && f->tp != 'O' ?\
		d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") && f->tp != 'O' ?\
		d = (unsigned char)d : 0;
	!f->mod && f->tp != 'O' ? d = (unsigned)d : 0;
	f->mod && !ft_strcmp(f->mod, "z") ? d = (size_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "j") ? d = (uintmax_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (unsigned long)d : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? d = (unsigned long long)d : 0;
	f->mod && !ft_strcmp(f->mod, "L") ? d = (unsigned int)d : 0;
	g_s = ft_uitoa_base(d, 8);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? g_s[0] = ' ' : 0;
	i = ft_strlen(g_s);
	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ? f->resh = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ?\
		g_s = ft_strjoinfree(ft_strtemp(f->tchn, i, '0'), g_s, 3) : 0;
	f->resh == 1 && !f->zr && f->tchn_t < i && d ?\
		g_s = ft_strjoinfree("0", g_s, 2) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w && !f->resh)
		return (0);
	i = ft_strlen(g_s);
	f->w > i ? g_s = ft_srtfinall(g_s, f, i, d) : 0;
	return (ft_printnbr(g_s, fd));
}

int			ft_unsig(long long int d, t_flags *f, int i, int fd)
{
	char	*s;

	f->tp == 'U' ? f->mod = 0 : 0;
	f->mod && !ft_strcmp(f->mod, "h") ? d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? d = (unsigned char)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (unsigned long)d : 0;
	f->mod && !ft_strcmp(f->mod, "L") ? d = (unsigned int)d : 0;
	(f->mod && !ft_strcmp(f->mod, "ll")) || f->tp == 'U' ?\
		d = (unsigned long long)d : 0;
	f->mod && !ft_strcmp(f->mod, "z") ? d = (size_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "j") ? d = (uintmax_t)d : 0;
	!f->mod && f->tp != 'U' ? d = (unsigned)d : 0;
	s = ft_uitoa_base(d, 10);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? s[0] = ' ' : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w)
		return (0);
	i = ft_strlen(s);
	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ?\
		s = ft_strjoinfree(ft_strtemp(f->tchn, i, '0'), s, 3) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	i = ft_strlen(s);
	f->w > i ? s = ft_srtfinall(s, f, i, d) : 0;
	return (ft_printnbr(s, fd));
}

int			ft_hex(long long int d, t_flags *f, int fd, int i)
{
	d = (unsigned long long)d;
	f->mod && !ft_strcmp(f->mod, "h") ? d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? d = (unsigned char)d : 0;
	f->mod && !ft_strcmp(f->mod, "z") ? d = (size_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "j") ? d = (uintmax_t)d : 0;
	!f->mod || (f->mod && !ft_strcmp(f->mod, "L")) ? d = (unsigned int)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (unsigned long)d : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? d = (unsigned long long)d : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w)
		return (0);
	if (d < 0 && !f->mod)
		g_s = ft_uitoa_base(d, 16);
	else if ((d < 0 && f->mod && (!ft_strcmp(f->mod, "j") ||\
		!ft_strcmp(f->mod, "ll") || !ft_strcmp(f->mod, "l"))))
		g_s = ft_uitoa_base(d, 16);
	else if (f->mod && !ft_strcmp(f->mod, "z"))
		g_s = ft_uitoa_base(d, 16);
	else
		g_s = ft_itoa_base(d, 16);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? g_s[0] = ' ' : 0;
	g_s = ft_strprecis(g_s, f, ft_strlen(g_s), d);
	i = ft_strlen(g_s);
	(f->w > i) ? g_s = ft_srtfinall(g_s, f, i, d) : 0;
	return (ft_printnbr(f->tp == 'X' ? g_s : ft_strlowcase(g_s), fd));
}

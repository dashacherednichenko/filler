/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:19:58 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 16:19:59 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define TP "bcCsSpdDioOuUxXfF%"

int g_fd = 0;
int g_y = 0;

int			ft_pars_tp(va_list ar, t_flags *f, int i, char *s)
{
	f->tp = s[i];
	s[i] == 'c' || s[i] == 'C' ?\
		f->l += ft_putcharn((char)va_arg(ar, int), f, 0, g_fd) : 0;
	s[i] == 's' || s[i] == 'S' ?\
		f->l += ft_puts_n(va_arg(ar, char*), f, 0, g_fd) : 0;
	s[i] == 'p' ? f->l += ft_ptrtype(va_arg(ar, long long int), f, g_fd) : 0;
	s[i] == 'd' || s[i] == 'i' || s[i] == 'D' ? f->l += ft_d(ar, f, g_fd) : 0;
	s[i] == 'b' ? f->l += ft_bin(ar, f, 32, g_fd) : 0;
	s[i] == 'o' || s[i] == 'O' ?\
		f->l += ft_octal(va_arg(ar, long long int), f, 0, g_fd) : 0;
	s[i] == 'u' || s[i] == 'U' ?\
		f->l += ft_unsig(va_arg(ar, long long int), f, 0, g_fd) : 0;
	s[i] == 'X' || s[i] == 'x' ?\
		f->l += ft_hex(va_arg(ar, long long int), f, g_fd, 0) : 0;
	s[i] == 'f' || s[i] == 'F' ? f->l += ft_float(ar, f, g_fd) : 0;
	s[i] == '%' ? f->l += ft_percent('%', f, g_fd) : 0;
	return (f->l);
}

static int	ft_flag_h(t_flags *f, int i, char *s, char c)
{
	if (f->mod && (!ft_strcmp(f->mod, "z") || !ft_strcmp(f->mod, "j")))
		return (i);
	if (s[i + 1] == c)
	{
		if (!f->mod || (!ft_strcmp(f->mod, "h") && !ft_strcmp(f->mod, "l")))
		{
			f->mod = c == 'h' ? "hh" : "ll";
			i++;
		}
	}
	else
		f->mod = c == 'h' ? "h" : "l";
	return (i);
}

static int	ft_nonv(t_flags *f, int i, char *s)
{
	if (!ft_strrchr("*-+ #0123456789.hlLzj", s[i]))
	{
		f->non_v = s[i];
		return (0);
	}
	return (1);
}

int			ft_pars_flag(va_list ar, t_flags *f, int i, char *s)
{
	s[i] == '-' ? f->min = 1 : 0;
	s[i] == ' ' ? f->space = 1 : 0;
	s[i] == '+' ? f->plus = 1 : 0;
	s[i] == '#' ? f->resh = 1 : 0;
	s[i] == '0' && !ft_isdigit(s[i - 1]) ? f->zr = 1 : 0;
	if (s[i] == '*' && f->tchn_t != 1)
	{
		f->w = va_arg(ar, int);
		f->w < 0 ? f->min = 1 : 0;
	}
	s[i] > '0' && s[i] <= '9' ? i = ft_width(s, f, i) : 0;
	s[i] == '.' ? i = ft_precision(s, f, i) : 0;
	if (s[i - 1] == '.' && s[i] == '*' && f->tchn_t == 1)
	{
		f->tchn = va_arg(ar, int);
		(f->tchn < 0) ? f = ft_nultchn(f) : 0;
	}
	s[i] == '#' ? f->resh = 1 : 0;
	s[i] == 'z' ? f->mod = "z" : 0;
	s[i] == 'j' ? f->mod = "j" : 0;
	(s[i] == 'h') ? i = ft_flag_h(f, i, s, 'h') : 0;
	(s[i] == 'l') ? i = ft_flag_h(f, i, s, 'l') : 0;
	s[i] == 'L' ? f->mod = "L" : 0;
	return (i);
}

int			ft_pars(va_list ar, t_flags *f, char *s, int fd)
{
	g_y = 0;
	g_fd = fd;
	while (s[g_y])
	{
		f = ft_obnul_fl(f);
		s[g_y] != '%' && s[g_y] ? g_y = ft_print_txt(s, f, g_y, fd) : 0;
		if (s[g_y] == '%')
		{
			g_y++;
			while (!ft_strrchr(TP, s[g_y]) && s[g_y])
			{
				g_y = ft_pars_flag(ar, f, g_y, s);
				if (ft_nonv(f, g_y, s) == 0)
					break ;
				(!ft_strrchr(TP, s[g_y]) && s[g_y]) ? g_y++ : 0;
			}
			s[g_y] && ft_strrchr(TP, s[g_y]) ?\
				f->l = ft_pars_tp(ar, f, g_y++, s) : 0;
			(f->non_v != 0) ? f->l += ft_putcharn(f->non_v, f, g_y++, fd) : 0;
		}
		s[g_y] != '%' && s[g_y] ? g_y = ft_print_txt(s, f, g_y, fd) : 0;
	}
	return (f->l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:29 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/27 15:32:30 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(char *fmt, ...)
{
	int					i;
	char				*s;
	t_flags				*f;
	va_list				ar;

	va_start(ar, fmt);
	f = (t_flags*)malloc(sizeof(t_flags));
	s = fmt;
	f->l = 0;
	f->l = ft_pars(ar, f, s, 1);
	va_end(ar);
	i = f->l;
	free(f);
	return (i);
}

int			ft_fdprintf(int fd, char *fmt, ...)
{
	int					i;
	char				*s;
	t_flags				*f;
	va_list				ar;

	va_start(ar, fmt);
	f = (t_flags*)malloc(sizeof(t_flags));
	s = fmt;
	f->l = 0;
	f->l = ft_pars(ar, f, s, fd);
	va_end(ar);
	i = f->l;
	free(f);
	return (i);
}

static char	*ft_colorcpy(char *ns, char *s2, int i)
{
	while (*s2)
		ns[i++] = *s2++;
	return (ns);
}

char		*ft_pars_color(char *ns, int i)
{
	while (ns[i])
	{
		if (!ft_strncmp(&ns[i], "C_of", 4))
			ns = ft_colorcpy(ns, "\033[0m", i++);
		else if (!ft_strncmp(&ns[i], "C_BLC", 5))
			ns = ft_colorcpy(ns, "\033[30m", i++);
		else if (!ft_strncmp(&ns[i], "C_RED", 5))
			ns = ft_colorcpy(ns, "\033[31m", i++);
		else if (!ft_strncmp(&ns[i], "C_GRN", 5))
			ns = ft_colorcpy(ns, "\033[32m", i++);
		else if (!ft_strncmp(&ns[i], "C_YLL", 5))
			ns = ft_colorcpy(ns, "\033[33m", i++);
		else if (!ft_strncmp(&ns[i], "C_BLU", 5))
			ns = ft_colorcpy(ns, "\033[34m", i++);
		else if (!ft_strncmp(&ns[i], "C_PUR", 5))
			ns = ft_colorcpy(ns, "\033[35m", i++);
		else if (!ft_strncmp(&ns[i], "C_CYA", 5))
			ns = ft_colorcpy(ns, "\033[36m", i++);
		else if (!ft_strncmp(&ns[i], "C_WHT", 5))
			ns = ft_colorcpy(ns, "\033[37m", i++);
		i++;
	}
	return (ns);
}

int			ft_color_printf(char *fmt, ...)
{
	int					i;
	char				*s;
	char				*ns;
	t_flags				*f;
	va_list				ar;

	va_start(ar, fmt);
	f = (t_flags*)malloc(sizeof(t_flags));
	s = fmt;
	i = 0;
	ns = ft_strdup(s);
	ns = ft_pars_color(ns, i);
	f->l = 0;
	f->l = ft_pars(ar, f, ns, 1);
	va_end(ar);
	free(ns);
	i = f->l;
	free(f);
	return (i);
}

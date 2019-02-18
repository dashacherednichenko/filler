/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:53:08 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/30 16:53:09 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	*ft_nultchn(t_flags *f)
{
	f->tchn = 0;
	f->tchn_t = 0;
	return (f);
}

char	*ft_strtemp(int x, int i, char c)
{
	char *tmp2;

	tmp2 = ft_memalloc(x-- - i + 1);
	while (x - i >= 0)
		tmp2[x-- - i] = c;
	return (tmp2);
}

int		ft_ptrtype(long long int d, t_flags *fl, int fd)
{
	int		i;
	char	*tmp;

	if (d == 0 && fl->tchn_t == 1 && fl->tchn == 0 && fl->w == 0)
		return (ft_puts_n("0x", ft_obnul_fl(fl), 0, fd));
	tmp = ft_strlowcase(ft_itoa_base(d, 16));
	(fl->min == 1) ? fl->zr = 0 : 0;
	if (fl->tchn > (i = ft_strlen(tmp)))
		tmp = ft_strjoinfree(ft_strtemp(fl->tchn, i, '0'), tmp, 3);
	if (fl->zr == 1 && !fl->tchn_t && fl->w > i + 2)
		tmp = ft_strjoinfree(ft_strtemp(fl->w, i + 2, '0'), tmp, 3);
	tmp = ft_strjoinfree("0x", tmp, 2);
	i = ft_strlen(tmp);
	if (fl->w > i && fl->min != 1)
		tmp = ft_strjoinfree(ft_strtemp(fl->w, i, ' '), tmp, 3);
	i = ft_puts_n(tmp, ft_nultchn(fl), 0, fd);
	free(tmp);
	return (i);
}

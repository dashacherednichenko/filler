/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:17:23 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/07 15:25:58 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 3

# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_flags
{
	int				l;
	int				min;
	int				plus;
	int				space;
	int				resh;
	int				zr;
	int				percent;
	long long int	w;
	long long int	tchn;
	int				tchn_t;
	char			*mod;
	char			tp;
	char			non_v;
}					t_flags;
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,\
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_itoa_base(long long int value, int base);
char				*ft_strlowcase(char *str);
size_t				ft_list_size(t_list *begin_list);
t_list				*ft_list_last(t_list *begin_list);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstsplit(char const *s, char c);
int					get_next_line(const int fd, char **line);
int					ft_sqrt(int nb);
int					ft_printf(char *fmt, ...);
int					ft_color_printf(char *fmt, ...);
int					ft_fdprintf(int fd, char *fmt, ...);
int					ft_nb_pass(char *s, int i);
int					ft_print_txt(char *s, t_flags *f, int i, int fd);
int					ft_printnbr(char *s, int fd);
int					ft_precision(char *s, t_flags *f, int i);
int					ft_width(char *s, t_flags *f, int i);
int					ft_pars(va_list ar, t_flags *f, char *s, int fd);
int					ft_pars_tp(va_list ar, t_flags *f, int i, char *s);
int					ft_puts_n(char *str, t_flags *f, int min, int fd);
int					ft_putcharn(char c, t_flags *f, int i, int fd);
int					ft_putnbrll(long long int n, int i);
int					ft_putnbrlln(long long int n, t_flags *f, int fd, int z);
int					ft_putnbrf(va_list ar, t_flags *f, int z, int fd);
int					ft_calc_nbr(long long int d);
int					ft_ptrtype(long long int d, t_flags *f, int fd);
int					ft_d(va_list ar, t_flags *f, int fd);
int					ft_bin(va_list ar, t_flags *f, int j, int fd);
int					ft_percent(char c, t_flags *f, int fd);
int					ft_octal(long long int d, t_flags *f, int i, int fd);
int					ft_unsig(long long int d, t_flags *f, int i, int fd);
int					ft_hex(long long int d, t_flags *f, int fd, int i);
int					ft_float(va_list ar, t_flags *f, int fd);
char				*ft_strjoinfree(char const *s1, char const *s2, int n);
char				*ft_strtemp(int x, int i, char c);
char				*ft_uitoa_base(unsigned long long int value, int base);
char				*ft_itoa_baseld(long double value, int base);
t_flags				*ft_obnul_fl(t_flags *flags);
t_flags				*ft_nultchn(t_flags *f);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfiller.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:58:31 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/18 12:58:35 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILLER_H
#define LIBFILLER_H

typedef struct		s_fill
{
	int				player;
	int 			enemy;
	char 			pl;
	char 			en;
	int 			x;
	int				y;
	int 			**map;
	int 			**piece;
	int				p_x;
	int 			p_y;
}					t_fill;

int					ft_createmap(t_fill *f, char *line);
int 				ft_init_players(t_fill *f, char *line);
int					ft_first_initmap(int fd, int x, t_fill *f, char *line);
int					ft_createpiece(t_fill *f, char *line);
int					ft_init_piece(int fd, int x, t_fill *f, char *line);
int					ft_cut_columns_piece(int fd, t_fill *f);
int					ft_second_initmap(int fd, int x, t_fill *f, char *line);
int					ft_initmap(int fd, t_fill *f);
int 				ft_calc_distance(int fd, int x, int y, t_fill *f);
int 				ft_nbr_modul(int x, int y);
int ft_printpiece(int fd, t_fill *f);

#endif

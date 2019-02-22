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
# define LIBFILLER_H

typedef struct		s_fill
{
	int				player;
	int				enemy;
	char			pl;
	char			en;
	int				x;
	int				y;
	int				**map;
	int				**piece;
	int				p_x;
	int				p_y;
	int				cand_x;
	int				cand_y;
	int				cand_dist;
	int 			p_x_first;
}					t_fill;

int					ft_createmap(t_fill *f, char *line);
int					next_createmap(t_fill *f);
int					ft_init_players(t_fill *f, char *line);
int					ft_first_initmap(int fd, int x, t_fill *f, char *line);
int					ft_createpiece(t_fill *f, char *line);
int					ft_init_piece(int fd, int x, t_fill *f, char *line);
int					ft_cut_columns_piece(int fd, t_fill *f);
int					ft_second_initmap(int fd, int x, t_fill *f, char *line);
int					ft_initmap(int fd, t_fill *f);
int					ft_calc_distance(int fd, int x, int y, t_fill *f);
int					ft_nbr_modul(int x, int y);
int					ft_place_piece(int fd, t_fill *f);
int					ft_printpiece(int fd, t_fill *f);
int					ft_printmap(int fd, t_fill *f);
void				ft_free_map(t_fill *f);
int					ft_obnul_piece(t_fill *f);

#endif

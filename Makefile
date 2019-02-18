#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 15:28:53 by dpiven            #+#    #+#              #
#    Updated: 2018/11/10 16:53:53 by dpiven           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT_OBJ = ./libft/*.o
SRC =	ft_printf.c ft_putnbrf.c\
		ft_putnbrll.c ft_putnbrlln.c ft_putstrn.c ft_retnbr_float.c\
		ft_putcharn.c ft_obnul_flags.c ft_ptr.c ft_strjoinfree.c ft_octal.c\
		ft_declima.c ft_float.c ft_pars.c ft_flags.c ft_percent.c ft_uitoa_base.c ft_binar.c ft_itoa_baseld.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(OBJ)
		@ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

$(LIBFT_OBJ):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C ./libft
	@rm -f *.o

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all


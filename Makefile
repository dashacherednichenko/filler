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

NAME = dpiven.filler

SRC = main.c ft_createmap.c ft_init_players.c ft_nbr_modul.c ft_place_piece.c ft_print_filler.c ft_free.c

LIB = @make -C libft/

all: $(NAME)

$(NAME):
	$(LIB)
#	@gcc -o $(NAME) $(SRC) ./libft/libft.a -I./ -I./libft/
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) ./libft/libft.a -I./ -I./libft/

clean:
	@$(LIB) clean

fclean: clean
	@$(LIB) fclean
	@rm -f $(NAME)
	@rm -f *.c~
	@rm -f *~

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epalomak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 18:24:17 by epalomak          #+#    #+#              #
#    Updated: 2019/12/11 15:54:52 by epalomak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c get_next_line.c ft_list.c ft_build_map.c ft_solver.c \
	ft_check_and_form.c

OBJ = main.o get_next_line.o ft_list.o ft_backtracker.o ft_solver.o

FLAGS = -Wall -Wextra -Werror -I./fillit

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "READY TO GO!"

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "cleaned"

re:	fclean all

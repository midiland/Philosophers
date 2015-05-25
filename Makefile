# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 15:21:48 by apantiez          #+#    #+#              #
#    Updated: 2015/05/25 09:00:43 by apantiez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT = -L ./libft -lft -I ./libft

SRC =	srcs/main.c \

OBJ = $(SRC:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFT) -I ./includes
	@echo "[\033[33;32mCompilation \033[33;34m$(NAME) \
		\033[33;32mok\033[33;0m]"

linux: fclean
	@$(CC) -c $(CFLAGS) -I ./includes $< -o $@ -lpthread
	@make -C ./libft
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFT) -I ./includes -lpthread



%.o : %.c
	@$(CC) -c $(CFLAGS) -I ./includes $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "[\033[33;31mSupression des .o de \033[33;34m$(NAME) \
			\033[33;32mok\033[33;0m]"

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)
	@echo "[\033[33;31mSupression de \033[33;34m$(NAME) \
	\033[33;32mok\033[33;0m]"

re : fclean all



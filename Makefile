# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 15:21:48 by apantiez          #+#    #+#              #
#    Updated: 2015/05/30 15:11:22 by apantiez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LINK_FLAG = -L libft -lft -L glfw/src -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

CFLAGS = -Wall -Wextra -Werror

LIBFT = -L ./libft -lft -I ./libft

SRC =	srcs/newmain.c \
		srcs/time.c \
		srcs/stick.c \
		srcs/thread.c \

OBJ = $(SRC:.c=.o)

LIB_GLFW =glfw/src/libglfw3.a

NAME = philo

all: $(NAME)

$(LIB_GLFW):
	git submodule init
	git submodule update
	cd glfw && cmake .
	make -C glfw

$(NAME): $(LIB_GLFW) $(OBJ)
	@make -C ./libft
	@$(CC) -o $(NAME) $(OBJ) -I ./includes $(LIB_COMP) $(LINK_FLAG)
	@echo "[\033[33;32mCompilation \033[33;34m$(NAME) \
		\033[33;32mok\033[33;0m]"

linux: $(OBJ)
	@make -C ./libft
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFT) -I ./includes -lpthread



%.o : %.c
	@$(CC) -c $(CFLAGS) -I ./includes $< -o $@ -g

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

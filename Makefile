# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 19:11:18 by armaxima          #+#    #+#              #
#    Updated: 2021/11/22 15:26:56 by armaxima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -MMD -Wall -Wextra -Werror

NAME = so_long

NAME_BON = so_long_bonus

SRC = src/ft_check.c \
	src/ft_print.c \
	src/ft_split.c \
	src/ft_utils.c \
	src/main.c \
	src/ft_mlx.c \
	src/ft_create_window.c \
	src/ft_create_location.c \
	src/ft_free_mlx.c \
	src/ft_move.c \
	src/ft_close.c \
	src/ft_error.c \
	src/ft_free_game.c \
	src/ft_patrol.c

SRC_BON = src_bonus/ft_check_bonus.c \
	src_bonus/ft_print_bonus.c \
	src_bonus/ft_split_bonus.c \
	src_bonus/ft_utils_bonus.c \
	src_bonus/main_bonus.c \
	src_bonus/ft_mlx_bonus.c \
	src_bonus/ft_create_window_bonus.c \
	src_bonus/ft_create_location_bonus.c \
	src_bonus/ft_free_mlx_bonus.c \
	src_bonus/ft_move_bonus.c \
	src_bonus/ft_close_bonus.c \
	src_bonus/ft_error_bonus.c \
	src_bonus/ft_free_game_bonus.c \
	src_bonus/ft_patrol_bonus.c

HEADER = ./include/so_long.h

HEADER_BON = ./include_bonus/so_long_bonus.h

HEADER_M = ./minilibx_opengl_20191021

OBJ = $(SRC:.c=.o)

OBJ_BON = $(SRC_BON:.c=.o)

SRC_D = $(SRC:.c=.d)

SRC_D_BON = $(SRC_BON:.c=.d)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER_M)

all: $(NAME)

bonus: $(NAME_BON)

$(NAME): $(OBJ) $(HEADER) $(HEADER_M)
	make -C minilibx_opengl_20191021/
	gcc $(FLAG) $(OBJ) -o $(NAME) -I includes -L minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit -lz

$(NAME_BON): $(OBJ_BON) $(HEADER_BON) $(HEADER_M)
	make -C minilibx_opengl_20191021/
	gcc $(FLAG) $(OBJ_BON) -o $(NAME_BON) -I includes -L minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit -lz

clean:
	rm -f $(OBJ) $(SRC_D) $(OBJ_BON) $(SRC_D_BON)

fclean: clean
	rm -f $(NAME) $(NAME_BON)

re: fclean all

.PHONY: all, clean, fclean, re

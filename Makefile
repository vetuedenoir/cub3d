# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 12:36:43 by kvisouth          #+#    #+#              #
#    Updated: 2024/01/08 18:03:57 by kscordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	main.c \
		parsing/parsing_main.c \
		parsing/argument.c \
		parsing/elem_info.c \
		parsing/elem_utils.c \
		parsing/elem_rgb.c \
		parsing/utils.c \
		parsing/paths.c \
		parsing/map.c \
		parsing/map_utils.c \
		parsing/map_utils2.c \
		parsing/check_map.c \
		parsing/check_player.c \
		hook_move_perso.c \
		clean_all.c \
		put_pixel.c \
		exec.c \
		raycasting2d.c \
		forme_geometrique.c \
		minimap.c \
		raycasting.c \
		rotate_player.c \
		randering.c

OBJS = $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
OBJ_DIR = obj/

includes = inc/defines.h inc/cub3d.h inc/structs.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -o3 #-g3
libft = libft/libft.a
minilibx = minilibx-linux/libmlx_Linux.a 

all: $(NAME)

$(NAME): $(OBJS) | $(libft) $(minilibx)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft -L minilibx-linux -lmlx -lXext -lX11 -lm

$(libft): 
	make -j -C ./libft

$(minilibx) :
	@make -j -C ./minilibx-linux

$(OBJ_DIR)%.o: src/%.c $(includes) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: src/parsing/%.c $(includes) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@make -j -C libft clean
	@make -j -C minilibx-linux clean
	rm -rf obj

fclean: clean
	@make -j -C libft fclean
	rm -f $(NAME)

re: fclean vitesse

vitesse:
	make -j -C .

.PHONY: all clean fclean re vitesse

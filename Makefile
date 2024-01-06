# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 12:36:43 by kvisouth          #+#    #+#              #
#    Updated: 2024/01/05 16:20:31 by kscordel         ###   ########.fr        #
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
		raycasting.c
		

OBJS = $(addprefix obj/, $(notdir $(SRCS:.c=.o)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_MAKEFILE = libft/Makefile
MINILIBX_MAKEFILE = minilibx-linux/Makefile

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft -L minilibx-linux -lmlx -lXext -lX11 -lm

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/parsing/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@make -C minilibx-linux clean
	@rm -rf obj

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

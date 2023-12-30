# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 12:36:43 by kvisouth          #+#    #+#              #
#    Updated: 2023/12/05 13:22:03 by kscordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	main.c \
		parsing/parsing_main.c \
		parsing/argument.c \
		parsing/utils.c \
		parsing/paths.c \
		hook.c \
		clean_all.c \
		put_pixel.c \
		exec.c \
		raycasting.c \
		forme_geometrique.c \
		minimap.c
		

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
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/parsing/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@make -C minilibx-linux clean
	rm -rf obj

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

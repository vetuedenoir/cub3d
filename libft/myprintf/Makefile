# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kscordel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 17:47:39 by kscordel          #+#    #+#              #
#    Updated: 2023/04/17 14:30:12 by kscordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = ft_printf \
	puts \
	

OBJ = $(addsuffix .o, ${SRC})
CC = cc 
HEADER = .
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft/
	
all: $(NAME)

%.o:%.c
	$(CC) -c $(FLAGS) $< -o $@ -I${HEADER}

$(NAME): ${LIBFT_DIR}libft.a ${OBJ}
		cp ${LIBFT_DIR}libft.a ./${NAME}
		ar rcs ${NAME} ${OBJ}
		
clean:
		rm -f ${OBJ}

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

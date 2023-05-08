# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 16:48:04 by tpetros           #+#    #+#              #
#    Updated: 2023/05/08 16:48:07 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_FILES = src/fractol.c 

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra
LINKER = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJS = ${SRC_FILES:.c=.o}

$(NAME): ${OBJS}
	@${MAKE} -C mlx
	${CC} ${CFLAGS} ${OBJS} ${LINKER} -o ${NAME}

all: ${NAME}

clean:
	cd ./mlx/ && make clean
	${RM} ${OBJS}

fclean: clean
	cd ./mlx/ && make clean
	${RM} ${NAME}

re:	fclean all
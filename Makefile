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

SRC_FILES = src/fractol.c \
			src/mandelbrot.c \

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra
LINKER = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJS = ${SRC_FILES:.c=.o}

$(NAME): ${OBJS}
	@${MAKE} -C mlx
	cd ./includes/libft/ && make
	${CC} ${CFLAGS} ${OBJS} ${LINKER} ./includes/libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all
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
$(VERBOSE).SILENT:

NAME = fractol

SRC_FILES = src/fractol.c \
			src/fractol_utils.c \
			src/ft_common.c \
			src/ft_init.c \
			src/mandelbrot.c \
			src/events.c \
			src/julia.c \

CC = gcc
RM = rm -rf

MLXMAC     := ./mlx/
MLXLINUX   := ./mlx_linux/

CFLAGS 		:= -Wall -Werror -Wextra
MacLinker 	:= -Lmlx -lmlx -framework OpenGL -framework AppKit
LinuxLink 	:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Iincludes/mlx_linux -lXext -lX11 -lm -lz

OS := $(shell uname)

ifeq ($(OS),Darwin)
	MLX     = $(MLXMAC)
	LINKER  = $(MacLinker)
else ifeq ($(OS),Linux)
	MLX     = $(MLXLINUX)
	LINKER  = $(LinuxLink)
else
	LINKER  =
endif

OBJS = ${SRC_FILES:.c=.o}

$(NAME): ${OBJS}
	@echo "Compiling and Linking MLX"
	@$(MAKE) -C $(MLX) 2>/dev/null
	@cd ./includes/libft/ && make
	${CC} ${CFLAGS} ${OBJS} ${LINKER} ./includes/libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	@cd ./includes/libft/ && make clean
	@make clean -sC $(MLX)
	${RM} ${OBJS}

fclean: clean
	@cd ./includes/libft/ && make fclean
	${RM} ${NAME}

re:	fclean all
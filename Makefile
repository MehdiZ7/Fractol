# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 18:36:18 by mzouhir           #+#    #+#              #
#    Updated: 2025/12/23 15:38:14 by mzouhir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = main.c create_window.c parsing.c create_fractal.c math_utils.c events.c create_julia.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
MLX_DIR = minilibx-linux
MLX = ${MLX_DIR}/libmlx_Linux.a
INCLUDES = -I${LIBFT_DIR} -I${MLX_DIR} -Iincludes
MLX_FLAGS = -lXext -lX11 -lm

all: ${LIBFT} ${MLX} ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${MLX}:
	${MAKE} -C ${MLX_DIR}

${NAME}: ${OBJS} ${LIBFT} ${MLX}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} ${MLX_FLAGS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	rm -f ${OBJS}
	${MAKE} -C ${LIBFT_DIR} clean
	${MAKE} -C ${MLX_DIR} clean

fclean: clean
	rm -f ${NAME}
	${MAKE} -C ${LIBFT_DIR} fclean
	${MAKE} -C ${MLX_DIR} clean

re: fclean all

.PHONY: all clean fclean re



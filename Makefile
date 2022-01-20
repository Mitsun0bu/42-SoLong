# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:29:22 by llethuil          #+#    #+#              #
#    Updated: 2022/01/13 17:22:18 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_AR =	./libft/libft.a				\

MLX_AR =	./mlx/libmlx.a				\

INCS =		./includes/so_long.h		\

SRCS =		./srcs/add_textures_1.c		\
			./srcs/add_textures_2.c		\
			./srcs/events.c				\
			./srcs/get_map.c			\
			./srcs/get_player.c			\
			./srcs/get_sprites.c		\
			./srcs/get_window.c			\
			./srcs/main.c				\
			./srcs/move_player.c		\
			./srcs/parse_map.c			\
			./srcs/randomize_field.c	\
			./srcs/utils.c				\

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I mlx

RM = rm -f

all : libft mlx ${NAME}

libft :
	make -C ./libft

mlx :
	make -C ./mlx

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT_AR} ${MLX_AR}
	${CC} ${OBJS} ${LIBFT_AR} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C ./libft
	make clean -C ./mlx

fclean: clean
	${RM} ${LIBFT_AR}
	${RM} ${MLX_AR}
	${RM} ${NAME}

re: fclean all

.PHONY: all libft mlx clean fclean re
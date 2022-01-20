# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 14:36:18 by llethuil          #+#    #+#              #
#    Updated: 2021/12/15 15:08:52 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

INCS = libft.h

SRCS = ft_atoi.c			\
	   ft_bzero.c			\
	   ft_calloc.c			\
	   ft_get_next_line.c	\
	   ft_isalnum.c			\
	   ft_isalpha.c			\
	   ft_isascii.c			\
	   ft_isdigit.c			\
	   ft_isprint.c			\
	   ft_itoa.c			\
	   ft_lstadd_back.c		\
	   ft_lstadd_front.c	\
	   ft_lstclear.c		\
	   ft_lstdelone.c		\
	   ft_lstiter.c			\
	   ft_lstlast.c			\
	   ft_lstmap.c			\
	   ft_lstnew.c			\
	   ft_lstsize.c			\
	   ft_memchr.c			\
	   ft_memcmp.c			\
	   ft_memcpy.c			\
	   ft_memmove.c			\
	   ft_memset.c			\
	   ft_putchar_fd.c		\
	   ft_putendl_fd.c		\
	   ft_putnbr_fd.c		\
	   ft_putstr_fd.c		\
	   ft_split.c			\
	   ft_strchr.c			\
	   ft_strdup.c			\
	   ft_striteri.c		\
	   ft_strjoin.c			\
	   ft_strlcat.c			\
	   ft_strlcpy.c			\
	   ft_strlen.c			\
	   ft_strmapi.c			\
	   ft_strncmp.c			\
	   ft_strnstr.c			\
	   ft_strrchr.c			\
	   ft_strtrim.c			\
	   ft_substr.c			\
	   ft_tolower.c			\
	   ft_toupper.c			\

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I ${INCS}

NAME = libft.a

all: ${NAME}

%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar rcs $@ ${OBJS}

bonus: all

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

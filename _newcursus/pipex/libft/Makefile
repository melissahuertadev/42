# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 02:31:48 by mhuerta           #+#    #+#              #
#    Updated: 2021/10/18 14:08:37 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# Variables section starts here #

NAME = libft.a

SRCS = ft_putstr_fd.c ft_putchar_fd.c ft_split.c ft_countwords.c ft_strjoin.c\
	ft_strlen.c ft_strcat.c ft_strcpy.c ft_strnstr.c

OBJS = $(SRCS:.c=.o)
HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra
CC = gcc

# Rules section starts here #

all: $(NAME)
	@echo	libft has been compiled

$(NAME): $(HEADER) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f libft.a

fclean: clean
	@rm -f $(NAME)

re: fclean all

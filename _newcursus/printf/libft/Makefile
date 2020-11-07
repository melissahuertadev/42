# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 02:31:48 by mhuerta           #+#    #+#              #
#    Updated: 2020/11/06 21:40:51 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# Variables section starts here #

NAME = libft.a

SRCS = ft_putchar.c ft_putstr.c ft_strlen.c ft_isdigit.c ft_strsub.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc


# Rules section starts here #

all: $(NAME)
	@echo	libft has been compiled

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

compile:
	@$(CC) main.c -L. -lft
	@echo	main compiled

clean:
	@rm -f *.o
	@rm -f libft.a

fclean: clean
	@rm -f $(NAME)

re: fclean all

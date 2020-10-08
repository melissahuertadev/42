# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 02:31:48 by mhuerta           #+#    #+#              #
#    Updated: 2020/10/07 19:40:11 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# Variables section starts here #

NAME = libft.a

SRCS = *.c

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
	@rm -f *.a

fclean: clean
	@rm -f $(NAME)

re: fclean all

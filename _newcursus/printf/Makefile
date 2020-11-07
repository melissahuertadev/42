# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 18:18:58 by mhuerta           #+#    #+#              #
#    Updated: 2020/11/07 13:27:42 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#gcc -Wno-nullability-completeness

.PHONY: all clean fclean re

# Variables section starts here #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_fields.c ft_printf_text.c ft_printf_numbers.c ft_helpers.c libft/*.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

# Rules section starts here #

all: $(NAME)
	@echo	libftprintf has been compiled

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

compile: re
	@$(CC) main.c -L. -lftprintf libft/libft.a
	@echo	main compiled

clean:
	@rm -f *.o
	@rm -f libftprintf.a

fclean: clean
	@rm -f $(NAME)

re: fclean all
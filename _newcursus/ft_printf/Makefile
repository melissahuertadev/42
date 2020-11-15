# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 18:18:58 by mhuerta           #+#    #+#              #
#    Updated: 2020/11/10 02:22:50 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#gcc -Wno-nullability-completeness

.PHONY: all clean fclean re

# Variables section starts here #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_fields.c ft_printf_text.c ft_printf_decimal.c \
		 ft_printf_unsigned.c ft_helpers.c ft_printf_ptr.c libft/*.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

# Rules section starts here #

all: $(NAME)
	@echo	libftprintf has been compiled

$(NAME):
	@make re -C ./libft
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS) ./libft/*.o
	@ranlib $(NAME)

compile: re
	@$(CC) main.c -L. -lftprintf libft/libft.a
	@echo	main compiled

clean:
	@rm -f *.o
	@rm -f libftprintf.a
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)

re: fclean all
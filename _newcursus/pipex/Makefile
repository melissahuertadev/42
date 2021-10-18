# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 00:25:28 by mhuerta           #+#    #+#              #
#    Updated: 2021/10/18 14:08:50 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = pipex

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

H_DIR = includes/
SRCS_DIR = srcs/
OBJS_DIR = objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
SRCS = pipex.c \
	execute.c


all: $(NAME)
	@echo	pipex has been compiled

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L ./libft -lft

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) -I libft/libft.h -I $(H_DIR) -c $< -o $@

clean:
	@rm -f libft/*.o
	@rm -rf $(OBJS_DIR)
	@echo	clean performed

fclean: clean
	@rm -f libft/libft.a
	@rm -f $(NAME)
	@echo	fclean performed

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuerta <mhuerta@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 00:25:28 by mhuerta           #+#    #+#              #
#    Updated: 2021/10/18 01:48:09 by mhuerta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# Variables section starts here #

NAME = pipex

SRCS_FILES = srcs/pipex.c srcs/execute.c
SRCS_PATH = srcs/
H_FILES = pipex.h
H_PATH = includes/
LIBFT = libft/libft.a

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILE))
OBJS = $(SRCS:.c=.o)
HEADER = $(addprefix $(H_PATH), $(H_FILES))

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

# Rules section starts here #

all: $(NAME)
	@echo	pipex has been compiled

$(NAME): $(HEADER) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -I $(H_PATH) -c srcs/main.c -o srcs/main.o
	@$(CC) $(CFLAGS) -I $(H_PATH) $(OBJS) -L ./libft -lft -o $(NAME)

$(LIBFT) : 
	@make -C ./libft/

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(H_PATH) -c $< -o $@
	
clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@echo	clean performed

fclean: clean
	@rm -f $(OBJS) $(NAME)
	@make fclean -C ./libft
	@echo	fclean performed

re: fclean all

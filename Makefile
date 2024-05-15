# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 14:21:29 by gmalyana          #+#    #+#              #
#    Updated: 2024/05/14 21:22:52 by gmalyana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = $(shell find src -type f -name "*.c" | tr '\n' ' ')
OBJS = $(SOURCES:.c=.o)
LIB_DIR = lib/libft/
LIBFT = $(LIB_DIR)libft.a
CFLAGS = #-Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT) -o $(NAME)

%.o:%.c push_swap.h
	cc $(CFLAGS) -c $<

$(LIBFT) :
	@make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean 
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

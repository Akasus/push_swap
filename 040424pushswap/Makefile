# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 01:06:37 by lbaumeis          #+#    #+#              #
#    Updated: 2024/04/04 19:05:50 by lbaumeis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIB_FLAGS = -L. -lft

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = push_swap.c control.c libps.c main.c
OFILES = $(CFILES:.c=.o)
P_NAME = push_swap

all: $(P_NAME)

$(P_NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_FLAGS)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(P_NAME)
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 19:56:56 by skhastag          #+#    #+#              #
#    Updated: 2024/07/30 06:57:36 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ZombieHorde

CFLAGS = -Wall -Wextra -Werror

CC = g++

STD = -std=c++98

SRCS = main.cpp Zombie.cpp ZombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re fclean test

test: fclean all
	./$(NAME) 10

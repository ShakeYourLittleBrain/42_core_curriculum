# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 02:41:21 by skhastag          #+#    #+#              #
#    Updated: 2024/08/07 02:13:02 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain

CC = g++

CFLAGS = -Wall -Wextra -Werror

STD = -std=c++98

SRC = main.cpp Dog.cpp Cat.cpp Brain.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(STD) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

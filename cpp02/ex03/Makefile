# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 03:13:53 by skhastag          #+#    #+#              #
#    Updated: 2024/08/02 06:22:28 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bsp

CC = g++

STD = -std=c++98

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp Fixed.cpp Point.cpp Bsp.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(STD) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

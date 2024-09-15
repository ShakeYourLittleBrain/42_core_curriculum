# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 03:13:53 by skhastag          #+#    #+#              #
#    Updated: 2024/08/01 03:15:16 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

CC = g++

STD = -std=c++98

CFLAGS = -Wall -Wextra -Werror

SRC = Fixed.cpp main.cpp

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

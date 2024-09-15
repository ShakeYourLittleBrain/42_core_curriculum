# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 19:51:27 by skhastag          #+#    #+#              #
#    Updated: 2024/07/30 19:52:57 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl

CC = g++

STD = -std=c++98

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(STD) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test

test: fclean all
	./$(NAME)

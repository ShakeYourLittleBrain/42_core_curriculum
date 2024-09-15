# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 05:06:41 by skhastag          #+#    #+#              #
#    Updated: 2024/07/30 06:44:53 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Repalce

CC = g++

CFLAGS = -Wall -Wextra -Werror

STD = -std=c++98

SRCS = main.cpp SedForWinners.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf *txt.*

re: fclean all

.PHONY: all clean fclean re test

S1 = aliquet

S2 = "'Sed is for winners'"

FILENAME = test.txt

test: fclean all
	./$(NAME) $(FILENAME) $(S1) $(S2)



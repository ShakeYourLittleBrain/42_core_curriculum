# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 23:45:49 by skhastag          #+#    #+#              #
#    Updated: 2024/07/30 04:24:34 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

RM = rm -f

SRCS = main.cpp Zombie.cpp NewZombie.cpp RandomChump.cpp

STD = -std=c++98

CC = g++

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

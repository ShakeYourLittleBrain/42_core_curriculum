# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 06:21:55 by skhastag          #+#    #+#              #
#    Updated: 2024/08/13 07:06:19 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form

STD = -std=c++98

CC = g++

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp Bureaucrat.cpp Form.cpp GradeTooHighException.cpp GradeTooLowException.cpp

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

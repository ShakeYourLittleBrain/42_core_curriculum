# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 06:21:55 by skhastag          #+#    #+#              #
#    Updated: 2024/09/01 13:34:25 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm

STD = -std=c++98

CC = g++

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp Bureaucrat.cpp AForm.cpp GradeTooHighException.cpp GradeTooLowException.cpp IsNotSignedException.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(STD) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

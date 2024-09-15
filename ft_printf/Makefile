# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 14:00:27 by skhastag          #+#    #+#              #
#    Updated: 2024/03/23 12:22:37 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wextra -Wall -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ft_get_formated_str.c ft_putaddress.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_strchr.c ft_putnbr_fd.c ft_putnbr_base.c ft_putunsigned.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

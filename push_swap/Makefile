# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 18:59:34 by skhastag          #+#    #+#              #
#    Updated: 2024/07/14 18:55:16 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS = push_swap.c push_swap_utils.c push_swap_stack_utils.c push_swap_stack_init.c push_swap_sort_main.c \
		push_swap_sort_main_utils.c push_swap_sort_3.c push_swap_init_b2a.c push_swap_init_a2b.c \
		op_swap.c op_rotate.c op_rev_rotate.c op_push.c error_input.c ft_atoi.c ft_split.c

OBJS = $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus

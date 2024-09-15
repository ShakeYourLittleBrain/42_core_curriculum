# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 04:05:27 by skhastag          #+#    #+#              #
#    Updated: 2024/04/26 05:59:12 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = ./library/libft/libft.a
HEADERS = ./include/
SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
CFLAGS = -Werror -Wall -Wextra -g -I
RM = rm -rf


SRC_FILES=	$(SRC_DIR)pipex.c \
			$(SRC_DIR)pipex_utils.c \

SRCS=	$(SRC_FILES)

OBJS=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
		@make all

$(LIBFT):
		@make -sC ./library/libft

all : 	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean :
		@$(RM) $(OBJ_DIR)
		@make clean -sC ./library/libft
		@$(RM) .cache_exists

fclean : 	clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)


re : fclean all

# Phony targets
.PHONY: start all clean fclean re

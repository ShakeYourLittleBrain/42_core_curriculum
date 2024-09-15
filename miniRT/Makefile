# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/07 02:24:15 by skhastag          #+#    #+#              #
#    Updated: 2024/07/24 21:53:58 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors / base 16 / Bright
GREEN := \033[32;1m
RESET := \033[0m

# Colors / Perso / Bright
ORANGE = \033[38;5;214m

# MLX_42
MLX_DIR = ./library/MLX_42/
MLX_NAME = libmlx42.a
MLX = $(MLX_DIR)$(MLX_NAME)

# Libft
LIBFT_DIR = ./library/libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

# Project settings
NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -mavx -Ofast
RM = rm -f
INCLUDE = -I ./include \
          -I ./library/libft/ \
          -I ./library/MLX_42/

# Root directories
SRC_DIR = src
OBJ_DIR = obj

# It Finds all the source files in the $(SRC_DIR) and it's (subdirectories) as it is
SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')

# Generate the corresponding object files in the obj directory with the same tree structure
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Targets
all: $(MLX) $(LIBFT) $(NAME)

install_brew:
	@echo "----- installing brew -----"
	rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew && \
	git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && \
	echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc && \
	source $HOME/.zshrc && brew update

install_glfw:
	@echo "----- installing glfw -----"
	brew install glfw

install: install_brew install_glfw

$(MLX):
#					@echo "Getting MlX ready"
					@make -sC $(MLX_DIR)

$(LIBFT):
#					@echo "Getting libft ready"
					@make -sC $(LIBFT_DIR)

# Rule for linking the object files to create the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX) $(LIBFT) $(INCLUDE) -ldl -lglfw -pthread -lm

# Rule for compiling source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) && printf "$(GREEN)Compiling: $(RESET)$(notdir $<)...\n"

clean:
					@echo "Removing object files"
					@rm -rf $(OBJ_DIR)
					@make clean -sC $(MLX_DIR)
					@make clean -sC $(LIBFT_DIR)
					@$(RM) $(NAME).dSYM

fclean:			clean
					@echo "Removing miniRT..."
					@rm -f $(NAME)
					@rm -f $(LIBFT)
					@rm -f $(MLX)

re:				fclean all
					@echo "$(BLUE)Cleaned and rebuilt everything for miniRT$(DEF_COLOR)"

.PHONY: all re clean fclean install_brew install_glfw install

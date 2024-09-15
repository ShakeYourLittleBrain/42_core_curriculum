# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 00:58:23 by skhastag          #+#    #+#              #
#    Updated: 2024/05/06 22:48:58 by skhastag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors / base 16 / Bright


DEF_COLOR		= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

#Colors / Perso / Bright

ORANGE			= \033[38;5;214m

#MLX_42

MLX_DIR			= ./library/MLX_42/
MLX_NAME		= libmlx42.a
MLX				= $(MLX_DIR)$(MLX_NAME)

#Libft

LIBFT_DIR		= ./library/libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)

#Variables

NAME			= fractol
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -ldl -lglfw -pthread -lm -g
RM				= rm -f
AR				= ar rcs
INCLUDE			= 	-I ./include \
					-I ./library/libft/ \
					-I ./library/MLX_42/

#Sources

OBJ_DIR_F 			= obj/
SRC_DIR_F			= src/
SRC_EVENTS_DIR		= events/
SRC_FRACTALS_DIR	= fractals/
SRC_COLORS_DIR		= colors/
SRC_UTILS_DIR		= utils/
SRC_FUNCTIONS_M	= $(SRC_DIR_F)fractol_main.c
SRC_FUNCTIONS_F	= $(SRC_DIR_F)$(SRC_FRACTALS_DIR)fractol_jul_prep.c \
				  $(SRC_DIR_F)$(SRC_FRACTALS_DIR)fractol_man_prep.c \
				  $(SRC_DIR_F)$(SRC_FRACTALS_DIR)fractol_tric_prep.c
SRC_FUNCTIONS_E = $(SRC_DIR_F)$(SRC_EVENTS_DIR)events_handler.c \
				  $(SRC_DIR_F)$(SRC_EVENTS_DIR)fractol_hook_utils.c
SRC_FUNCTIONS_C = $(SRC_DIR_F)$(SRC_COLORS_DIR)fractol_color.c
SRC_FUNCTIONS_U = $(SRC_DIR_F)$(SRC_UTILS_DIR)ft_utils.c

#Sources path

SRC_FRACTALS_DIR_PATH =$(SRC_DIR_F)$(SRC_FRACTALS_DIR)
SRC_EVENTS_DIR_PATH =$(SRC_DIR_F)$(SRC_EVENTS_DIR)
SRC_COLORS_DIR_PATH =$(SRC_DIR_F)$(SRC_COLORS_DIR)
SRC_UTILS_DIR_PATH =$(SRC_DIR_F)$(SRC_UTILS_DIR)

#objects sources path

OBJ_FRACTALS_DIR_PATH =$(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_FRACTALS_DIR)
OBJ_EVENTS_DIR_PATH =$(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_EVENTS_DIR)
OBJ_COLORS_DIR_PATH =$(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_COLORS_DIR)
OBJ_UTILS_DIR_PATH =$(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_UTILS_DIR)

#FRACT_SRC		= $(SRC_FUNCTIONS_F)
FRACT_OBJ		= $(patsubst $(SRC_DIR_F)%.c,$(OBJ_DIR_F)%.o,$(SRC_FUNCTIONS_M))
FRACT_OBJ_F		= $(patsubst $(SRC_FRACTALS_DIR_PATH)%.c,$(OBJ_FRACTALS_DIR_PATH)%.o,$(SRC_FUNCTIONS_F))
FRACT_OBJ_E		= $(patsubst $(SRC_EVENTS_DIR_PATH)%.c,$(OBJ_EVENTS_DIR_PATH)%.o,$(SRC_FUNCTIONS_E))
FRACT_OBJ_C		= $(patsubst $(SRC_COLORS_DIR_PATH)%.c,$(OBJ_COLORS_DIR_PATH)%.o,$(SRC_FUNCTIONS_C))
FRACT_OBJ_U		= $(patsubst $(SRC_UTILS_DIR_PATH)%.c,$(OBJ_UTILS_DIR_PATH)%.o,$(SRC_FUNCTIONS_U))

IFMAKE_DIR_F	= .cache_exists

#instructions

all:	$(MLX) $(LIBFT) $(IFMAKE_DIR_F) $(NAME)

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

$(IFMAKE_DIR_F):
					@mkdir -p $(OBJ_DIR_F)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_EVENTS_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_FRACTALS_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_COLORS_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_UTILS_DIR)

$(MLX):
					@echo "Getting MlX ready"
					@make -sC $(MLX_DIR)

$(LIBFT):
					@echo "Getting libft ready"
					@make -sC $(LIBFT_DIR)

$(NAME): $(FRACT_OBJ) $(FRACT_OBJ_F) $(FRACT_OBJ_E) $(FRACT_OBJ_C) $(FRACT_OBJ_U) $(MLX) $(LIBFT)
					@echo "Compiling fractol..."
					@$(CC) $(CFLAGS) -o $(NAME) $(FRACT_OBJ) $(FRACT_OBJ_F) $(FRACT_OBJ_E) $(FRACT_OBJ_C) $(FRACT_OBJ_U) $(MLX) $(LIBFT) $(INCLUDE)
					@echo "Fractol ready."

$(OBJ_DIR_F)%.o: $(SRC_DIR_F)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_FRACTALS_DIR_PATH)%.o: $(SRC_FRACTALS_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_EVENTS_DIR_PATH)%.o: $(SRC_EVENTS_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_COLORS_DIR_PATH)%.o: $(SRC_COLORS_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_UTILS_DIR_PATH)%.o: $(SRC_UTILS_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
					@echo "Removing object files"
					@rm -rf $(OBJ_DIR_F)
					@make clean -C $(MLX_DIR)
					@make clean -C $(LIBFT_DIR)

fclean:			clean
					@echo "Removing fractol..."
					@rm -f $(NAME)
					@rm -f $(LIBFT)
					@rm -f $(MLX)

re:				fclean all
					@echo "$(BLUE)Cleaned and rebuilt everything for fractol$(DEF_COLOR)"

.PHONY: all re clean fclean

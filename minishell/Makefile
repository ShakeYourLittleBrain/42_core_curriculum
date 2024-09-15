# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 03:15:17 by skhastag          #+#    #+#              #
#    Updated: 2024/06/16 20:54:25 by skhastag         ###   ########.fr        #
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
ORANGE			= \033[38;5;214m

#Libft
LIBFT_DIR		= ./library/libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)

#Variables
NAME			= minishell
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -rf
AR				= ar rcs
INCLUDE			= 	-I ./include \
					-I ./library/libft/ \

#Sources dir
OBJ_DIR_F 			= obj/
SRC_DIR_F			= src/
SRC_DEBUG_DIR		= debug/
SRC_UTILS_DIR		= utils/
SRC_PARSER_DIR		= parser/
SRC_PARSER_UT_DIR	= $(SRC_PARSER_DIR)$(SRC_UTILS_DIR)
SRC_TERMINAL_DIR	= terminal/
SRC_EXE_DIR			= execution/
SRC_BUILDIN		 	= buildin/
SRC_EXECUTE			= execute/
SRC_SIGNAL_DIR		= signal/
SRC_BUILDIN_DIR		= $(SRC_EXE_DIR)$(SRC_BUILDIN)
SRC_EXECUTE_DIR 	= $(SRC_EXE_DIR)$(SRC_EXECUTE)
SRC_EXE_UTILS		= $(SRC_EXE_DIR)$(SRC_UTILS_DIR)

SRC_FUNCTIONS_M	= $(SRC_DIR_F)minishell_main.c

SRC_FUNCTIONS_D = $(SRC_DIR_F)$(SRC_DEBUG_DIR)minishell_printf_utils.c

SRC_FUNCTIONS_U = $(SRC_DIR_F)$(SRC_UTILS_DIR)minishell_utils.c \
				  $(SRC_DIR_F)$(SRC_UTILS_DIR)minishell_utils_1.c \
				  $(SRC_DIR_F)$(SRC_UTILS_DIR)minishell_free.c

SRC_FUNCTIONS_P = $(SRC_DIR_F)$(SRC_PARSER_DIR)minishell_ast_parser.c \
				  $(SRC_DIR_F)$(SRC_PARSER_DIR)minishell_token_handler.c \
				  $(SRC_DIR_F)$(SRC_PARSER_DIR)minishell_lexical_analysis.c \
				  $(SRC_DIR_F)$(SRC_PARSER_DIR)minishell_syntactical_analysis.c \
				  $(SRC_DIR_F)$(SRC_PARSER_DIR)minishell_cmds_handler.c \
				  $(SRC_DIR_F)$(SRC_PARSER_DIR)minishell_expansion.c \
				  $(SRC_DIR_F)$(SRC_PARSER_DIR)minishell_redirections.c

SRC_FUNCTIONS_P_U = $(SRC_DIR_F)$(SRC_PARSER_UT_DIR)minishell_expansion_utils.c

SRC_FUNCTIONS_T = $(SRC_DIR_F)$(SRC_TERMINAL_DIR)minishell_terminal.c \
				  $(SRC_DIR_F)$(SRC_TERMINAL_DIR)minishell_terminal_utils.c \
				  $(SRC_DIR_F)$(SRC_TERMINAL_DIR)minishell_terminal_utils_extra.c

SRC_FUNCTIONS_E_B = $(SRC_DIR_F)$(SRC_BUILDIN_DIR)cd.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)cd_actions.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)cd_utils.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)echo.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)env.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)exit.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)export.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)export_actions.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)export_utils.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)export_utils_1.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)pwd.c \
					$(SRC_DIR_F)$(SRC_BUILDIN_DIR)unset.c

SRC_FUNCTIONS_E_E = $(SRC_DIR_F)$(SRC_EXECUTE_DIR)multiple_execution.c \
					$(SRC_DIR_F)$(SRC_EXECUTE_DIR)multiple_execution_utils.c \
					$(SRC_DIR_F)$(SRC_EXECUTE_DIR)single_execution.c \
					$(SRC_DIR_F)$(SRC_EXECUTE_DIR)execution_manager.c \
					$(SRC_DIR_F)$(SRC_EXECUTE_DIR)buildins_check.c


SRC_FUNCTIONS_E_U = $(SRC_DIR_F)$(SRC_EXE_UTILS)error_print.c \
					$(SRC_DIR_F)$(SRC_EXE_UTILS)find_path.c \
					$(SRC_DIR_F)$(SRC_EXE_UTILS)ft_getenv.c

SRC_FUNCTIONS_S	= $(SRC_DIR_F)$(SRC_SIGNAL_DIR)minishell_signal_process.c

#sources path
SRC_FUNCTIONS_D_DIR_PATH =$(SRC_DIR_F)$(SRC_DEBUG_DIR)
SRC_FUNCTIONS_U_DIR_PATH =$(SRC_DIR_F)$(SRC_UTILS_DIR)
SRC_FUNCTIONS_P_DIR_PATH =$(SRC_DIR_F)$(SRC_PARSER_DIR)
SRC_FUNCTIONS_P_U_DIR_PATH =$(SRC_DIR_F)$(SRC_PARSER_UT_DIR)
SRC_FUNCTIONS_T_DIR_PATH =$(SRC_DIR_F)$(SRC_TERMINAL_DIR)
SRC_FUNCTIONS_E_B_DIR_PATH = $(SRC_DIR_F)$(SRC_BUILDIN_DIR)
SRC_FUNCTIONS_E_E_DIR_PATH = $(SRC_DIR_F)$(SRC_EXECUTE_DIR)
SRC_FUNCTIONS_E_U_DIR_PATH = $(SRC_DIR_F)$(SRC_EXE_UTILS)
SRC_FUNCTIONS_S_DIR_PATH = $(SRC_DIR_F)$(SRC_SIGNAL_DIR)

#Objects dir
OBJ_DEBUG_DIR_PATH		= $(OBJ_DIR_F)$(SRC_FUNCTIONS_D_DIR_PATH)
OBJ_UTILS_DIR_PATH 		= $(OBJ_DIR_F)$(SRC_FUNCTIONS_U_DIR_PATH)
OBJ_PARSER_DIR_PATH 	= $(OBJ_DIR_F)$(SRC_FUNCTIONS_P_DIR_PATH)
OBJ_PARSER_UT_DIR_PATH 	= $(OBJ_DIR_F)$(SRC_FUNCTIONS_P_U_DIR_PATH)
OBJ_TERMINAL_DIR_PATH 	= $(OBJ_DIR_F)$(SRC_FUNCTIONS_T_DIR_PATH)
OBJ_EXE_E_B_DIR_PATH	= $(OBJ_DIR_F)$(SRC_FUNCTIONS_E_B_DIR_PATH)
OBJ_EXE_E_E_DIR_PATH	= $(OBJ_DIR_F)$(SRC_FUNCTIONS_E_E_DIR_PATH)
OBJ_EXE_E_U_DIR_PATH	= $(OBJ_DIR_F)$(SRC_FUNCTIONS_E_U_DIR_PATH)
OBJ_SIGNAL_S_DIR_PATH	= $(OBJ_DIR_F)$(SRC_FUNCTIONS_S_DIR_PATH)

#Object prefix
MINI_OBJ		= $(patsubst $(SRC_DIR_F)%.c,$(OBJ_DIR_F)%.o,$(SRC_FUNCTIONS_M))
MINI_OBJ_D		= $(patsubst $(SRC_FUNCTIONS_D_DIR_PATH)%.c,$(OBJ_DEBUG_DIR_PATH)%.o,$(SRC_FUNCTIONS_D))
MINI_OBJ_U		= $(patsubst $(SRC_FUNCTIONS_U_DIR_PATH)%.c,$(OBJ_UTILS_DIR_PATH)%.o,$(SRC_FUNCTIONS_U))
MINI_OBJ_P		= $(patsubst $(SRC_FUNCTIONS_P_DIR_PATH)%.c,$(OBJ_PARSER_DIR_PATH)%.o,$(SRC_FUNCTIONS_P))
MINI_OBJ_P_U	= $(patsubst $(SRC_FUNCTIONS_P_U_DIR_PATH)%.c,$(OBJ_PARSER_UT_DIR_PATH)%.o,$(SRC_FUNCTIONS_P_U))
MINI_OBJ_T		= $(patsubst $(SRC_FUNCTIONS_T_DIR_PATH)%.c,$(OBJ_TERMINAL_DIR_PATH)%.o,$(SRC_FUNCTIONS_T))
MINI_OBJ_E_B	= $(patsubst $(SRC_FUNCTIONS_E_B_DIR_PATH)%.c,$(OBJ_EXE_E_B_DIR_PATH)%.o,$(SRC_FUNCTIONS_E_B))
MINI_OBJ_E_E	= $(patsubst $(SRC_FUNCTIONS_E_E_DIR_PATH)%.c,$(OBJ_EXE_E_E_DIR_PATH)%.o,$(SRC_FUNCTIONS_E_E))
MINI_OBJ_E_U	= $(patsubst $(SRC_FUNCTIONS_E_U_DIR_PATH)%.c,$(OBJ_EXE_E_U_DIR_PATH)%.o,$(SRC_FUNCTIONS_E_U))
MINI_OBJ_S		= $(patsubst $(SRC_FUNCTIONS_S_DIR_PATH)%.c,$(OBJ_SIGNAL_S_DIR_PATH)%.o,$(SRC_FUNCTIONS_S))

IFMAKE_DIR_F	= .cache_exists

#instructions
all:	$(LIBFT) $(IFMAKE_DIR_F) $(NAME)

$(IFMAKE_DIR_F):
					@mkdir -p $(OBJ_DIR_F)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_DEBUG_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_UTILS_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_PARSER_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_PARSER_DIR)$(SRC_UTILS_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_TERMINAL_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_EXE_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_BUILDIN_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_EXECUTE_DIR)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_EXE_UTILS)
					@mkdir -p $(OBJ_DIR_F)$(SRC_DIR_F)$(SRC_SIGNAL_DIR)

$(LIBFT):
					@echo "Getting libft ready"
					@make -sC $(LIBFT_DIR)

$(NAME): $(MINI_OBJ) $(MINI_OBJ_D) $(MINI_OBJ_U) $(MINI_OBJ_P) $(MINI_OBJ_P_U) $(MINI_OBJ_T) $(MINI_OBJ_E_B) $(MINI_OBJ_E_E) $(MINI_OBJ_E_U) $(MINI_OBJ_S) $(LIBFT)
					@echo "Compiling minishell..."
					@$(CC) $(CFLAGS) -o $(NAME) $(MINI_OBJ) $(MINI_OBJ_D) $(MINI_OBJ_U) $(MINI_OBJ_P) $(MINI_OBJ_P_U) $(MINI_OBJ_T) $(MINI_OBJ_E_B) $(MINI_OBJ_E_E) $(MINI_OBJ_E_U) $(MINI_OBJ_S) $(LIBFT) $(INCLUDE) -l readline
					@echo "Minishell ready."

$(OBJ_DIR_F)%.o: $(SRC_DIR_F)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DEBUG_DIR_PATH)%.o: $(SRC_FUNCTIONS_D_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_UTILS_DIR_PATH)%.o: $(SRC_FUNCTIONS_U_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_PARSER_DIR_PATH)%.o: $(SRC_FUNCTIONS_P_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_PARSER_UT_DIR_PATH)%.o: $(SRC_FUNCTIONS_P_U_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_TERMINAL_DIR_PATH)%.o: $(SRC_FUNCTIONS_T_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_EXE_E_B_DIR_PATH)%.o: $(SRC_FUNCTIONS_E_B_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_EXE_E_E_DIR_PATH)%.o: $(SRC_FUNCTIONS_E_E_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_EXE_E_U_DIR_PATH)%.o: $(SRC_FUNCTIONS_E_U_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_SIGNAL_S_DIR_PATH)%.o: $(SRC_FUNCTIONS_S_DIR_PATH)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
					@echo "Removing object files"
					@$(RM) $(OBJ_DIR_F)
					@make clean -sC $(LIBFT_DIR)
					@$(RM) .cache_exists
					@$(RM) minishell.dSYM
					@$(RM) out*

fclean:			clean
					@echo "Removing minishell..."
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re:				fclean all
					@echo "$(BLUE)Cleaned and rebuilt everything for minishell$(DEF_COLOR)"

.PHONY: all re clean fclean .cache_exists

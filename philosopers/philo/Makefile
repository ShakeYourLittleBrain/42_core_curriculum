# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 05:17:44 by skhastag          #+#    #+#              #
#    Updated: 2024/06/18 03:19:53 by skhastag         ###   ########.fr        #
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


NAME = 			philo

CC = 			cc
CFLAGS = 		-g -pthread -Werror -Wall -Wextra
RM = 			rm -rf
OBJ_DIR = 		obj/
HEADER	=		philo.h

SRC_FILES=		philo_main.c philo_error_input.c \
				philo_ft_utils.c philo_ft_utils_ext.c \
				philo_utils.c philo_ft_init.c \
				philo_printf_utils_.c philo_prog_init.c \
				philo_jobs.c philo_police.c \

OBJS=			$(patsubst %.c,$(OBJ_DIR)%.o,$(SRC_FILES))

start:
				@make all

all : 			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				@echo "$(ORANGE)Compiling philo... $(DEF_COLOR)"
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)philo created in /philo/ ... $(DEF_COLOR)"

$(OBJ_DIR)%.o:	%.c
				@echo "$(YELLOW)Getting ready... $< $(DEF_COLOR)"
				@mkdir -p $(@D)
				@echo "$(BLUE)Obj is ready... $@ $(DEF_COLOR)"
				@$(CC) $(CFLAGS) -c $< -o $@

clean :
				@$(RM) $(OBJ_DIR)
				@$(RM) .cache_exists

fclean : 		clean
				$(RM) $(NAME)
				@$(RM) philo.dSYM


re : 			fclean all

# Phony targets
.PHONY: start all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 12:18:11 by fduque-a          #+#    #+#              #
#    Updated: 2023/06/17 23:38:21 by fduque-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = push_swap
BONUS = checker
HEADER = push_swap.h
HEADER_BONUS = a_push_swap_bonus.h
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar rcs
RM = rm -f
HDR = -I .

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources to objects

SRC_FILES = comm_push comm_reverse comm_rotate comm_swap free_error_check main push_swap set_stuff small_sort stack_creation utils_algo utils_sort
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))
SRC_BONUS_FILES = a_get_next_line_bonus a_checker_bonus a_get_next_line_utils_bonus push_swap set_stuff small_sort stack_creation utils_algo utils_sort comm_push comm_reverse comm_rotate comm_swap free_error_check a_split_bonus
SRC_BONUS = $(addsuffix .c, $(SRC_BONUS_FILES))
OBJ_BONUS = $(addsuffix .o, $(SRC_BONUS_FILES))

# Rules

$(NAME) : $(OBJ) $(HEADER)
	@ $(CC) $(CFLAGS) $(HDR) $(OBJ) -o $(NAME)
	@ echo "$(BLUE)Compiled $(NAME) with sucess!$(DEF_COLOR)"
	@ echo "$(GREEN)Everything is ready to use!$(DEF_COLOR)"
	@ echo "$(YELLOW)Run ./$(NAME) plus numeric argument/s to start$(DEF_COLOR)"

%.o : %.c $(HEADER)
	@ echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@ $(CC) $(CFLAGS) $(HDR) -c $< -o $@
	@ echo "$(GREEN)Object files created with sucess$(DEF_COLOR)"

all : $(NAME)

clean :
	@ $(RM) -rf $(OBJ)
	@ echo "$(RED)Removed $(NAME) object files$(DEF_COLOR)"
	@ $(RM) -rf $(OBJ_BONUS)
	@ echo "$(RED)Removed $(BONUS) object files$(DEF_COLOR)"

fclean : clean
	@ $(RM)  $(NAME)
	@ echo "$(RED)Removed '$(NAME)' with sucess$(DEF_COLOR)"
	@ $(RM)  $(BONUS)
	@ echo "$(RED)Removed '$(BONUS)' with sucess$(DEF_COLOR)"
	@ echo "$(RED)Everything clean$(DEF_COLOR)"

re : fclean all

bonus: $(OBJ_BONUS) $(HEADER_BONUS)
	@$(CC) $(CFLAGS) $(HDR) $(OBJ_BONUS) -o $(BONUS)
	@echo "$(BLUE)Compiled $(BONUS) with success!$(DEF_COLOR)"
	@echo "$(GREEN)Everything is ready to use!$(DEF_COLOR)"

.PHONY: all clean fclean re
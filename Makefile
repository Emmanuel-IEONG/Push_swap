# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eieong <eieong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 11:19:32 by eieong            #+#    #+#              #
#    Updated: 2025/04/11 11:18:24 by eieong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT := libft/libft.a

RM := rm -rf
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
INCLUDES := -I/usr/include

GREEN		:= \033[0;32m
LGREEN		:= \033[1;32m
PURPLE		:= \033[0;35m
LPURPLE		:= \033[1;35m

SRC :=	src/push_swap.c \
		src/args.c \
		src/move_push.c \
		src/move_swap.c \
		src/move_rotate.c \
		src/move_rev_rotate.c \
		src/sort.c \
		src/algo.c \
		src/nb_index_utils.c \
		src/stack_in_tab.c \
		src/stack_utils.c

OBJ := $(SRC:.c=.o)

$(NAME): $(OBJ)
	@echo "$(GREEN)----Compiling lib----"
	@make all -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@
	@echo "\n$(LGREEN)Push_swap Compiled!\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	@echo "$(PURPLE)----Cleaning----"
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@echo "\n$(LPURPLE)ALL CLEANED!\n"

re: fclean all

.PHONY: all clean fclean re

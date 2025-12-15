# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelhansa <nelhansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 10:06:16 by nelhansa          #+#    #+#              #
#    Updated: 2025/12/15 03:58:24 by nelhansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	./push_swap_utils2.c \
	./push_swap_utils.c \
	./push_swap_utils3.c \
	./push_swap_utils4.c \
	./stack_utils.c \
	./rotate.c \
	./push.c \
	./swap.c \
	./reverse_rotate.c \
	./atoi_ut.c \
	./main.c
SRC_BONUS = checker.c \
	./push_swap.c \
	./push_swap_utils2.c \
	./push_swap_utils.c \
	./push_swap_utils3.c \
	./push_swap_utils4.c \
	./stack_utils.c \
	./rotate.c \
	./push.c \
	./swap.c \
	./reverse_rotate.c \
	./atoi_ut.c \
	./get_next_line.c \
	./get_next_line_utils.c
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME)

clean : 
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

bonus : $(OBJS_BONUS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS_BONUS) -o $(NAME_BONUS)


.PHONY : clean
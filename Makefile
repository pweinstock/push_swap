# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 18:59:13 by pweinsto          #+#    #+#              #
#    Updated: 2021/08/13 17:19:15 by pweinsto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_CHECKER = checker

LIB_NAME = push_swap.a

LIB_NAME_CHECKER = bonus_checker.a

SRCS =	free_utils.c \
		game_rules_push.c \
		game_rules_rotate_down.c \
		game_rules_rotate_up.c \
		game_rules_swap.c \
		parse.c \
		quick_sort.c \
		sort_utils_1.c \
		sort_utils_2.c \
		sort_utils_3.c \
		sort.c \
		stack_utils.c \

C_SRCS = bonus_game_rules_push.c \
		bonus_game_rules_rotate_down.c \
		bonus_game_rules_rotate_up.c \
		bonus_game_rules_swap.c \
		bonus_get_next_line.c \
		bonus_get_next_line_utils.c \

LIBFT_PATH	= ./libft

CHECKER_PATH = ./bonus_checker

GET_NEXT_LINE_PATH = ./bonus_get_next_line

OBJS	=	$(SRCS:.c=.o)

C_OBJS	=	$(C_SRCS:.c=.o)

CC		=		gcc

CFLAGS	=	-Werror -Wextra -Wall

C = -c

O = -o

AR		=		ar rc

RM		=		rm -f

all: 		target_libft $(NAME) $(NAME_CHECKER)

target_libft:		
			make -C libft/

compile:
			$(CC) $(CFLAGS) $(C) $(SRCS)

compile_checker:
			$(CC) $(CFLAGS) $(C) $(CHECKER_PATH)/*.c $(GET_NEXT_LINE_PATH)/*.c

$(LIB_NAME):	compile
			$(AR) $(LIB_NAME) $(OBJS) $(LIBFT_PATH)/*.o

$(LIB_NAME_CHECKER):	compile_checker
			$(AR) $(LIB_NAME_CHECKER) $(OBJS) $(C_OBJS) $(LIBFT_PATH)/*.o

$(NAME): $(LIB_NAME)
			$(CC) $(CFLAGS) $(O) $(NAME) $(LIB_NAME) push_swap.c

$(NAME_CHECKER): $(LIB_NAME_CHECKER)
			$(CC) $(CFLAGS) $(O) $(NAME_CHECKER) $(LIB_NAME_CHECKER) $(CHECKER_PATH)/bonus_checker.c

clean_libft:
			make clean -C libft/

clean:		clean_libft
			$(RM) $(OBJS) push_swap.o

bonus_clean:
			$(RM) $(C_OBJS) bonus_checker.o

fclean_libft:
			make fclean -C libft/

fclean:		clean bonus_clean fclean_libft 
			$(RM) $(LIB_NAME) $(LIB_NAME_CHECKER) $(NAME) $(NAME_CHECKER)


re:			fclean all
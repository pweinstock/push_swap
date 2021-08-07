# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 18:59:13 by pweinsto          #+#    #+#              #
#    Updated: 2021/08/07 19:36:16 by pweinsto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB_NAME = push_swap.a

SRCS =	game_rules_push.c \
		game_rules_rotate_down.c \
		game_rules_rotate_up.c \
		game_rules_swap.c \
		parse.c \
		push_swap.c \
		quick_sort.c \
		sort_utils_1.c \
		sort_utils_2.c \
		sort.c \
		stack_utils.c \

LIBFT_PATH	= ./libft

OBJS	=	$(SRCS:.c=.o)

CC		=		gcc

CFLAGS	=		-Wall -Wextra -Werror

C = -c

O = -o

AR		=		ar rc

RM		=		rm -f

all: 		target_libft $(NAME)

target_libft:		
			make -C libft/

compile:
			$(CC) $(CFLAGS) $(C) $(SRCS)

$(LIB_NAME):	compile
			$(AR) $(LIB_NAME) $(OBJS) $(LIBFT_PATH)/*.o

$(NAME): $(LIB_NAME)
			$(CC) $(CFLAGS) $(O) $(NAME) $(LIB_NAME)

clean_libft:
			make clean -C libft/

clean:		clean_libft
			$(RM) $(OBJS)

fclean_libft:
			make fclean -C libft/

fclean:		clean fclean_libft
			$(RM) $(LIB_NAME) $(NAME) 


re:			fclean all
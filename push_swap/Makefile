# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 11:11:46 by mjameau           #+#    #+#              #
#    Updated: 2024/07/09 16:23:26 by mjameau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

OBJECTS	=	$(SRCS:.c=.o)

SRCS	=	create_stack.c main.c stack_utils.c errors_fts.c push_swap.c reverse_rotate.c \
			rotates.c sort.c swaps.c target_price.c push.c remake_libft_utils.c

HEADER	=	push_swap.h

all: $(NAME)


$(NAME):
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean

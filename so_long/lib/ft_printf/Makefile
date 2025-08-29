# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 10:16:39 by mjameau           #+#    #+#              #
#    Updated: 2024/09/06 10:16:40 by mjameau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= ft_printf.c ft_utils.c ft_printf_alpha.c ft_printf_digit.c ft_printf_hexa.c
SRCS			= ${SRC}
OBJS			= ${SRCS:.c=.o}
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

.c.o:
	@$(CC) -I. $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
	@ar rcs $(NAME) $?
	@ranlib $(NAME)

all:			$(NAME)

clean:
	@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)
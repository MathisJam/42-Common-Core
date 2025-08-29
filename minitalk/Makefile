# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 16:24:45 by mjameau           #+#    #+#              #
#    Updated: 2024/11/06 14:05:48 by mjameau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	client
NAME2 	=	server

NAMEBONUS = client_bonus
NAME2BONUS = server_bonus

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

OBJECTS	=	$(LIBFTDIR:.c=.o) $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

SRCS	= $(SRCDIR)client.c

SRCS2	= $(SRCDIR)server.c

SRCSBONUS	=	$(SRCDIR)client_bonus.c
SRCS2BONUS	=	$(SRCDIR)server_bonus.c

all: $(NAME) $(NAME2)


$(NAME): $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(NAME2) : $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS2) $(LIBFT) -o $(NAME2)

$(NAMEBONUS): $(LIBFT)
		$(CC) $(CFLAGS) $(SRCSBONUS) $(LIBFT) -o $(NAMEBONUS)

$(NAME2BONUS): $(LIBFT)
		$(CC) $(CFLAGS) $(SRCS2BONUS) $(LIBFT) -o $(NAME2BONUS)

$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJECTS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(NAME2) $(NAMEBONUS) $(NAME2BONUS)

bonus: $(NAMEBONUS) $(NAME2BONUS)

re: fclean all

.PHONY: all clean re fclean

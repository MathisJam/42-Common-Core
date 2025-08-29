# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 10:59:03 by mjameau           #+#    #+#              #
#    Updated: 2025/02/20 12:55:05 by mjameau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC_PATH	=	./
SRC			=	megaphone.cpp

OBJ_PATHb	=	obj/
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))


RESET			= \033[0m
BLACK    		= \033[1;30m
RED      		= \033[1;31m
GREEN    		= \033[1;32m
YELLOW   		= \033[1;33m
BLUE     		= \033[1;34m
MAGENTA  		= \033[1;35m
CYAN     		= \033[1;36m
WHITE    		= \033[1;37m

SILENT		=	> /dev/null 2>&1

all: $(NAME)

$(NAME):
	@echo "$(RED)"C"$(YELLOW)"o"$(GREEN)"m"$(CYAN)"p"$(BLUE)"i"$(MAGENTA)"l"$(RED)"i"$(YELLOW)"n"$(GREEN)"g" $(CYAN)"m"$(BLUE)"e"$(MAGENTA)"g"$(RED)"a"$(YELLOW)"p"$(GREEN)"h"$(CYAN)"o"$(BLUE)"n"$(MAGENTA)"e"$(RED)"."$(YELLOW)"."$(GREEN)"." "📣" $(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"💫" $(RESET)"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(RED)"C"$(YELLOW)"l"$(GREEN)"e"$(CYAN)"a"$(BLUE)"n"$(MAGENTA)"i"$(RED)"n"$(YELLOW)"g" $(GREEN)"m"$(CYAN)"e"$(BLUE)"g"$(MAGENTA)"a"$(RED)"p"$(YELLOW)"h"$(GREEN)"o"$(CYAN)"n"$(BLUE)"e"$(MAGENTA)"."$(RED)"."$(YELLOW)"." $(RESET)"
	@rm -rf $(OBJ_PATH) $(SILENT)
	@echo "$(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"🧹" $(RESET)"

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean



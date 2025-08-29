# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 16:45:58 by mjameau           #+#    #+#              #
#    Updated: 2025/03/26 17:07:10 by mjameau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Intern

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC_PATH	=	src/
SRC			=	main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

INC = -I inc/


OBJ_PATH	=	obj/
OBJ			=	$(SRC:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

DEP            =    $(OBJS:.o=.d)

RESET			= \e[0m
BLACK    		= \e[1;30m
RED      		= \e[1;31m
GREEN    		= \e[1;32m
YELLOW   		= \e[1;33m
BLUE     		= \e[1;34m
MAGENTA  		= \e[1;35m
CYAN     		= \e[1;36m
WHITE    		= \e[1;37m

SILENT		=	> /dev/null 2>&1

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(RED)"C"$(YELLOW)"o"$(GREEN)"m"$(CYAN)"p"$(BLUE)"i"$(MAGENTA)"l"$(RED)"i"$(YELLOW)"n"$(GREEN)"g" $(CYAN)"I"$(BLUE)"n"$(MAGENTA)"t"$(RED)"e"$(YELLOW)"r"$(GREEN)"n"$(RED)"."$(YELLOW)"."$(GREEN)"." "👶" $(RESET)"
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)
	@echo "$(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"💫" $(RESET)"


$(OBJ_PATH)%.o: $(SRC_PATH)/%.cpp
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(RED)"C"$(YELLOW)"l"$(GREEN)"e"$(CYAN)"a"$(BLUE)"n"$(MAGENTA)"i"$(RED)"n"$(YELLOW)"g" $(CYAN)"I"$(BLUE)"n"$(MAGENTA)"t"$(RED)"e"$(YELLOW)"r"$(GREEN)"n"$(RED)"."$(YELLOW)"."$(GREEN)"." "👶" $(RESET)"
	@rm -rf $(OBJ_PATH) $(SILENT)
	@echo "$(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"🧹" $(RESET)"

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean

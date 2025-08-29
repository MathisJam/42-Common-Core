RESET			= "\033[0m"
BLACK    		= "\033[30m"
RED      		= "\033[31m"
GREEN    		= "\033[32m"
YELLOW   		= "\033[33m"
BLUE     		= "\033[34m"
MAGENTA  		= "\033[35m"
CYAN     		= "\033[36m"
WHITE    		= "\033[37m"


NAME	= philo

SRCS 	=	get_set.c	handlers.c	init.c	lunch.c	main.c \
			monitor.c	parsing.c	update.c	utils.c	utils2.c

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -g

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(RED)"C"$(YELLOW)"o"$(GREEN)"m"$(CYAN)"p"$(BLUE)"i"$(MAGENTA)"l"$(RED)"i"$(YELLOW)"n"$(GREEN)"g" $(CYAN)"p"$(BLUE)"h"$(MAGENTA)"i"$(RED)"l"$(YELLOW)"o"$(GREEN)"."$(CYAN)"."$(BLUE)"." "👴" $(RESET)
	@cc $(OBJS) $(FLAGS) -o $(NAME)
	@echo $(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"💫" $(RESET)

clean:
	@echo $(RED)"C"$(YELLOW)"l"$(GREEN)"e"$(CYAN)"a"$(BLUE)"n"$(MAGENTA)"i"$(RED)"n"$(YELLOW)"g" $(GREEN)"p"$(CYAN)"h"$(BLUE)"i"$(MAGENTA)"l"$(RED)"o"$(YELLOW)"."$(GREEN)"."$(CYAN)"." "🧹" $(RESET)
	@rm -f $(OBJS)
	@echo $(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"✨" $(RESET)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
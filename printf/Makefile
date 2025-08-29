NAME	=	libftprintf.a

LIBFTNAME 	=	$(LIBFTDIR)/libft.a

LIBFTDIR	=	./libft

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

OBJECTS	=	$(SRCS:.c=.o)

SRCS	=	ft_printf.c ft_print_c.c ft_print_di.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_xx.c

HEADER	=	ft_printf.h

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR) all

$(NAME): makelibft $(OBJECTS)
		cp $(LIBFTNAME) $(NAME)
		ar rcs	$(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) -I. $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	@make clean -C $(LIBFTDIR)

fclean:	clean
		$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR)

re: all

.PHONY: all clean re fclean makelibft

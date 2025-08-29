# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 16:30:06 by mjameau           #+#    #+#              #
#    Updated: 2024/09/05 16:30:07 by mjameau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

src	=		main.c\
			put_image.c\
			map_init.c\
			moves.c\
			check_map.c\
			flood_fill.c\
			get_next_line.c\
			get_next_line_utils.c\

SRCS = $(addprefix ./srcs/, $(src))

OBJS = $(SRCS:.c=.o)


MLX_A = libmlx.a
MLX_DIR = ./lib/mlx/
MLX		=	$(MLX_DIR)$(MLX_A)

PRINTF_A = libftprintf.a
PRINTF_DIR = ./lib/ft_printf/
PRINTF	= $(PRINTF_DIR)$(PRINTF_A)

FLAGS = lib/mlx/libmlx.a lib/mlx/libmlx_Linux.a -L. -lXext -L. -lX11
FT_PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

INCLUDE = includes/

.c.o :
	@cc -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

all: $(MLX) $(PRINTF) $(NAME)

$(PRINTF):
	@echo "Making ft_printf..."
	@make -C $(PRINTF_DIR)
	@echo "Done!"

$(MLX):
	@echo "Making MiniLibx..."
	@make -C $(MLX_DIR)
	@echo "Done!"


$(NAME): $(OBJS)
	@echo "Compiling so_long..."
	@cc $(OBJS) $(FLAGS) -o $(NAME) $(MLX) $(PRINTF) -lXext -lX11 -lm
	@echo "Done!"

clean:
	@echo "Cleaning..."
	@rm -f $(OBJS)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(MLX_DIR)
	@echo "Cleaning complete !"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(PRINTF_DIR)$(PRINTF_A)
	@rm -f $(MLX_DIR)$(MLX_A)

re: fclean all

.PHONY: all clean fclean re
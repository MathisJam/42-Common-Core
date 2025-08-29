/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:01 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/10 15:39:02 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FAIL 1
# define SUCCESS 0

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/mlx/mlx.h"
# include "get_next_line.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	void	*ptr;
	void	*window;
	void	*sprite[8];
	int		img_size;
	char	**map;
	int		x;
	int		y;
	int		nb_move;

	int		player_x;
	int		player_y;
	int		end_y;
	int		end_x;
	int		carrot;
	int		check_carrot;
	int		next_x;
	int		next_y;
}			t_data;

void		initialised(t_data *data, char *argv);
int			handle_input(int keysym, t_data *data);
int			free_all(t_data *data);
int			check_name(const char *big, const char *little, size_t len);
void		map_init_window(t_data *data);
void		put_image_on_map(t_data *data, int i, int j);
void		map_read(t_data *data, char *map);
char		**maploc(int count_line, char *map);
void		free_tab(char **tab);
void		move(t_data *data, char move);
void		next_move(t_data *data, char c);
void		player_actualisation(t_data *data, char move);
void		set_position(t_data *data);
void		init_image(t_data *data);
void		*xpm_to_img(t_data *data, char *path, int index);
void		error_xpm(t_data *data, int i);
void		free_ptr(t_data *data);
int			flood_fill(t_data *data);
void		fill(t_data *data, char **map, int y, int x);
char		**dup_map(t_data *data, char **map);
int			map_check(t_data *data);
int			player_end_check(char **map);
int			size_check(t_data *data, char **map);
int			line_check(t_data *data, char **map, int i, int len);

#endif
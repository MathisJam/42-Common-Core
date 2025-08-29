/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:11:07 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/24 18:54:59 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ROTATION_SPEED 0.075
# define PLAYER_SPEED 0.075
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# define CNUM 5
# define FNUM 6

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_ray
{
	int			curr_x;
	int			map_x;
	int			map_y;
	double		cam_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		prep_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_texture
{
	void		*img_ptr;
	char		*data;
	char		*path;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct s_line
{
	int			x;
	int			y;
	int			y0;
	int			y1;
	int			tex_x;
	int			tex_y;
}				t_line;

typedef struct s_player
{
	double		px;
	double		py;
	t_coord		dir_vect;
	t_coord		cam_plane_vect;
	double		cam_height;
	double		speed;
	double		sens;
}				t_player;

typedef struct s_control
{
	int			last_mouse_pos;
	int			look_left;
	int			look_right;
	int			look_up;
	int			look_down;
	int			move_left;
	int			move_right;
	int			move_fwd;
	int			move_bwd;
}				t_control;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_texture	*mlx_img;

	int			row_nbr;
	int			column_nbr;
	int			map_start;
	int			player_found;
	char		**map;

	char		**f_strings;
	char		**c_strings;
	int			*floor;
	int			*ceiling;

	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;
	t_control	*control;
	t_player	*player;
}				t_data;

// INIT
void			init_data(t_data *data);
void			init_mlx(t_data *data);
void			init_textures(t_data *data);

// MAP
void			load_map(t_data *data, char *map);
char			**malloc_map(char *map, t_data *data);
void			check_map(t_data *data);
void			get_map_info(t_data *data, char *map);
bool			is_map_start(char *str);
void			get_floor_ceiling(t_data *data);
int				validate_player(t_data *data, char **map, int i, int j);

// RENDER AFFICHAGE & CO
int				render(void *arg);
void			raycasting(t_data *data, t_ray *ray);
void			prep_height(t_ray *ray, t_player *player);
void			draw_texture_image(t_data *data, t_ray *ray, t_line *line,
					t_texture *img);
void			paint_line(t_data *data, t_line *line, int *rgb);
void			draw_textures(t_data *data, t_ray *ray, t_player *player);

// CAMERA
void			set_camera(t_data *data, double d_y, double p_x, double p_y);
void			turn_left(t_data *data, bool mouse);
void			turn_right(t_data *data, bool mouse);

// INPUTS
int				handle_key_release(int key, t_data *data);
int				handle_key_press(int key, t_data *data);
int				handle_mouse_move(int x, int y, t_data *data);
void			event_executor(t_data *data);
void			move_forward(t_data *data);
void			move_right(t_data *data);
void			move_left(t_data *data);
void			move_backward(t_data *data);

// SAFE FUNCTIONS
int				safe_open_fd(char *file, int flag, t_data *data);
void			*malloc_fd(size_t bytes, t_data *data, int *fd);
void			*safe_calloc(size_t nmemb, size_t bytes, t_data *data);

// UTILS
int				check_extension(const char *big, const char *little,
					size_t len);
int				count_strings(char **strings);
char			*strdup_without_n(const char *s);
bool			is_space(char c);
bool			is_wall(char c);
int				is_char(char c);
void			not_empty(char **map, int y, int x, t_data *data);
int				invalid_char(char **map, t_data *data);
void			skip_one_line(int fd);

// FREE
void			err_msg(char *str, t_data *data, bool to_free);
int				free_all(t_data *data, int exit_status);

#endif

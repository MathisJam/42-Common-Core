/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:52:01 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/24 13:57:49 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	paint_texture_line(t_data *data, t_ray *ray, t_line *line,
		double wall_x)
{
	t_texture	*img;
	int			tex_x;

	img = data->no;
	if (ray->side == EAST)
		img = data->ea;
	else if (ray->side == WEST)
		img = data->we;
	else if (ray->side == NORTH)
		img = data->no;
	else if (ray->side == SOUTH)
		img = data->so;
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->side == WEST || ray->side == EAST) && ray->ray_dir_x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((ray->side == NORTH || ray->side == SOUTH) && ray->ray_dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = ray->draw_start;
	line->y1 = ray->draw_end;
	line->tex_x = tex_x;
	draw_texture_image(data, ray, line, img);
}

void	draw_textures(t_data *data, t_ray *ray, t_player *player)
{
	t_line	*line;
	double	wall_x;

	line = malloc(sizeof(t_line));
	ft_bzero(line, sizeof(t_line));
	if (ray->side == WEST || ray->side == EAST)
		wall_x = player->py + ray->prep_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->px + ray->prep_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	line->x = ray->curr_x;
	if (is_wall(data->map[ray->map_y][ray->map_x]))
		paint_texture_line(data, ray, line, wall_x);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	paint_line(data, line, data->ceiling);
	line->y0 = WIN_HEIGHT;
	line->y1 = ray->draw_end;
	paint_line(data, line, data->floor);
	free(line);
}

int	render(void *arg)
{
	t_data	*data;
	t_ray	*ray;

	data = (t_data *)arg;
	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
		return (1);
	while (ray->curr_x < WIN_WIDTH)
		raycasting(data, ray);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img->img_ptr, 0, 0);
	free(ray);
	event_executor(data);
	return (0);
}

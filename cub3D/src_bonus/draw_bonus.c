/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:21:28 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/19 15:54:52 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	texture_on_img(t_data *data, t_ray *ray, t_line *line,
		t_texture *texture)
{
	int	scale;

	scale = line->y * texture->line_length - (WIN_HEIGHT
			* data->player->cam_height) * texture->line_length / 2
		+ ray->line_height * texture->line_length / 2;
	line->tex_y = ((scale * texture->height) / ray->line_height)
		/ texture->line_length;
	data->mlx_img->data[line->y * data->mlx_img->line_length + line->x
		* data->mlx_img->bits_per_pixel / 8] = texture->data[line->tex_y
		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)];
	data->mlx_img->data[line->y * data->mlx_img->line_length + line->x
		* (data->mlx_img->bits_per_pixel / 8) + 1] = texture->data[line->tex_y
		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)
		+ 1];
	data->mlx_img->data[line->y * data->mlx_img->line_length + line->x
		* (data->mlx_img->bits_per_pixel / 8) + 2] = texture->data[line->tex_y
		* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)
		+ 2];
}

static void	pixel_on_img(int *rgb, int x, int y, t_texture *img)
{
	int	r;
	int	g;
	int	b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	img->data[y * img->line_length + x * img->bits_per_pixel / 8] = b;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8 + 1] = g;
	img->data[y * img->line_length + x * img->bits_per_pixel / 8 + 2] = r;
}

void	draw_texture_image(t_data *data, t_ray *ray, t_line *line,
		t_texture *img)
{
	int	y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		line->y--;
		while (++line->y < y_max)
			texture_on_img(data, ray, line, img);
	}
}

void	paint_line(t_data *data, t_line *line, int *rgb)
{
	int	y;
	int	y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_on_img(rgb, line->x, y, data->mlx_img);
			y++;
		}
	}
}

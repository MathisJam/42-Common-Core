/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:06:47 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/24 17:45:46 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// La fonction fabs prend un argument (un nombre a virgule, cf float)
// et retourne sa valeur absolue en type double.
static void	init_values(t_ray *ray, t_player *player)
{
	ray->cam_x = (2 * ray->curr_x) / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = player->dir_vect.x + player->cam_plane_vect.x * ray->cam_x;
	ray->ray_dir_y = player->dir_vect.y + player->cam_plane_vect.y * ray->cam_x;
	ray->map_x = (int)player->px;
	ray->map_y = (int)player->py;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

static void	determine_step(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->px - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->px) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->py - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->py) * ray->delta_dist_y;
	}
}

static void	get_next_wall(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		if (ray->step_x == -1)
			ray->side = EAST;
		else
			ray->side = WEST;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		if (ray->step_y == -1)
			ray->side = SOUTH;
		else
			ray->side = NORTH;
	}
}

static void	algo_dda(t_data *data, t_ray *ray)
{
	while (!ray->hit)
	{
		get_next_wall(ray);
		if (is_wall(data->map[ray->map_y][ray->map_x]))
			ray->hit = 1;
	}
}

void	raycasting(t_data *data, t_ray *ray)
{
	t_player	*player;

	player = data->player;
	init_values(ray, player);
	determine_step(ray, player);
	algo_dda(data, ray);
	prep_height(ray, player);
	draw_textures(data, ray, player);
	ray->curr_x++;
}

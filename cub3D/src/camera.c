/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:17:40 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/24 12:20:43 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	validate_player(t_data *data, char **map, int i, int j)
{
	if (map[i][j] == 'N')
	{
		data->player->dir_vect.x = 0.00;
		set_camera(data, -1.00, 0.66, 0.00);
	}
	else if (map[i][j] == 'S')
	{
		data->player->dir_vect.x = 0.00;
		set_camera(data, 1.00, -0.66, 0.00);
	}
	else if (map[i][j] == 'E')
	{
		data->player->dir_vect.x = 1.00;
		set_camera(data, 0.00, 0.00, 0.66);
	}
	else if (map[i][j] == 'W')
	{
		data->player->dir_vect.x = -1;
		set_camera(data, 0.00, 0.00, -0.66);
	}
	else
		return (1);
	data->player->px = (double)j + 0.5;
	data->player->py = (double)i + 0.5;
	return (0);
}

void	set_camera(t_data *data, double d_y, double p_x, double p_y)
{
	if (data->player_found)
		err_msg("Need one and only one N S W E char\n", data, true);
	data->player->dir_vect.y = d_y;
	data->player->cam_plane_vect.x = p_x;
	data->player->cam_plane_vect.y = p_y;
	data->player_found++;
}

void	turn_left(t_data *data, bool mouse)
{
	double	og_dirx;
	double	og_planex;
	double	sens;

	og_dirx = data->player->dir_vect.x;
	og_planex = data->player->cam_plane_vect.x;
	sens = data->player->sens;
	if (mouse == true)
		sens = data->player->sens * 0.5;
	data->player->dir_vect.x = data->player->dir_vect.x * cos(-sens)
		- data->player->dir_vect.y * sin(-sens);
	data->player->dir_vect.y = og_dirx * sin(-sens) + data->player->dir_vect.y
		* cos(-sens);
	data->player->cam_plane_vect.x = data->player->cam_plane_vect.x * cos(-sens)
		- data->player->cam_plane_vect.y * sin(-sens);
	data->player->cam_plane_vect.y = og_planex * sin(-sens)
		+ data->player->cam_plane_vect.y * cos(-sens);
}

void	turn_right(t_data *data, bool mouse)
{
	double	og_dirx;
	double	og_planex;
	double	sens;

	og_dirx = data->player->dir_vect.x;
	og_planex = data->player->cam_plane_vect.x;
	sens = data->player->sens;
	if (mouse == true)
		sens = data->player->sens * 0.5;
	data->player->dir_vect.x = data->player->dir_vect.x * cos(sens)
		- data->player->dir_vect.y * sin(sens);
	data->player->dir_vect.y = og_dirx * sin(sens) + data->player->dir_vect.y
		* cos(sens);
	data->player->cam_plane_vect.x = data->player->cam_plane_vect.x * cos(sens)
		- data->player->cam_plane_vect.y * sin(sens);
	data->player->cam_plane_vect.y = og_planex * sin(sens)
		+ data->player->cam_plane_vect.y * cos(sens);
}

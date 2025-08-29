/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:48:32 by jchen             #+#    #+#             */
/*   Updated: 2025/01/24 17:48:27 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	is_wall(char c)
{
	return (c == '1' || c == ' ' || c == '\n' || c == '\0' || is_space(c));
}

void	move_forward(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (!is_wall(data->map[(int)(player->py)][(int)(player->px
		+ player->dir_vect.x * ceil(player->speed))]))
		player->px += (player->speed * player->dir_vect.x);
	if (!is_wall(data->map[(int)(player->py + player->dir_vect.y
				* ceil(player->speed))][(int)(player->px)]))
		player->py += (player->speed * player->dir_vect.y);
}

void	move_right(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (!is_wall(data->map[(int)(player->py)][(int)(player->px
		+ player->cam_plane_vect.x * ceil(player->speed))]))
		player->px += (player->speed * player->cam_plane_vect.x);
	if (!is_wall(data->map[(int)(player->py + player->cam_plane_vect.y
				* ceil(player->speed))][(int)(player->px)]))
		player->py += (player->speed * player->cam_plane_vect.y);
}

void	move_left(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (!is_wall(data->map[(int)(player->py)][(int)(player->px
		- player->cam_plane_vect.x * ceil(player->speed))]))
		player->px -= (player->speed * player->cam_plane_vect.x);
	if (!is_wall(data->map[(int)(player->py - player->cam_plane_vect.y
				* ceil(player->speed))][(int)(player->px)]))
		player->py -= (player->speed * player->cam_plane_vect.y);
}

void	move_backward(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (!is_wall(data->map[(int)(player->py)][(int)(player->px
		- player->dir_vect.x * ceil(player->speed))]))
		player->px -= (player->speed * player->dir_vect.x);
	if (!is_wall(data->map[(int)((player->py - player->dir_vect.y
					* ceil(player->speed)))][(int)(player->px)]))
		player->py -= (player->speed * player->dir_vect.y);
}

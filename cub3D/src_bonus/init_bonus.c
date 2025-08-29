/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:57 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/22 19:19:04 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_player(t_data *data)
{
	data->player = safe_calloc(1, sizeof(t_player), data);
	data->player->cam_height = 1.0;
	data->player->speed = PLAYER_SPEED;
	data->player->sens = ROTATION_SPEED;
}

void	init_data(t_data *data)
{
	data->mlx_img = safe_calloc(1, sizeof(t_texture), data);
	data->no = safe_calloc(1, sizeof(t_texture), data);
	data->so = safe_calloc(1, sizeof(t_texture), data);
	data->we = safe_calloc(1, sizeof(t_texture), data);
	data->ea = safe_calloc(1, sizeof(t_texture), data);
	data->control = safe_calloc(1, sizeof(t_control), data);
	init_player(data);
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		err_msg("Mlx initialization failed\n", data, true);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3D");
	if (data->mlx_win == NULL)
		err_msg("Window initialization failed\n", data, true);
	data->mlx_img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT);
	if (!data->mlx_img->img_ptr)
		err_msg("mlx_new_image failed\n", data, true);
	data->mlx_img->width = WIN_WIDTH;
	data->mlx_img->height = WIN_HEIGHT;
	data->mlx_img->data = mlx_get_data_addr(data->mlx_img->img_ptr,
			&data->mlx_img->bits_per_pixel, &data->mlx_img->line_length,
			&data->mlx_img->endian);
}

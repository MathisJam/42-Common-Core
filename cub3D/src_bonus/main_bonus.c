/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:22:49 by jchen             #+#    #+#             */
/*   Updated: 2025/01/22 19:38:36 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	global_init(t_data *data, char **argv)
{
	init_data(data);
	load_map(data, argv[1]);
	check_map(data);
	get_map_info(data, argv[1]);
	get_floor_ceiling(data);
	init_mlx(data);
	init_textures(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_putstr_fd("Error\nData calloc failed\n", 2);
	if (argc != 2 || check_extension(argv[1], ".cub", ft_strlen(argv[1])) == 1)
		err_msg("please enter : ./cub3D [map.cub]\n", data, true);
	global_init(data, argv);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse_move, data);
	mlx_hook(data->mlx_win, 17, 0, free_all, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, handle_key_release, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop(data->mlx_ptr);
	free_all(data, 0);
}

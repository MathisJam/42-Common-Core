/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:44:29 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/22 19:38:25 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

static void	free_t_texture(t_data *data, t_texture *texture)
{
	if (texture)
	{
		if (texture->img_ptr)
			mlx_destroy_image(data->mlx_ptr, texture->img_ptr);
		if (texture->path)
			free(texture->path);
		free(texture);
	}
}

static void	free_all2(t_data *data)
{
	if (data->ceiling)
		free(data->ceiling);
	if (data->floor)
		free(data->floor);
	free_tab(data->map);
	free_tab(data->f_strings);
	free_tab(data->c_strings);
}

int	free_all(t_data *data, int exit_status)
{
	if (data == NULL)
		exit(exit_status);
	free_t_texture(data, data->mlx_img);
	free_t_texture(data, data->no);
	free_t_texture(data, data->ea);
	free_t_texture(data, data->we);
	free_t_texture(data, data->so);
	if (data->player)
		free(data->player);
	if (data->control)
		free(data->control);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_all2(data);
	if (data)
		free(data);
	exit(exit_status);
}

void	err_msg(char *str, t_data *data, bool to_free)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (to_free == true)
		free_all(data, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:16 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/06 10:10:28 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* Encore une fonction de free, pour le pointeur
*/
void	free_ptr(t_data *data)
{
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	exit (FAIL);
}

/*
* Fonction d'erreur si il y a un soucis avec les images, on suppr tout et on free
*/
void	error_xpm(t_data *data, int i)
{
	int		j;

	j = -1;
	while (++j < i)
		mlx_destroy_image(data->ptr, data->sprite[j]);
	mlx_destroy_window(data->ptr, data->window);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	free_tab(data->map);
	perror("Error\nTexture failed");
	exit(SUCCESS);
}

/*
* Ici on recupere nos fichiers xpm our les transformer en image.
*/
void	*xpm_to_img(t_data *data, char *path, int index)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->ptr, path, &data->img_size,
			&data->img_size);
	if (!img)
		error_xpm(data, index);
	return (img);
}

/*
* Ici on attribue les fichiers xpm au bon sprite[]
*/
void	init_image(t_data *data)
{
	data->sprite[0] = xpm_to_img(data, "./textures/floor.xpm", 0);
	data->sprite[1] = xpm_to_img(data, "./textures/wall.xpm", 1);
	data->sprite[2] = xpm_to_img(data, "./textures/playerup.xpm", 2);
	data->sprite[3] = xpm_to_img(data, "./textures/player.xpm", 3);
	data->sprite[4] = xpm_to_img(data, "./textures/playerleft.xpm", 4);
	data->sprite[5] = xpm_to_img(data, "./textures/player.xpm", 5);
	data->sprite[6] = xpm_to_img(data, "./textures/exit.xpm", 6);
	data->sprite[7] = xpm_to_img(data, "./textures/item.xpm", 7);
}

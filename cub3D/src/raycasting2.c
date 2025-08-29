/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:52:44 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/22 14:18:26 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
Fonction qui determine les distances et mets draw start et draw end a jour

1. Obtiens la distance de l'intersection entre le point et la perpendiculaire du
 mur / cam
2. Obtiens la hauteur de la line via la longueur de l'ecran
3. Calcule le + petit et + grand pixel a dessiner
*/
void	prep_height(t_ray *ray, t_player *player)
{
	if (ray->side == WEST || ray->side == EAST)
	{
		ray->prep_wall_dist = ((double)ray->map_x - player->px + (1
					- ray->step_x) / 2) / ray->ray_dir_x;
	}
	else
		ray->prep_wall_dist = ((double)ray->map_y - player->py + (1
					- ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = WIN_HEIGHT / ray->prep_wall_dist;
	ray->draw_start = -ray->line_height / 2 + ((WIN_HEIGHT / 2)
			* player->cam_height);
	if (ray->draw_start <= 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ((WIN_HEIGHT / 2)
			* player->cam_height);
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

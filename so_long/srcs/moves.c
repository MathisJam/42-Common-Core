/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:29:50 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/06 10:09:50 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* Ici on va parcourir la map et donner les bonnes valeurs a nos variables
ex : si on tombe sur le caractere 'E' alors on a trouve l'exit et
on peut mettre a jour les coordonnees de "end"
*/
void	set_position(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'E')
			{
				data->end_x = j;
				data->end_y = i;
			}
			else if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			else if (data->map[i][j] == 'C')
				data->carrot++;
		}
	}
}

/*
* Ici on gere la position de notre personnage, si il marche sur une piece
on l'enleve et on remet le sprite du sol.
En fonction de la direction (U D S A) on va changer le sprite
et mettre a jour la position du personnage en changeant "player_x -> next_x"
*/
void	player_actualisation(t_data *data, char move)
{
	if (data->map[data->next_y][data->next_x] == 'C')
		data->carrot--;
	data->map[data->next_y][data->next_x] = 'P';
	data->map[data->player_y][data->player_x] = '0';
	mlx_put_image_to_window(data->ptr, data->window,
		data->sprite[0], data->player_x * 64, data->player_y * 64);
	if (move == 'U')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[2], data->next_x * 64, data->next_y * 64);
	else if (move == 'D')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[3], data->next_x * 64, data->next_y * 64);
	else if (move == 'L')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[4], data->next_x * 64, data->next_y * 64);
	else if (move == 'R')
		mlx_put_image_to_window(data->ptr, data->window,
			data->sprite[5], data->next_x * 64, data->next_y * 64);
	data->player_x = data->next_x;
	data->player_y = data->next_y;
}

/*
*Ici on donne les valeurs des next,
si on monte alors on decremente car on commence d'en haut
et si on va a gauche alors on decremente car on lit a partir de la droite
*/
void	next_move(t_data *data, char c)
{
	data->next_x = data->player_x;
	data->next_y = data->player_y;
	if (c == 'U')
		data->next_y = data->player_y - 1;
	else if (c == 'D')
		data->next_y = data->player_y + 1;
	else if (c == 'L')
		data->next_x = data->player_x - 1;
	else if (c == 'R')
		data->next_x = data->player_x + 1;
}

/*
* Ici on va compter le nombre de mouvements qu'il a fallu pour finir le jeu
si on arrive pas sur la sortie ('E') on augmente le compteur, si on arrive
sur la sortie et qu'il n'y a plus d'item sur la map
alors on peut afficher le message de reussite et tout free !
*/
void	move(t_data *data, char move)
{
	next_move(data, move);
	if (!(data->next_x > (data->x - 1) / 64 || data->next_x < 0
			|| data->next_y > (data->y - 1) / 64 || data->next_y < 0)
		&& (data->map[data->next_y][data->next_x] != '1'
		|| (data->map[data->next_y][data->next_x] == 'E' && data->carrot == 0)))
	{
		if (data->map[data->next_y][data->next_x] == 'E' && data->carrot == 0)
		{
			ft_printf("\rMovement count : %d", data->nb_move + 1);
			ft_printf("\nYAY! WELL DONE !\n");
			free_all(data);
		}
		else if (data->map[data->next_y][data->next_x] != 'E')
		{
			data->nb_move++;
			player_actualisation(data, move);
		}
	}
}

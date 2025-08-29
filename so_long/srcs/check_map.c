/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:21 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/06 10:06:52 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* on check si la ligne est bien fermee
*/
int	line_check(t_data *data, char **map, int i, int len)
{
	int	j;

	j = -1;
	if (ft_strlen(map[i]) != len - 1 || map[i][len - 2] != '1')
		return (FAIL);
	while (++j < data->x / 64)
	{
		if (map[i][j] != '1')
			return (FAIL);
	}
	return (SUCCESS);
}

/*
* Ici on regarde la taille de la map.
nos tiles font 64 donc on divise par 64 pour mettre la limite, on check aussi
si les colonnes sont fermees par des 1 (les murs)
*/
int	size_check(t_data *data, char **map)
{
	int		len;
	int		i;

	len = ft_strlen(map[0]);
	i = -1;
	while (++i < data->x / 64)
	{
		if (map[0][i] != '1')
			return (FAIL);
	}
	i = -1;
	while (++i < ((data->y / 64) - 1))
	{
		if (ft_strlen(map[i]) != len || map[i][0] != '1'
			|| map[i][len - 2] != '1')
			return (FAIL);
	}
	if (line_check(data, map, i, len) == 1)
		return (FAIL);
	return (SUCCESS);
}

/*
* On check le nombre de caractere P et E dans la map pour
voir si il y en a bien 1 et seulement 1
*/
int	player_end_check(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	player = 0;
	exit = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'E')
				exit++;
		}
	}
	if (player != 1 || exit != 1)
		return (FAIL);
	return (SUCCESS);
}

/*
* Ici on va utiliser nos fonctions de check et afficher un message
d'erreur approprie si la fonction nous renvoie 1
*/
int	map_check(t_data *data)
{
	if (size_check(data, data->map) == 1)
	{
		perror("Error\nInvalid map");
		return (FAIL);
	}
	if (player_end_check(data->map) == 1 || data->carrot == 0)
	{
		perror("Error\nOnly 1 'P', 1 'E' and at least 1 'C' in the map");
		return (FAIL);
	}
	if (flood_fill(data) == 1)
	{
		perror("Error\nCan't reach exit or all collectibles");
		return (FAIL);
	}
	else
		return (SUCCESS);
}

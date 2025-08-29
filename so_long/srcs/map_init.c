/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:30 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/26 18:14:32 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Fonction pour free le tableau (**map)
 */
void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

/*
* Malloc de la map, on lis la map avec get next line
 pour recup ce qu'il y a dans le fd
*/
char	**maploc(int count_line, char *map)
{
	char	**tab;
	int		i;
	int		fd;

	fd = open(map, 0);
	tab = NULL;
	if (count_line != 0)
		tab = malloc(sizeof(char *) * (count_line + 1));
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (count_line > ++i)
	{
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
		{
			free_tab(tab);
			perror("Error\nMemory allocation failed\n");
			return (NULL);
		}
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}

/*
* On va open la map pour recuperer sa longueur et largeur
et compter le nombre de ligne pour ensuite la malloc dans notre
fonction maploc, tout ca est compte en nombre de "bloc", on multiplie donc
par 64 (la taille de nos tiles) pour convertir les dimensions en pixels.
*/
void	map_read(t_data *data, char *map)
{
	int		fd;
	char	*line;
	size_t	len;
	int		count_line;

	len = 0;
	fd = open(map, 0);
	if (fd == -1)
		free_ptr(data);
	count_line = 0;
	line = get_next_line(fd);
	if (line != 0)
		len = ft_strlen(line) - 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count_line++;
	}
	free(line);
	data->x = (int)len * 64;
	data->y = count_line * 64;
	close(fd);
	data->map = maploc(count_line, map);
}

/*
* Fonction pour mettre les images sur la map,
on choisit quel sprite mettre en fonction
de quel caractere on trouve sur les coordones i et j
*/
void	put_image_on_map(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->ptr, data->window, data->sprite[1], j
			* 64, i * 64);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->ptr, data->window, data->sprite[3], j
			* 64, i * 64);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->ptr, data->window, data->sprite[6], j
			* 64, i * 64);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->ptr, data->window, data->sprite[7], j
			* 64, i * 64);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->ptr, data->window, data->sprite[0], j
			* 64, i * 64);
	else
	{
		perror("Error\nInvalid map\n");
		free_all(data);
	}
}

/*
 * Ici on initialise l'image et la map avec les bonnes dimensions
 */
void	map_init_window(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	init_image(data);
	while (++i < (data->y / 64))
	{
		while (++j < (data->x / 64))
			put_image_on_map(data, i, j);
		j = -1;
	}
}

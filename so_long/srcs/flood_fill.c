/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:09 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/10 16:21:55 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strdup(const char *s)
{
	int		size;
	char	*tab;
	int		i;

	i = 0;
	while (s[i])
		i++;
	size = i;
	tab = malloc(sizeof(char) * size + 1);
	if (tab == NULL)
		return (NULL);
	ft_strcpy(tab, s);
	return (tab);
}

/*
 * On fait un potit strdup pour la map
 */
char	**dup_map(t_data *data, char **map)
{
	char	**dup;
	int		i;

	dup = malloc(sizeof(char *) * ((data->y / 64) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < (data->y / 64))
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			free_tab(dup);
			return (NULL);
		}
	}
	dup[i] = NULL;
	return (dup);
}

/*
* La fonction de fill classique, on check aussi le nombre de'item'
pour ensuite verifier qu'on a bien le meme nombre d'item'
*/
void	fill(t_data *data, char **map, int y, int x)
{
	if (map[y][x] == 'C')
		data->check_carrot++;
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F' && map[y + 1][x] != 'E')
	{
		map[y][x] = 'F';
		fill(data, map, y + 1, x);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, y - 1, x);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, y, x + 1);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, y, x - 1);
	}
	map[y][x] = 'F';
}

/*
* on va recup la map avec notre fonction dup, on fill tout avec la fonction fill
et ensuite on check notre nombre d'item et si la sortie est OK
*/
int	flood_fill(t_data *data)
{
	char	**dup;

	dup = dup_map(data, data->map);
	if (!dup)
		return (1);
	data->check_carrot = 0;
	fill(data, dup, data->player_y, data->player_x);
	if (dup[data->end_y][data->end_x] == 'F'
		&& data->check_carrot == data->carrot)
	{
		free_tab(dup);
		return (SUCCESS);
	}
	free_tab(dup);
	return (FAIL);
}

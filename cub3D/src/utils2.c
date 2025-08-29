/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:52:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/24 18:54:54 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	not_empty(char **map, int y, int x, t_data *data)
{
	if (map[y + 1] && map[y - 1] && map[y + 1][x - 1] && map[y + 1][x + 1]
		&& map[y - 1][x - 1] && map[y - 1][x + 1] && (map[y - 1][x - 1] != '\0'
			&& map[y - 1][x] != '\0' && map[y - 1][x - 1] != '\0' && map[y][x
			- 1] != '\0' && map[y][x] != '\0' && map[y][x + 1] != '\0' && map[y
			+ 1][x - 1] != '\0' && map[y + 1][x] != '\0' && map[y + 1][x
			+ 1] != '\0'))
		return ;
	err_msg("Player outside the map\n", data, true);
}

int	invalid_char(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\t')
				err_msg("No tab allowed, please use space\n", data, true);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& !is_space(map[i][j]))
				return (1);
		}
	}
	return (0);
}

void	skip_one_line(int fd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < 1)
	{
		tmp = get_next_line(fd);
		printf("%s", tmp);
		free(tmp);
	}
}

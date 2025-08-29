/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:36:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/24 18:52:26 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (is_space(line[i]) || line[i] == '1'))
		i++;
	if (line[i] == '\0')
		return (0);
	else
		return (1);
}

static int	double_char(char **map, t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				not_empty(map, i, j, data);
				flag++;
			}
		}
	}
	if (flag != 1)
		return (1);
	else
		return (0);
}

void	close_check2(t_data *data, char **map, int i, int l)
{
	int	next_l;

	if (!map[i + 1])
		return ;
	next_l = ft_strlen(map[i + 1]) - 1;
	if (next_l - 1 < l)
	{
		while (l-- > next_l)
			if (map[i][l] != '1')
				err_msg("Map not closed", data, true);
	}
	else if (next_l - 1 > l)
	{
		while (l++ < next_l - 1)
			if (map[i + 1][l] != '1')
				err_msg("Map not closed", data, true);
	}
	if (map[i + 1][next_l - 1] != '1')
		err_msg("Map not closed", data, true);
}

static int	close_check(t_data *data, char **map)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	if (check_line(map[0]) || check_line(map[(data->row_nbr) - 1]))
		return (1);
	while (++i < (data->row_nbr))
	{
		j = 0;
		while (is_space(map[i][j]))
			j++;
		l = ft_strlen(map[i]) - 1;
		while (l > 0 && is_space(map[i][l]))
			l--;
		if (map[i][j] != '1' || map[i][l] != '1')
			return (1);
		close_check2(data, map, i, l);
		while (map[i][j++])
			validate_player(data, data->map, i, j);
	}
	if (i < 3)
		err_msg("Map not closed", data, true);
	return (0);
}

void	check_map(t_data *data)
{
	if (!data->map)
		err_msg("Map not found in CHECK MAP\n", data, true);
	if (data->map_start < 7)
		err_msg("Don't forget the paths to the textures\n", data, true);
	if (invalid_char(data->map, data))
		err_msg("Invalid char in map, or not at the end\n", data, true);
	if (close_check(data, data->map))
		err_msg("Map is not closed, or is not at the end\n", data, true);
	if (double_char(data->map, data))
		err_msg("Need one and only one N S W E char\n", data, true);
}

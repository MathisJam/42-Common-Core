/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:51:04 by jchen             #+#    #+#             */
/*   Updated: 2025/01/24 18:56:08 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	is_map_start(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) == 1)
		return (false);
	while (str && (str[i] == '1' || str[i] == ' '))
		i++;
	if (str[i] == '\n' && i > 1)
		return (true);
	return (false);
}

static int	map_line_nbr(char *str, t_data *data)
{
	int		i;
	int		fd;
	char	*line;
	int		start;
	int		j;

	i = 0;
	start = 0;
	fd = safe_open_fd(str, O_RDONLY, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		j = 0;
		while (line && is_char(line[j]))
			j++;
		if (j > 1 && (line[j] == '\n'))
		{
			start = i;
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), start);
}

static void	skip_not_map_lines(int fd, int start)
{
	int		i;
	int		j;
	bool	flag;
	char	*tmp;

	i = 0;
	flag = false;
	while (++i < start)
	{
		tmp = get_next_line(fd);
		j = 0;
		while (tmp[j] == '1' || tmp[j] == '0' || tmp[j] == 'N' || tmp[j] == 32
			|| tmp[j] == 'S' || tmp[j] == 'W' || tmp[j] == 'E')
		{
			if (tmp[j + 1] && i == 1 && !flag && (tmp[j + 1] == '\n' || tmp[j
						+ 1] == '\0'))
			{
				flag = true;
				start -= 1;
				i--;
			}
			j++;
		}
		free(tmp);
	}
}

void	load_map(t_data *data, char *map)
{
	int		fd;
	char	*line;
	int		start;
	int		i;

	i = 0;
	start = 0;
	fd = safe_open_fd(map, O_RDONLY, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		if (is_map_start(line) == true)
		{
			start = i;
			data->column_nbr = ft_strlen(line) - 1;
		}
		if (start)
			data->row_nbr++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	data->map = malloc_map(map, data);
}

char	**malloc_map(char *map, t_data *data)
{
	char	**map_array;
	int		fd;
	int		i;

	data->map_start = map_line_nbr(map, data);
	if (!(data->map_start) || data->row_nbr == 0)
		err_msg("Map not found\n", data, true);
	fd = open(map, O_RDONLY);
	map_array = malloc_fd((data->row_nbr + 1) * sizeof(char *), data, &fd);
	skip_not_map_lines(fd, data->map_start);
	i = -1;
	while (data->row_nbr > ++i)
	{
		map_array[i] = get_next_line(fd);
		if (!map_array[i])
		{
			close(fd);
			err_msg("Copy map process failed\n", data, true);
		}
		if (map_array[i][0] == '\n' || map_array[i][0] == '\0')
			skip_one_line(fd);
	}
	map_array[i] = NULL;
	return (close(fd), map_array);
}

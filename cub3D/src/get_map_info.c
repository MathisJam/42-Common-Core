/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:38:11 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/22 15:47:23 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*catch_path(char *line)
{
	char	*temp;

	temp = line;
	if (ft_strlen(temp) < 22)
		return (NULL);
	while (*temp && *(temp + 1) && (*temp != '.' || *(temp + 1) != '/'))
	{
		temp++;
		if (!*temp || !*(temp + 1))
			return (NULL);
	}
	return (temp);
}

static int	is_texture(t_data *data, char *line)
{
	if (ft_strstr(line, "NO") && !data->no->path)
		return (NORTH);
	else if (ft_strstr(line, "EA") && !data->ea->path)
		return (EAST);
	else if (ft_strstr(line, "WE") && !data->we->path)
		return (WEST);
	else if (ft_strstr(line, "SO") && !data->so->path)
		return (SOUTH);
	else if (ft_strstr(line, "F") && !data->f_strings)
		return (FNUM);
	else if (ft_strstr(line, "C") && !data->c_strings)
		return (CNUM);
	return (-1);
}

static void	get_textures_info(t_data *data, char *line, int code)
{
	int	j;

	j = -1;
	if (code == NORTH && catch_path(line) != NULL)
		data->no->path = strdup_without_n(catch_path(line));
	else if (code == EAST && catch_path(line) != NULL)
		data->ea->path = strdup_without_n(catch_path(line));
	else if (code == WEST && catch_path(line) != NULL)
		data->we->path = strdup_without_n(catch_path(line));
	else if (code == SOUTH && catch_path(line) != NULL)
		data->so->path = strdup_without_n(catch_path(line));
	else if (code == FNUM)
		data->f_strings = ft_split(line, ',');
	else if (code == CNUM)
		data->c_strings = ft_split(line, ',');
}

static bool	valid_textures_info(t_data *data)
{
	if (!data->no->path || !data->ea->path || !data->we->path || !data->so->path
		|| !data->f_strings || !data->c_strings)
		return (false);
	return (true);
}

void	get_map_info(t_data *data, char *map)
{
	int		fd;
	char	*line;
	int		code;

	code = 0;
	fd = safe_open_fd(map, O_RDONLY, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		code = is_texture(data, line);
		if (code > -1)
			get_textures_info(data, line, code);
		free(line);
		line = get_next_line(fd);
	}
	if (valid_textures_info(data) == false)
	{
		free(line);
		close(fd);
		err_msg("Missing textures paths\n", data, true);
	}
	free(line);
	close(fd);
}

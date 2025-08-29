/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:32:14 by mjameau           #+#    #+#             */
/*   Updated: 2024/06/14 13:02:16 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *line_buf)
{
	int		i;
	char	*rest;

	i = 0;
	while (line_buf[i] != '\n' && line_buf[i] != '\0')
		i++;
	if (line_buf[0] == '\0' || line_buf[1] == '\0')
		return (NULL);
	rest = ft_substr(line_buf, i + 1, ft_strlen(line_buf) - i);
	if (line_buf[i] == '\n')
		line_buf[i + 1] = '\0';
	else
		line_buf[i] = '\0';
	return (rest);
}

static char	*ft_fill(int fd, char *rest, char *buffer)
{
	ssize_t	read_buf;
	char	*temp;

	read_buf = 1;
	while (read_buf > 0)
	{
		read_buf = read(fd, buffer, BUFFER_SIZE);
		if (read_buf == -1 || read_buf > BUFFER_SIZE)
		{
			free(rest);
			return (NULL);
		}
		else if (read_buf == 0)
			break ;
		buffer[read_buf] = '\0';
		if (!rest)
			rest = ft_strdup("");
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rest);
		free(buf);
		rest = NULL;
		buf = NULL;
		return (NULL);
	}
	line = ft_fill(fd, rest, buf);
	free(buf);
	if (!line)
		return (NULL);
	rest = get_line(line);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:00:14 by jchen             #+#    #+#             */
/*   Updated: 2025/01/19 12:58:04 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	safe_open_fd(char *file, int flag, t_data *data)
{
	int	fd;

	fd = open(file, flag);
	if (fd < 0)
		err_msg("Failed to open fd\n", data, true);
	return (fd);
}

void	*malloc_fd(size_t bytes, t_data *data, int *fd)
{
	void	*allocation;

	allocation = malloc(bytes);
	if (!allocation)
	{
		close(*fd);
		err_msg("Malloc failed\n", data, true);
	}
	return (allocation);
}

void	*safe_calloc(size_t nmemb, size_t bytes, t_data *data)
{
	void	*allocation;

	allocation = ft_calloc(nmemb, bytes);
	if (!allocation)
		err_msg("Calloc failes\n", data, true);
	return (allocation);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:18:43 by jchen             #+#    #+#             */
/*   Updated: 2025/01/24 18:51:13 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_extension(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = len - 1;
	j = 3;
	if (i <= j)
		return (1);
	while (big[i] == little[j])
	{
		if (little[j] == big[i] && j == 0)
			return (0);
		j--;
		i--;
	}
	return (1);
}

char	*strdup_without_n(const char *s)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!temp)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

int	is_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || (c == ' '));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:16:36 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/10 14:50:01 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

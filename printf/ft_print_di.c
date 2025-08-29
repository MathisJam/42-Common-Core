/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:34:00 by mjameau           #+#    #+#             */
/*   Updated: 2024/06/05 17:25:54 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(int n)
{
	int				nb;
	unsigned int	i;

	i = 1;
	if (n == INT_MIN)
	{
		ft_putnbr_fd(n, 1);
		return (11);
	}
	if (n < 0)
	{
		i++;
		nb = -n;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	return (i);
}

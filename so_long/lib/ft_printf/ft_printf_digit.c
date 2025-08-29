/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:16:21 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/06 10:16:22 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_int(int n)
{
	int	value_int;

	value_int = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		value_int++;
	}
	if (n == 0)
	{
		value_int++;
		return (value_int);
	}
	while (n > 0)
	{
		n /= 10;
		value_int++;
	}
	return (value_int);
}

int	ft_print_int(int n)
{
	int	value_int;

	ft_putnbr(n);
	value_int = len_int(n);
	return (value_int);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

int	ft_print_unsigned_int(unsigned int n)
{
	int	value_unsint;

	ft_put_unsigned_nbr(n);
	value_unsint = 0;
	if (n == 0)
	{
		value_unsint++;
		return (value_unsint);
	}
	while (n > 0)
	{
		n = n / 10;
		value_unsint++;
	}
	return (value_unsint);
}

void	ft_put_unsigned_nbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_put_unsigned_nbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
}

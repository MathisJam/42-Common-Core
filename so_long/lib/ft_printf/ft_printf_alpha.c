/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:16:16 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/06 10:16:18 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	int	value_char;

	value_char = write(1, &c, 1);
	return (value_char);
}

int	ft_print_str(char *str)
{
	int	value_str;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	value_str = write(1, str, ft_strlen(str));
	return (value_str);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	value_ptr;

	value_ptr = 0;
	if (ptr == 0)
	{
		value_ptr = write(1, "(nil)", 5);
		return (value_ptr);
	}
	else
		value_ptr = write(1, "0x", 2);
	ft_putptr(ptr);
	value_ptr += ft_len_ptr(ptr);
	return (value_ptr);
}

void	ft_putptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr > 9)
			ft_putchar((ptr - 10 + 'a'));
		else
			ft_putchar((ptr + '0'));
	}
}

int	ft_len_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

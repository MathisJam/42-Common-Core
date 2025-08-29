/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:16:24 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/06 10:16:25 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int hex)
{
	int	value_hexa;

	value_hexa = 0;
	if (hex >= 16)
	{
		ft_print_hexa(hex / 16);
		ft_print_hexa(hex % 16);
	}
	else
	{
		if (hex > 9)
			ft_putchar((hex - 10 + 'a'));
		else
			ft_putchar((hex + '0'));
	}
	value_hexa = ft_len_hexa(hex);
	return (value_hexa);
}

int	ft_print_hexa_caps(unsigned int hex)
{
	int	value_hexa;

	value_hexa = 0;
	if (hex >= 16)
	{
		ft_print_hexa_caps(hex / 16);
		ft_print_hexa_caps(hex % 16);
	}
	else
	{
		if (hex > 9)
			ft_putchar((hex - 10 + 'A'));
		else
			ft_putchar((hex + '0'));
	}
	value_hexa = ft_len_hexa(hex);
	return (value_hexa);
}

int	ft_len_hexa(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex != 0)
	{
		len++;
		hex = hex / 16;
	}
	return (len);
}

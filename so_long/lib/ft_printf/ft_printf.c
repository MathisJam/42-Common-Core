/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:16:27 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/06 10:16:28 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		value;
	va_list	args;

	i = 0;
	value = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			value += ft_format(str[i + 1], args);
			i++;
		}
		else
			value += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (value);
}

int	ft_format(char c, va_list args)
{
	int	value_format;

	value_format = 0;
	if (c == '%')
		value_format = ft_print_char('%');
	else if (c == 'c')
		value_format = ft_print_char(va_arg(args, int));
	else if (c == 's')
		value_format = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		value_format = ft_print_ptr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		value_format = ft_print_int(va_arg(args, int));
	else if (c == 'u')
		value_format = ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'x')
		value_format = ft_print_hexa(va_arg(args, unsigned int));
	else if (c == 'X')
		value_format = ft_print_hexa_caps(va_arg(args, unsigned int));
	return (value_format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:16:30 by mjameau           #+#    #+#             */
/*   Updated: 2024/09/10 14:49:57 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
int		ft_format(char c, va_list args);
int		ft_strlen(char *s);
void	ft_putchar(char c);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long ptr);
void	ft_putptr(unsigned long ptr);
int		ft_len_ptr(unsigned long ptr);
int		len_int(int n);
int		ft_print_int(int n);
void	ft_putnbr(int n);
int		ft_print_unsigned_int(unsigned int n);
void	ft_put_unsigned_nbr(unsigned int nb);
int		ft_print_hexa(unsigned int hex);
int		ft_print_hexa_caps(unsigned int hex);
int		ft_len_hexa(unsigned int hex);

#endif
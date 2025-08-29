/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:50:09 by mjameau           #+#    #+#             */
/*   Updated: 2024/06/05 17:26:34 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_print_c(char c);
int	ft_print_s(char *s);

int	ft_print_p(void *addr);
int	ft_print_xx(unsigned int num, const char format);
int	ft_print_u(unsigned int n);
int	ft_print_di(int n);

#endif

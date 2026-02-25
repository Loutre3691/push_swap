/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:08:16 by slaabid           #+#    #+#             */
/*   Updated: 2026/02/21 21:32:19 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_putpointer(unsigned long long ptr)
{
	int	begin;
	int	nxt;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	begin = ft_putstr_fd("0x", 1);
	if (begin == -1)
		return (-1);
	nxt = ft_puthex((unsigned long long)ptr, 'x');
	if (nxt == -1)
		return (-1);
	return (begin + nxt);
}

int	ft_format_fd(char c, va_list args, int fd)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_fd(va_arg(args, int), fd);
	else if (c == 's')
		count = ft_putstr_fd(va_arg(args, char *), fd);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_fd(va_arg(args, int), fd);
	else if (c == '%')
		count = ft_putchar_fd('%', fd);
	if (count == -1)
		return (-1);
	return (count);
}

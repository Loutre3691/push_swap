/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:54:03 by slaabid           #+#    #+#             */
/*   Updated: 2026/02/21 21:29:45 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		ret;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			ret = ft_format_fd(format[++i], args, fd);
		else
			ret = ft_putchar_fd(format[i], fd);
		if (ret == -1)
			return (va_end(args), -1);
		count += ret;
		i++;
	}
	va_end(args);
	return (count);
}

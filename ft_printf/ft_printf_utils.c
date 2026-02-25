/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:13:06 by slaabid           #+#    #+#             */
/*   Updated: 2026/02/22 23:52:58 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(unsigned int c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *str, int fd)
{
	int	count;
	int	ret;

	if (!str)
		return (ft_putstr_fd("(null)", fd));
	count = 0;
	while (*str)
	{
		ret = ft_putchar_fd(*str, fd);
		if (ret == -1)
			return (-1);
		count += ret;
		str++;
	}
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		count;
	int		ret;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
	{
		ret = ft_putnbr_fd((int)(nb / 10), fd);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (ft_putchar_fd((char)(nb % 10 + '0'), fd) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putunsigned(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar_fd((n % 10) + '0', 1);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_puthex(unsigned long long n, char format)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 16)
	{
		ret = ft_puthex(n / 16, format);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (format == 'x')
		ret = ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	else
		ret = ft_putchar_fd("0123456789ABCDEF"[n % 16], 1);
	if (ret == -1)
		return (-1);
	return (count + ret);
}

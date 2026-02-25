/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:47:14 by slaabid           #+#    #+#             */
/*   Updated: 2026/02/21 21:29:36 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...)__attribute__((format(printf, 1, 2)));
int	ft_putchar(unsigned int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned long long n, char format);
int	ft_putpointer(unsigned long long ptr);
int	ft_format(char c, va_list args);

int	ft_printf_fd(int fd, const char *format, ...);
int	ft_putchar_fd(unsigned int c, int fd);
int	ft_putstr_fd(char *str, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_format_fd(char c, va_list args, int fd);

#endif
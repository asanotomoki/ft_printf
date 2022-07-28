/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:57:08 by test              #+#    #+#             */
/*   Updated: 2022/07/28 16:23:05 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(int c, ssize_t len)
{
	len = ft_intmaxch(len, 1);
	if (len == -1)
		return (-1);
	ft_putchar_fd(c, 1);
	return (len);
}

int	ft_putformat(const char *fmt, va_list *args, ssize_t len)
{
	if (*fmt == 'c')
		len = ft_putchar(va_arg(*args, int), len);
	else if (*fmt == 's')
		len = ft_putstr(va_arg(*args, char *), len);
	else if (*fmt == 'p')
		len = ft_putptr(va_arg(*args, unsigned long int), len);
	else if (*fmt == 'd' || *fmt == 'i')
		len = ft_putnbr(va_arg(*args, int), len);
	else if (*fmt == 'u')
		len = ft_putnbr_base(va_arg(*args, unsigned int), 10, len, *fmt);
	else if (*fmt == 'x')
		len = ft_putnbr_base(va_arg(*args, unsigned int), 16, len, *fmt);
	else if (*fmt == 'X')
		len = ft_putnbr_base(va_arg(*args, unsigned int), 16, len, *fmt);
	else if (*fmt == '%')
		len = ft_putchar('%', len);
	return (len);
}

ssize_t	ft_vprintf(const char *fmt, va_list *args)
{
	ssize_t	len;

	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			len = ft_putformat(fmt, args, len);
		}
		else
			len = ft_putchar(*fmt, len);
		if (len == -1)
			return (-1);
		fmt++;
	}
	return (len);
}

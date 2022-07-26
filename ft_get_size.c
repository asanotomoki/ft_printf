/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:12:49 by test              #+#    #+#             */
/*   Updated: 2022/07/26 17:19:40 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_getstr_size(char *str)
{
	size_t	len;

	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	return (len);
}

size_t	ft_getnbr_base(int nbr, int base_len)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

size_t	ft_getargs_size(const char *fmt, va_list s_args)
{
	size_t	len;

	if (*fmt == 'c')
		len = 1;
	else if (*fmt == 's')
		len = ft_getstr_size(va_arg(s_args, char *));
	// else if (*fmt == 'p')
	// 	len = ft_putchar();
	else if (*fmt == 'd' || *fmt == 'i')
		len = ft_getnbr_base(va_arg(s_args, int), 10);
	else if (*fmt == 'u')
		len = ft_getnbr_base(va_arg(s_args, unsigned int), 10);
	else if (*fmt == 'x' || *fmt == 'X')
		len = ft_getnbr_base(va_arg(s_args, unsigned int), 16);
	else if (*fmt == '%')
		len = 1;
	else
		len = 0;
	return (len);
}

ssize_t	ft_printf_size(const char *fmt, va_list s_args)
{
	ssize_t	len;

	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			len += ft_getargs_size(fmt, s_args);
		}
		else
			len++;
		if (len > INT_MAX)
			return (-1);
		fmt++;
	}
	return (len);
}

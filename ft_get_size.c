/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:12:49 by test              #+#    #+#             */
/*   Updated: 2022/07/27 13:03:13 by test             ###   ########.fr       */
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

size_t	ft_getnbr_base(unsigned long int nbr, int base_len)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

size_t ft_getnbr_digit(int nbr)
{
	size_t	i;

	i = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

size_t	ft_getargs_size(const char *fmt, va_list *s_args)
{
	size_t	len;

	len = 0;
	if (*fmt == 'c')
		len = 1;
	else if (*fmt == 's') {
		// printf("%s", va_arg(*s_args, char *));s
		len = ft_getstr_size(va_arg(*s_args, char *));
	}
	else if (*fmt == 'p')
	{
		len = 2;
		len += ft_getnbr_base(va_arg(*s_args, unsigned long int), 16);
	}
	else if (*fmt == 'd' || *fmt == 'i')
		len = ft_getnbr_digit(va_arg(*s_args, int));
	else if (*fmt == 'u')
		len = ft_getnbr_base(va_arg(*s_args, unsigned int), 10);
	else if (*fmt == 'x' || *fmt == 'X')
		len = ft_getnbr_base(va_arg(*s_args, unsigned int), 16);
	else if (*fmt == '%')
		len = 1;
	else
		len = 0;
	return (len);
}

ssize_t	ft_printf_size(const char *fmt, va_list *s_args)
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

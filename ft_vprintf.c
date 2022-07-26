/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:57:08 by test              #+#    #+#             */
/*   Updated: 2022/07/26 22:44:35 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base, size_t base_len)
{
	if (nbr == 0)
		return ;
	ft_putnbr_base(nbr / base_len, base, base_len);
	ft_putchar_fd(base[nbr % base_len], 1);
}

void	ft_putstr(char *str)
{
	if (!str)
		ft_putstr_fd("(NULL)", 1);
	else
		ft_putstr_fd(str, 1);
}

void	ft_putargs(const char *fmt, va_list args)
{

	if (*fmt == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*fmt == 's')
		ft_putstr(va_arg(args, char *));
	// else if (*fmt == 'p')
	// 	len = ft_putchar();
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*fmt == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (*fmt == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (*fmt == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (*fmt == '%')
		ft_putchar_fd('%', 1);
}

int	ft_vprintf(const char *fmt, va_list args)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_putargs(fmt, args);
		}
		else
			ft_putchar_fd(*fmt, 1);
		fmt++;
	}
	return (0);
}

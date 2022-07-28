/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:03:23 by test              #+#    #+#             */
/*   Updated: 2022/07/28 16:22:16 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_recursive(unsigned int nbr, int base_len, char sp)
{
	if (nbr == 0)
		return ;
	ft_putnbr_recursive(nbr / base_len, base_len, sp);
	if (nbr % base_len < 10)
		ft_putchar_fd((nbr % base_len) + '0', 1);
	else
	{
		if (sp == 'X')
			ft_putchar_fd((nbr % base_len) - 10 + 'A', 1);
		else
			ft_putchar_fd((nbr % base_len) - 10 + 'a', 1);
	}
}

ssize_t	ft_putnbr_base(unsigned int nbr, int base_len, ssize_t len, char sp)
{
	len = ft_intmaxch(len, ft_getnbr_base(nbr, base_len));
	if (len == -1)
		return (-1);
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
	}	
	ft_putnbr_recursive(nbr, base_len, sp);
	return (len);
}

ssize_t	ft_putnbr(int nbr, ssize_t len)
{
	len = ft_intmaxch(len, ft_getnbr_digit(nbr));
	if (len == -1)
		return (-1);
	ft_putnbr_fd(nbr, 1);
	return (len);
}

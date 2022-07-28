/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:00:07 by test              #+#    #+#             */
/*   Updated: 2022/07/28 16:21:45 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_recursive(unsigned long int nbr, int base_len, char sp)
{
	if (nbr == 0)
		return ;
	ft_putptr_recursive(nbr / base_len, base_len, sp);
	if (nbr % base_len < 10)
		ft_putchar_fd((nbr % base_len) + '0', 1);
	else
		ft_putchar_fd((nbr % base_len) - 10 + 'a', 1);
}

ssize_t	ft_putptr(unsigned long int ptr, ssize_t len)
{
	len = ft_intmaxch(len, ft_getptr_len(ptr) + 2);
	if (len == -1)
		return (-1);
	write(1, "0x", 2);
	if (ptr == 0)
		write(1, "0", 1);
	else
		ft_putptr_recursive(ptr, 16, 'p');
	return (len);
}

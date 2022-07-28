/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:36:14 by test              #+#    #+#             */
/*   Updated: 2022/07/28 16:21:17 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_intmaxch(ssize_t len, size_t c_len)
{
	if (c_len + len > INT_MAX)
		return (-1);
	return (len + c_len);
}

size_t	ft_printf_strlen(const char *str)
{
	size_t	len;

	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	return (len);
}

size_t	ft_getptr_len(unsigned long int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

size_t	ft_getnbr_base(unsigned int nbr, int base_len)
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

size_t	ft_getnbr_digit(int nbr)
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

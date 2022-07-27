/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:54:16 by test              #+#    #+#             */
/*   Updated: 2022/07/28 01:26:00 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr(char *str, ssize_t len)
{
	len = ft_intmaxch(len, ft_printf_strlen(str));
	if (len == -1)
		return (-1);
	if (!str)
		ft_putstr_fd("(null)", 1);
	else
		ft_putstr_fd(str, 1);
	return (len);
}

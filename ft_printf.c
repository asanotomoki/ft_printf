/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:38:30 by test              #+#    #+#             */
/*   Updated: 2022/07/26 22:44:56 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	va_list	s_args;
	ssize_t	len;

	va_start(args, fmt);
	va_copy(s_args, args);
	len = ft_printf_size(fmt, s_args);
	if (len == -1)
	{
		va_end(args);
		va_end(s_args);
		return (-1);
	}
	ft_vprintf(fmt, args);
	va_end(args);
	va_end(s_args);
	return (len);
}

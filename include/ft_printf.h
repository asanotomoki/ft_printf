/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:02:33 by test              #+#    #+#             */
/*   Updated: 2022/07/26 21:55:46 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

int		ft_printf(const char *format, ...);
ssize_t	ft_printf_size(const char *fmt, va_list s_args);
void	ft_putnbr_base(int nbr, char *base, size_t base_len);
void	ft_putstr(char *str);
#endif

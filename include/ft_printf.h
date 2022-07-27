/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:02:33 by test              #+#    #+#             */
/*   Updated: 2022/07/28 02:32:15 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdint.h>

int		ft_printf(const char *format, ...);
ssize_t	ft_printf_size(const char *fmt, va_list *s_args);
ssize_t	ft_vprintf(const char *fmt, va_list *args);
ssize_t	ft_intmaxch(ssize_t len, size_t c_len);
size_t	ft_printf_strlen(const char *str);
size_t	ft_getnbr_base(unsigned int nbr, int base_len);
size_t	ft_getnbr_digit(int nbr);
ssize_t	ft_putnbr(int nbr, ssize_t len);
ssize_t	ft_putnbr_base(unsigned int nbr, int base_len, ssize_t len, char sp);
ssize_t	ft_putstr(char *str, ssize_t len);
ssize_t	ft_putptr(unsigned long int ptr, ssize_t len);
size_t	ft_getptr_len(unsigned long int nbr);

#endif

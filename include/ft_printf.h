/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:02:33 by test              #+#    #+#             */
/*   Updated: 2022/07/27 00:24:56 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

int		ft_printf(const char *format, ...);
ssize_t	ft_printf_size(const char *fmt, va_list *s_args);
int		ft_vprintf(const char *fmt, va_list *args);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:14:06 by test              #+#    #+#             */
/*   Updated: 2022/07/28 02:26:33 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>

int main() {
	char *null_str;

	null_str = "abcdef";
	printf(" : %d\n", ft_printf("%s %p", null_str, null_str));
	printf(" : %d\n", printf("%s %p", null_str, null_str));
	return (0);
}

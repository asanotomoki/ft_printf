/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:14:06 by test              #+#    #+#             */
/*   Updated: 2022/07/26 22:43:02 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>

int main() {
	int i = 0;
	printf(" %d \n", ft_printf("ft %s %s %s ", "test", "te", "st"));
	printf(" %d \n", printf("or %s %s %s ", "test", "te", "st"));
	return (0);
}
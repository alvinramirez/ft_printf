/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:49:00 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/10 21:50:05 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_character(char character)
{
	return (write(1, &character, 1));
}

int	ft_print_string(char *string)
{
	int	len;

	if (!string)
		string = "(null)";
	len = 0;
	while (*string)
		len += write(1, string++, 1);
	return (len);
}

int	ft_print_number(int number)
{
	int	len;

	len = 0;
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		len += ft_print_character('-');
		number = -number;
	}
	if (number >= 10)
		len += ft_print_number(number / 10);
	len += ft_print_character((number % 10) + '0');
	return (len);
}

int	ft_print_unsigned(unsigned int number)
{
	int	len;

	len = 0;
	if (number >= 10)
		len += ft_print_unsigned(number / 10);
	len += ft_print_character((number % 10) + '0');
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:07 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/30 23:33:28 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_search_hexadecimal(unsigned int number, char caseType);
static int	ft_length_hexadecimal(unsigned int number);

int	ft_print_hexadecimal(int number, const char caseType)
{
	unsigned int	n;

	n = (unsigned int)number;
	if (n == 0)
		return (ft_print_character('0'));
	ft_search_hexadecimal(n, caseType);
	return (ft_length_hexadecimal(n));
}

static void	ft_search_hexadecimal(unsigned int number, char caseType)
{
	char	hex_char;

	if (number >= 16)
		ft_search_hexadecimal(number / 16, caseType);
	if (number % 16 < 10)
		hex_char = (number % 16) + '0';
	else
	{
		if (caseType == 'X')
			hex_char = (number % 16) - 10 + 'A';
		else
			hex_char = (number % 16) - 10 + 'a';
	}
	ft_print_character(hex_char);
}

static int	ft_length_hexadecimal(unsigned int number)
{
	int	length;

	length = 1;
	while (number >= 16)
	{
		number /= 16;
		length++;
	}
	return (length);
}

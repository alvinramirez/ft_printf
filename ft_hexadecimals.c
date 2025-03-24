/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:07 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/24 23:26:21 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_search_hexadecimal(unsigned int number, int caseType);
static int	ft_length_hexadecimal(unsigned int number);

int	ft_print_hexadecimal(unsigned int number, const char caseType)
{
	if (number == 0)
		return (ft_print_character('0'));
	ft_search_hexadecimal(number, caseType);
	return (ft_length_hexadecimal(number));
}

static void	ft_search_hexadecimal(unsigned int number, int caseType)
{
	char	hex_char;

	if (number >= 16)
		ft_search_hexadecimal(number / 16, caseType);
	if (number % 16 < 10)
		hex_char = (number % 16) + '0';
	else
	{
		if (caseType == 1)
			hex_char = (number % 16) - 10 + 'A';
		else
			hex_char = (number % 16) - 10 + 'a';
	}
	ft_print_character(hex_char);
}

static int	ft_length_hexadecimal(unsigned int number)
{
	int	length;

	length = 0;
	if (number == 0)
		length = 1;
	while (number != 0)
	{
		length++;
		number = number / 16;
	}
	return (length);
}

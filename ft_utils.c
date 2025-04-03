/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:32:03 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/03 13:46:07 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length_hexadecimal(unsigned long long number)
{
	int	length;

	length = 0;
	while (number > 0)
	{
		length++;
		number /= 16;
	}
	return (length);
}

void	ft_search_hexadecimal(unsigned long long number, char format)
{
	if (number >= 16)
	{
		ft_search_hexadecimal(number / 16, format);
		ft_search_hexadecimal(number % 16, format);
	}
	else
	{
		if (number < 10)
			ft_print_character(number + '0');
		else
		{
			if (format == 'x')
				ft_print_character(number - 10 + 'a');
			else if (format == 'X')
				ft_print_character(number - 10 + 'A');
		}
	}
}

int	ft_handle_output(int *count, int result)
{
	if (result < 0)
	{
		*count = -1;
		return (-1);
	}
	*count += result;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:32:03 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/01 23:27:03 by alvinram         ###   ########.fr       */
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
		ft_search_hex(number / 16, format);
		ft_search_hex(number % 16, format);
	}
	else
	{
		if (number < 10)
			ft_print_character(number + '0');
		else
		{
			if (format == 'x' || format == 'p')
				ft_print_character(number - 10 + 'a');
			else if (format == 'X')
				ft_print_character(number - 10 + 'A');
		}
	}
}

int	ft_safe_write(int fd, const void *buffer, size_t count)
{
	if (!buffer || count == 0)
		return (-1);
	return (write(fd, buffer, count));
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

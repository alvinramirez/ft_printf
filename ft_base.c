/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:49:00 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/25 17:39:55 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_character(char character)
{
	int	result;

	result = ft_safe_write(1, &character, 1);
	if (result < 0)
		return (-1);
	return (result);
}

int	ft_print_string(char *string)
{
	int	len;
	int	result;

	if (!string)
		string = "(null)";
	len = 0;
	while (*string)
	{
		result = ft_safe_write(1, string++, 1);
		if (result < 0)
			return (-1);
		len += result;
	}
	return (len);
}

int	ft_print_number(int number)
{
	int	len;
	int	result;

	len = 0;
	if (number == -2147483648)
		return (ft_safe_write(1, "-2147483648", 11));
	if (number < 0)
	{
		result = ft_print_character('-');
		if (result < 0)
			return (-1);
		len += result;
		number = -number;
	}
	if (number >= 10)
	{
		result = ft_print_number(number / 10);
		if (result < 0)
			return (-1);
		len += result;
	}
	result = ft_print_character((number % 10) + '0');
	if (result < 0)
		return (-1);
	return (len += result);
}

int	ft_print_unsigned(unsigned int number)
{
	int	len;
	int	result;

	len = 0;
	if (number >= 10)
	{
		result = ft_print_unsigned(number / 10);
		if (result < 0)
			return (-1);
		len = result;
	}
	result = ft_print_character((number % 10) + '0');
	if (result < 0)
		return (-1);
	len += result;
	return (len);
}

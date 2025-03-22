/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:11 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/22 19:01:52 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer_length(unsigned long long pointer);
static int	ft_search_pointer(unsigned long long pointer);

int	ft_print_pointer(unsigned long long pointer)
{
	int	count;
	int	result;

	count = 0;
	if (ft_handle_output(&count, ft_safe_write(1, "0x", 2)) < 0)
		return (-1);
	if (pointer == 0)
	{
		result = ft_safe_write(1, "0", 1);
		if (ft_handle_output(&count, result) < 0)
			return (-1);
		return (count);
	}
	if (ft_search_pointer(pointer) < 0)
		return (-1);
	return (count + ft_pointer_length(pointer));
}

static int	ft_pointer_length(unsigned long long pointer)
{
	int	length;

	length = 1;
	while (pointer >= 16)
	{
		pointer /= 16;
		length++;
	}
	return (length);
}

static int	ft_search_pointer(unsigned long long pointer)
{
	int	result;

	if (pointer >= 16)
	{
		result = ft_search_pointer(pointer / 16);
		if (result < 0)
			return (-1);
	}
	if (pointer % 16 < 10)
		result = ft_print_character((pointer % 16) + '0');
	else
		result = ft_print_character((pointer % 16) - 10 + 'a');
	if (result < 0)
		return (-1);
	return (0);
}

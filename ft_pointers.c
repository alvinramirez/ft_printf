/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:11 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/20 22:33:50 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer_length(unsigned long long pointer);
static void	ft_search_pointer(unsigned long long pointer);

int	ft_print_pointer(unsigned long long pointer)
{
	int	count;

	count = 0;
	if (ft_handle_output(&count, ft_safe_write(1, "0x", 2)) < 0)
		return (-1);
	if (pointer == 0)
		return (ft_handle_output(&count, ft_safe_write(1, "0", 1)) < 0 ?
			-1 : count);
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

static void	ft_search_pointer(unsigned long long pointer)
{
	if (pointer >= 16)
		if (ft_search_pointer(pointer / 16) < 0)
			return (-1);
	if (pointer % 16 < 10)
		return (ft_print_character((pointer % 16) + '0'));
	return (ft_print_character((pointer % 16) - 10 + 'a'));
}

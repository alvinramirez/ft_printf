/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:11 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/12 22:37:50 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer_length(unsigned long long pointer);
static void	ft_search_pointer(unsigned long long pointer);

int	ft_print_pointer(unsigned long long pointer)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (pointer == 0)
		return (count + write(1, "0", 1));
	ft_search_pointer(pointer);
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
		ft_search_pointer(pointer / 16);
	if (pointer % 16 < 10)
		ft_print_character((pointer % 16) + '0');
	else
		ft_print_character((pointer % 16) - 10 + 'a');
}
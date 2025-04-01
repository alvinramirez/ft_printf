/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:11 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/01 23:26:24 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long long pointer)
{
	int	size;

	size = ft_print_string("0x");
	if (pointer == 0)
		size += ft_print_character('0');
	else
	{
		ft_search_hexadecimal(pointer, 'p');
		size += ft_length_hexadecimal(pointer);
	}
	return (size);
}

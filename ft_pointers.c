/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:11 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/03 13:31:56 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_search_pointer(unsigned long long number)
{
	if (number >= 16)
	{
		ft_search_pointer(number / 16);
		ft_search_pointer(number % 16);
	}
	else
	{
		if (number < 10)
			ft_print_character(number + '0');
		else
			ft_print_character(number - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long pointer)
{
	if (pointer == 0)
		return (ft_print_string("(nil)"));
	ft_print_string("0x");
	ft_search_pointer(pointer);
	return (ft_length_hexadecimal(pointer) + 2);
}

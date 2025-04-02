/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:07 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/02 22:08:47 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(int number, const char caseType)
{
	unsigned int	safe_number;

	safe_number = (unsigned int)number;
	if (safe_number == 0)
		return (ft_print_character('0'));
	ft_search_hexadecimal(safe_number, caseType);
	return (ft_length_hexadecimal(safe_number));
}

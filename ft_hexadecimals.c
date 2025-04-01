/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:44:07 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/01 23:26:56 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(int number, const char caseType)
{
	if (number == 0)
		return (ft_print_character('0'));
	ft_search_hexadecimal(number, caseType);
	return (ft_length_hexadecimal(number));
}

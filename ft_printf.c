/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:48:52 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/16 23:41:45 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list args, char specifier)
{
	int	size;

	size = 0;
	if (specifier == 'c')
		size += ft_print_character(va_arg(args, int));
	else if (specifier == 's')
		size += ft_print_string(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		size += ft_print_number(va_arg(args, int));
	else if (specifier == 'u')
		size += ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'p')
		size += ft_print_pointer(va_arg(args, unsigned long long));
	else if (specifier == 'x' || specifier == 'X')
		size += ft_print_hexadecimal(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		size += write(1, "%", 1);
	else
		size += ft_print_character(specifier);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_select_format(args, *format);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

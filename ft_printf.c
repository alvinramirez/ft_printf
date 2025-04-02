/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:48:52 by alvinram          #+#    #+#             */
/*   Updated: 2025/04/02 22:25:42 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list args, char specifier);

int	ft_printf(char const *format, ...)
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
			if (ft_handle_output(&count, ft_select_format(args, *format)) < 0)
				return (va_end(args), -1);
		}
		else if (ft_handle_output(&count, write(1, format, 1)) < 0)
			return (va_end(args), -1);
		format++;
	}
	va_end(args);
	return (count);
}

static int	ft_select_format(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_print_character(va_arg(args, int)));
	if (specifier == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (specifier == 'p')
		return (ft_print_pointer((unsigned long long)va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_number(va_arg(args, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (specifier == 'x')
		return (ft_print_hexadecimal(va_arg(args, unsigned int), 'x'));
	if (specifier == 'X')
		return (ft_print_hexadecimal(va_arg(args, unsigned int), 'X'));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (-1);
}

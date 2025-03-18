/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:48:52 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/18 23:10:08 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_output(int *count, int result)
{
	if (result < 0)
		return (-1);
	*count += result;
	return (0);
}

static int	ft_select_format(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_print_character(va_arg(args, int)));
	if (specifier == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (specifier == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_number(va_arg(args, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (specifier == '%')
		return (ft_safe_write(1, "%", 1));
	return (-1);
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
			if (ft_handle_output(&count, ft_select_format(args, *format)) < 0)
				return (va_end(args), -1);
		}
		else if (ft_handle_output(&count, ft_safe_write(1, format, 1)) < 0)
			return (va_end(args), -1);
		format++;
	}
	va_end(args);
	return (count);
}

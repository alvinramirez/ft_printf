/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:48:46 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/17 22:05:26 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_print_character(char character);
int	ft_print_string(char *string);
int	ft_print_number(int number);
int	ft_print_unsigned(unsigned int number);
int	ft_print_pointer(unsigned long long pointer);
int	ft_print_hexadecimal(unsigned int number, const char caseType);

int ft_safe_write(int fd, const void *buffer, size_t count);

#endif
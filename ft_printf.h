/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:48:46 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/28 23:47:26 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
int	ft_printf(const char *format, ...);

int	ft_print_character(char character);
int	ft_print_string(char *string);
int	ft_print_number(int number);
int	ft_print_unsigned(unsigned int number);
int	ft_print_pointer(unsigned long long pointer);
int	ft_print_hexadecimal(int number, const char caseType);

int	ft_safe_write(int fd, const void *buffer, size_t count);
int	ft_handle_output(int *count, int result);

#endif
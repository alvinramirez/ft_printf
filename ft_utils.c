/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:32:03 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/21 16:34:03 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_safe_write(int fd, const void *buffer, size_t count)
{
	int	bytes_written;

	bytes_written = write(fd, buffer, count);
	if (bytes_written < 0)
		return (-1);
	return (bytes_written);
}

int	ft_handle_output(int *count, int result)
{
	if (result < 0)
		return (-1);
	*count += result;
	return (0);
}

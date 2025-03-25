/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvinram <alvinram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:32:03 by alvinram          #+#    #+#             */
/*   Updated: 2025/03/25 17:40:01 by alvinram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_safe_write(int fd, const void *buffer, size_t count)
{
	if (!buffer || count == 0)
		return (-1);
	return (write(fd, buffer, count));
}

int	ft_handle_output(int *count, int result)
{
	if (result < 0)
	{
		*count = -1;
		return (-1);
	}
	*count += result;
	return (0);
}

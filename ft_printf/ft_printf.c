/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:08:37 by vlushnik          #+#    #+#             */
/*   Updated: 2024/05/11 18:24:14 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	count;
	ssize_t	result;

	if (!format)
		return (0);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += check_format(*(++format), args);
		else
		{
			result = write(1, format, 1);
			if (result < 0)
				return (-1);
			count += result;
		}
		format++;
	}
	va_end(args);
	return (count);
}

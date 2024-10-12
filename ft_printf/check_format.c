/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:06:04 by vlushnik          #+#    #+#             */
/*   Updated: 2023/12/08 20:31:29 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char specifier, va_list args)
{
	int	count;
	int	result;

	count = 0;
	result = 0;
	if (specifier == 'c')
		result = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		result = ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		result = ft_putptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		result = ft_putnbr((long)(va_arg(args, int)), 10);
	else if (specifier == 'u')
		result = ft_put_u((unsigned int)(va_arg(args, int)), 10);
	else if (specifier == 'x')
		result = ft_puthex((va_arg(args, unsigned int)), 16, 'x');
	else if (specifier == 'X')
		result = ft_puthex((va_arg(args, unsigned int)), 16, 'X');
	else if (specifier == '%')
		result = ft_putchar('%');
	if (result < 0)
		return (-1);
	count += result;
	return (count);
}

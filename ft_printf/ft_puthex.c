/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:14:52 by vlushnik          #+#    #+#             */
/*   Updated: 2023/12/11 20:18:45 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int base, char specifier)
{
	int		count;
	char	*hex;
	int		result;

	count = 0;
	if (specifier == 'x')
		hex = "0123456789abcdef";
	else if (specifier == 'X')
		hex = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	if (n / base > 0)
	{
		result = ft_puthex(n / base, base, specifier);
		if (result < 0)
			return (-1);
		count += result;
	}
	result = ft_putchar(hex[n % base]);
	if (result < 0)
		return (-1);
	count += result;
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:53:14 by vlushnik          #+#    #+#             */
/*   Updated: 2023/12/11 20:21:25 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_extra(unsigned long n, int base)
{
	long		count;
	const char	*hex;
	long		result;

	hex = "0123456789abcdef";
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n / base > 0)
	{
		result = ft_puthex_extra(n / base, base);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:19:49 by vlushnik          #+#    #+#             */
/*   Updated: 2024/02/17 17:08:48 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_protected(char c)
{
	int	result;

	result = ft_putchar(c);
	if (result < 0)
		return (-1);
	return (result);
}

static int	print_negative_num(long n, int base)
{
	int	result;
	int	count;

	result = ft_putchar_protected('-');
	if (result < 0)
		return (-1);
	count = ft_putnbr(-n, base);
	if (count < 0)
		return (-1);
	return (count + 1);
}

int	ft_putnbr(long n, int base)
{
	int	count;
	int	result;

	if (n == 0)
		return (ft_putchar_protected('0'));
	if (n < 0)
		return (print_negative_num(n, base));
	if (n < base)
		return (ft_putchar_protected(n + '0'));
	else
	{
		count = ft_putnbr(n / base, base);
		if (count < 0)
			return (-1);
		else
		{
			result = ft_putnbr(n % base, base);
			if (result < 0)
				return (-1);
			return (count + result);
		}
	}
}

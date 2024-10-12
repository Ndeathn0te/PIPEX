/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:12:14 by vlushnik          #+#    #+#             */
/*   Updated: 2023/12/11 21:37:24 by vlushnik         ###   ########.fr       */
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

int	ft_put_u(unsigned int n, int base)
{
	int		count;
	int		result;
	char	c;

	if (n == 0)
	{
		return (ft_putchar_protected(c = '0'));
	}
	if (n < (unsigned int)base)
	{
		return (ft_putchar_protected(c = n + '0'));
	}
	else
	{
		count = ft_put_u(n / base, base);
		if (count < 0)
			return (-1);
		else
		{
			result = ft_put_u(n % base, base);
			if (result < 0)
				return (-1);
			return (count + result);
		}
	}
}

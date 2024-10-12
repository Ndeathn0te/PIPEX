/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:26:52 by vlushnik          #+#    #+#             */
/*   Updated: 2023/12/08 20:38:14 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;
	int	result;

	count = ft_putstr("0x");
	if (count < 0)
		return (-1);
	result = ft_puthex_extra((unsigned long)ptr, 16);
	if (result < 0)
		return (-1);
	return (count + result);
}

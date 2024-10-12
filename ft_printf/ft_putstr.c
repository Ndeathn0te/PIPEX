/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:16:44 by vlushnik          #+#    #+#             */
/*   Updated: 2023/12/08 20:36:58 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	result;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		result = ft_putchar((int)*str);
		if (result < 0)
		{
			return (-1);
		}
		str++;
		count++;
	}
	return (count);
}

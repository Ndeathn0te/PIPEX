/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:13:47 by vlushnik          #+#    #+#             */
/*   Updated: 2024/05/11 18:21:04 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	ssize_t	result;

	result = write(1, &c, 1);
	if (result < 0)
		return (-1);
	else
		return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlushnik <vlushnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:19:27 by vlushnik          #+#    #+#             */
/*   Updated: 2023/12/11 21:39:02 by vlushnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define LONG_MIN -9223372036854775807

int	ft_printf(char const *format, ...);
int	check_format(char specifier, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long n, int base);
int	ft_put_u(unsigned int n, int base);
int	ft_puthex(unsigned int n, int base, char specifier);
int	ft_putptr(void *ptr);
int	ft_puthex_extra(unsigned long n, int base);

#endif

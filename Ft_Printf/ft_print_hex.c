/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:21:06 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/25 14:34:05 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_hex(unsigned long long n, int err)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n < 16 && err == 1)
		len += ft_putchar_fd('0', 1);
	if (n >= 16)
	{
		len += ft_print_hex(n / 16, 0);
		len += ft_print_hex(n % 16, 0);
	}
	else
		len += ft_putchar_fd(base[n], 1);
	return (len);
}

size_t	ft_print_hex_upper(unsigned long long n, int err)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789ABCDEF";
	if (n < 16 && err == 1)
		len += ft_putchar_fd('0', 1);
	if (n >= 16)
	{
		len += ft_print_hex_upper(n / 16, 0);
		len += ft_print_hex_upper(n % 16, 0);
	}
	else
		len += ft_putchar_fd(base[n], 1);
	return (len);
}

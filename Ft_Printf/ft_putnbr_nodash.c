/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_nodash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:43:14 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/25 14:46:17 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_nodash(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putchar_fd('2', 1);
		n = 147483648;
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
	{
		len += ft_putnbr_nodash(n / 10);
		len += ft_putnbr_nodash(n % 10);
	}
	else
	{
		len += ft_putchar_fd(n + 48, 1);
	}
	return (len);
}

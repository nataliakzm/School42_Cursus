/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:21:15 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/26 14:40:19 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** This script outputs integer to given file
** DETAILS: Outputs the integer ’n’ to the given file descriptor.
*/

#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putchar_fd('-', fd);
		len += ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
	{
		len += ft_putnbr_fd(n / 10, fd);
		len += ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		len += ft_putchar_fd(n + 48, fd);
	}
	return (len);
}

size_t	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putunbr_fd(n / 10, fd);
		len += ft_putunbr_fd(n % 10, fd);
	}
	else
		len += ft_putchar_fd(n + 48, fd);
	return (len);
}

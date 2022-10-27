/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:05:07 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/27 15:38:59 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** This script converts integer to ASCII string
** DETAILS: Allocates (with malloc(3)) and returns a string 
** representing the integer received as an argument.
** Negative numbers must be handled.
*/

#include "libft.h"

static int	ft_num_size(int numb)
{
	int	length;

	length = 1;
	if (numb < 0)
		length++;
	while (numb > 9 || numb < -9)
	{
		length++;
		numb /= 10;
	}
	return (length + 1);
}

static char	*ft_reverse(char *str)
{
	char	swap;
	int		i;
	int		j;

	i = 0;
	j = (int)ft_strlen(str) - 1;
	while (i < ((int)(ft_strlen(str)) / 2))
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;
	int		neg;

	i = 0;
	neg = 0;
	str = malloc(sizeof(char) * ft_num_size(n));
	if (n < 0)
		neg = 1;
	if (str == 0)
		return (0);
	if (n == 0)
		str[i++] = '0';
	while (n)
	{
		j = n % 10;
		if (j < 0)
			j *= -1;
		str[i++] = j + 48;
		n /= 10;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_reverse(str));
}

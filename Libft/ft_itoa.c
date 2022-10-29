/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:05:07 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/29 12:05:45 by nkuzminy         ###   ########.fr       */
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
	return (length);
}

char	*ft_itoa(int n)
{
	long int	u;
	int			i;
	char		*str;

	u = (long int)n;
	i = ft_num_size(u);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i--] = '\0';
	if (u == 0)
		str[0] = '0';
	if (u < 0)
	{
		str[0] = '-';
		u = u * -1;
	}
	while (u)
	{
		str[i--] = (u % 10) + 48;
		u = u / 10;
	}
	return (str);
}

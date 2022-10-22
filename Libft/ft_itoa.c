/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:05:07 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/22 17:12:26 by nkuzminy         ###   ########.fr       */
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

static unsigned int	ft_num_size(int numb)
{
	int	length;

	length = 0;
	if (numb == 0)
		return (1);
	if (numb < 0)
		length += 1;
	while (numb)
	{
		numb /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	unsigned int	numb;
	unsigned int	length;
	char			*str;

	numb = 0;
	str = (char *)malloc(sizeof(char) * (ft_num_size(n) + 1));
	if (str == 0)
		return (0);
	if (numb < 0)
	{
		str[0] = '-';
		numb = -n;
	}
	else
		numb = n;
	if (numb == 0)
		str[0] = '0';
	str[ft_num_size(n)] = '\0';
	while (numb)
	{
		str[ft_num_size(n) - 1] = (numb % 10) + '0';
		numb = numb / 10;
		ft_num_size(n)--;
	}
	return (str);
}

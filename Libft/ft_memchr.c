/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:06:39 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/15 16:26:32 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <strings.h>
** This script locates byte in byte string
** DETAILS: memchr() locates the first occurrence of c
**			(converted to an unsigned char) in string s.
*/

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	char *str;
	char f_c;

	i = 0;
	str = (char *)s;
	f_c = (char)c;
	while (i < n)
	{
		if (str[i] == f_c)
			return (&str[i]);
		i++;
	}
	return (0);
}

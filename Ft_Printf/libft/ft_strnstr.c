/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:23:16 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/19 15:32:05 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** This script locates a substring in a string (size-bounded)
** DETAILS: strnstr() locates the first occurrence of the null-termi-
**	nated string s2 in the string s1, where not more than n characters are
**	searched.  Characters that appear after a `\0' character are not
**	searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		j = 0;
		while (needle[j] && haystack[i + j]
			&& needle[j] == haystack[i + j]
			&& i + j < n)
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		if (!haystack[i + j] || i + j == n)
			return ((char *)(void *)0);
		i++;
	}
	return ((char *)(void *)0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:06:59 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/27 13:24:38 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <strings.h>
** This script copies memory area
** DETAILS: memcpy() copies n bytes from memory area s2 to memory area s1.
**  If s1 and s2 overlap, behavior is undefined.  Applications in which
**	s1 and s2 might overlap should use memmove(3) instead.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		((char *)dest)[i] = s1[i];
		i++;
	}
	return (dest);
}

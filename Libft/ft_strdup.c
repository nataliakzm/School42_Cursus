/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:22:01 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/19 16:11:26 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** This script saves a copy of a string (with malloc)
** DETAILS: strdup() allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it.  The pointer may
**	subsequently be used as an argument to the function free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

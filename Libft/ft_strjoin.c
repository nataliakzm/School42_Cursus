/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:22:18 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/22 13:10:10 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** This script concatenates two strings into a new string (with malloc)
** DETAILS: Allocates (with malloc(3)) and returns a new string,
** which is the result of the concatenation of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (res == 0)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);
}

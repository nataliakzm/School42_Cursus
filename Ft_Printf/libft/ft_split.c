/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:21:33 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/29 14:24:59 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * LIBRARY: N/A
 * This script splits string, with specified character as delimiter,
 * into an array of strings
 * DETAILS: Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting ’s’ using the character ’c’ as a delimiter. 
 * The array must be ended by a NULL pointer.
*/

#include "libft.h"

static int	ft_wcount(char const *str, char c)
{
	int	i;
	int	count;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (str[0] != c)
		count++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_malloc(char const *str, char c)
{
	int		len;
	char	**ptr_words;

	len = ft_wcount(str, c);
	ptr_words = malloc(sizeof(*ptr_words) * (len + 1));
	if (ptr_words == 0)
		return (0);
	return (ptr_words);
}

static int	ft_nxtword(char const *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**free_words(char **ptr_words, int i)
{
	int	j;

	j = 0;
	while (j < i && ptr_words[j] != 0)
	{
		free(ptr_words[j]);
		j++;
	}
	free(ptr_words);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	int		i;
	int		j;
	char	**ptr_words;

	k = 0;
	i = -1;
	ptr_words = ft_malloc(s, c);
	if (!ptr_words)
		return (0);
	while (++i < ft_wcount(s, c))
	{
		j = 0;
		ptr_words[i] = malloc (ft_nxtword(s, c, k) + 1);
		if (!ptr_words[i])
			return (free_words(ptr_words, i));
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
			ptr_words[i][j++] = s[k++];
		ptr_words[i][j] = '\0';
	}
	ptr_words[i] = 0;
	return (ptr_words);
}

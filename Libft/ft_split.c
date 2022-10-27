/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:21:33 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/25 14:32:09 by nkuzminy         ###   ########.fr       */
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

int	ft_wcount(const char *str, char c)
{
	int	i;
	int	sum_words;

	i = 0;
	sum_words = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			sum_words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (sum_words);
}

char	*ft_word(const char *str, char c)
{
	char	*wd;
	int		i;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	wd = malloc(sizeof(char) * (i + 1));
	if (wd == 0)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		wd[i] = str[i];
		i++;
	}
	wd[i] = '\0';
	return (wd);
}

void	free_words(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_words;
	int		words;
	int		i;

	ptr_words = 0;
	if (!s)
		return (0);
	words = ft_wcount(s, c);
	ptr_words = malloc(sizeof(char *) * (words + 1));
	if (ptr_words)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		ptr_words[i] = ft_word(s, c);
		if (ptr_words[i] == 0)
			free_words(i, ptr_words);
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr_words[i] = 0;
	return (ptr_words);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:21:24 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/26 14:34:58 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** This script outputs string to given file
** DETAILS: Outputs the string ’s’ to the given file descriptor.
*/

#include "libft.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		i++;
	}
	return (i);
}

size_t	ft_putnstr_fd(char *s, int n, int fd)
{
	int	i;

	i = 0;
	while (*s && n)
	{
		ft_putchar_fd(*s, fd);
		s++;
		i++;
		n--;
	}
	return (i);
}

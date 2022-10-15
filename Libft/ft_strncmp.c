/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:23:08 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/11 17:23:09 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** This script compares strings (size-bounded)
** DETAILS: strcmp() and strncmp() functions lexicographically compare
**	the null-terminated strings s1 and s2.
** The strncmp() function compares not more than n characters.  Because
**	strncmp() is designed for comparing strings rather than binary data,
**	characters that appear after a `\0' character are not compared.
*/

#include "libft.h"

int ft_strncmp(const char *s1, char *s2, size_t n) {}
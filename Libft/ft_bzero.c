/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:02:42 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/13 16:15:10 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This script writes zeroes to a byte string
** LIBRARY: <strings.h> 
** DETAILS: bzero() writes n zeroed bytes to the string s.
**          If n is zero, bzero() does nothing.
*/

#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, '\0', n);
}
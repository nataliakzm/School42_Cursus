/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:03:54 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/13 15:29:10 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This script is for testing ASCII characters */
/* DETAILS: isascii() tests for an ASCII character (in the range 0 to 127) */
/* LIBRARY: <ctype.h> */

#include "libft.h"

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}

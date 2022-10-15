/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:24:18 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/13 15:28:09 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This script is for lower case to upper case letter conversion */
/* LIBRARY: <ctype.h> */

#include "libft.h"

int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
		return (i -= 32);
	return (0);
}

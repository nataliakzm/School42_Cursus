/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:24:18 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/17 12:07:43 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** This script is for lower case to upper case letter conversion
*/

#include "libft.h"

int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
		return (i -= 32);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:23:48 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/13 15:27:55 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <ctype.h>
** This script is for upper case to lower case letter conversion
*/

#include "libft.h"

int ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (i += 32);
	return (i);
}

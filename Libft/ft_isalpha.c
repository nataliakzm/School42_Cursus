/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:03:45 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/13 15:30:16 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This script is for testing alphabetic characters */
/* LIBRARY: <ctype.h> */

#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1);
	return (0);
}

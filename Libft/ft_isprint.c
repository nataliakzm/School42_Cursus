/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:05:01 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/13 15:31:20 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This script is for printing character test (incl. space) */
/* LIBRARY: <ctype.h */

#include "libft.h"

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}

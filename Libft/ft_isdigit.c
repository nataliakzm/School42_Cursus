/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:04:53 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/13 15:30:50 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This script is for testing decimal-digit characters */
/* LIBRARY: <ctype.h */

#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

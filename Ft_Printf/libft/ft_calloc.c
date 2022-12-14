/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:02:55 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/22 14:15:21 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdlib.h>
** This script is for memory allocation
** DETAILS: calloc() contiguously allocates enough space for count
**	objects that are size bytes of memory each and returns a pointer to the
**	allocated memory. The allocated memory is filled with bytes of value
**	zero.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	size *= count;
	new = malloc(size);
	if (new)
		ft_bzero(new, size);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:06:30 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/29 15:02:25 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** This script counts elements of a list
** DETAILS: Counts the number of elements in a list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}

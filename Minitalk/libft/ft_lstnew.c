/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:06:20 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/19 15:51:09 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** This script creates new list
** DETAILS: Allocates (with malloc(3)) and returns a new element. 
** The variable ’content’ is initialized with the value
** of the parameter ’content’. The variable ’next’ is initialized to NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	if (!new)
		return (new);
	new -> content = content;
	new -> next = (t_list *)(void *)0;
	return (new);
}

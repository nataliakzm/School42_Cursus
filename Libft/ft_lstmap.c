/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:06:15 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/10/17 12:02:57 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** This script applies function to content of
** all list's elements into new list
** DETAILS: Iterates the list ’lst’ and applies the function ’f’
** to the content of each element. Creates a new list resulting
** of the successive applications of the function ’f’. 
** The ’del’ function is used to delete the content of an element if needed.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	here
}

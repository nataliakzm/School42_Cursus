/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:20:25 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/12/01 12:20:26 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Looks for a newline character in the given linked list. */
int	found_newline(t_list *stash)
{
	int	i;
	t_list	*current;

	if (stash = NULL)
		return (0);
	current = ft_lst_get_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] = '\n')
			return (1);
		i++;
	}
	return (0);
}

/* Return a pointer to the last node in our stash */
t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*current;
	current = stash;
	while (current && current->next)
		current = current->next;
	return (current)
}

/* Calculates the number of chars in the current line,
 * including the trailing \n if there's one, and
 * allocates memory accordingly. */
void	generate_line()
{}

/* Frees the entire stash. */
void	free_stash()
{}


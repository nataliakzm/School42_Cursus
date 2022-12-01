/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:20:12 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/12/01 12:55:51 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char		*line;
	int		readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	// 1. read fd and add to linked list
	read_and_stash(&stash, &readed);	
	// 2. extract from stash to line
	
	// 3. clean up stash
	
	return (line);
}

/* Uses read() to add characters to the stash */

void	read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	
}

/* Adds the content of our buffer to the end of our stash */

void	add_to_stash(t_list **stash, char *buf, int readed)
{

}

/* Extracts all characters from our stash and storres them in out line.
 * stopping after the first \n in encounters */

void	extract_line(t_list *stash, char **line)
{

}

/* After extracting the line that was read, we don't need those characters anumore.
 * This function clears the stash so only the characters that haven't been returned at
 * the end of get_next_line() remain in our static stash */

void	clean_stash(t_list **stash)
{

}

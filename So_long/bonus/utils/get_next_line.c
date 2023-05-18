/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:00:12 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 16:00:13 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*read_line(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*lines;
	int		files;

	files = read(fd, buff, 1);
	if (files == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		lines = malloc(sizeof(char) * depth + 1);
		if (!lines)
			return (0);
		lines[depth] = 0;
		*ret = 1;
		if (buff[0] == 0)
			*ret = 0;
		return (lines);
	}
	else
	{
		lines = read_line(depth + 1, ret, fd);
		lines[depth] = buff[0];
	}
	return (lines);
}

int	get_next_line(int fd, char **lines)
{
	int	ret;

	ret = 1;
	*lines = read_line(0, &ret, fd);
	return (ret);
}

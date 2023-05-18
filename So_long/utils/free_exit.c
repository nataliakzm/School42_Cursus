/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:47:04 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/11 15:47:06 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_exit(t_long *game)
{
	if (game->mlx_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free_map(game);
	write(1, "\n\033[31mThe Game was closed successfully\n", 39);
	exit(0);
}

int	free_map(t_long *game)
{
	int	i;

	i = 0;
	if (game->maptofree == -1)
		return (1);
	while (i < game->y)
	{
		free(game->map[i]);
		i++;
	}
	if (game->map)
		free(game->map);
	return (1);
}

int	show_error(t_long *game, char *str)
{
	write(1, "\033[31mError\n\033[0;37m", 12);
	ft_putstr(str);
	write(1, "\n", 1);
	free_exit(game);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

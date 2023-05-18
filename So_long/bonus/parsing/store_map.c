/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:06:18 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/11 16:06:19 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/****************************************************************************
	-'store_map' reads a map file and stores its contents in a data structure
	-'store_line' processes each line of the map, updating the game accordingly
	-'check_map' verifies the validity of the map by checking conditions 
		such as the presence of a player, an exit, and collectibles. 
	-'malloc_map' allocates memory for the map
	-'checkifgood' check if a character is valid for the map
*****************************************************************************/

int	store_map(t_long *game, char *filename)
{
	char	*line;
	int		fd;
	int		ret;
	int		nb;

	nb = 0;
	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	while (line[num_blank(line)] == '1' || line[num_blank(line)] == '0')
	{
		store_line(game, line, nb);
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		nb++;
	}
	free(line);
	return (0);
}

int	store_line(t_long *game, char *line, int nb)
{
	int	index;

	index = 0;
	while (line[index])
	{
		game->case_total++;
		game->map[nb][index] = replace_char(line[index]);
		if (line[index] == PLAYER_CHAR)
		{
			game->player_set++;
			game->player_x = index;
			game->player_y = nb;
		}
		if (line[index] == EXIT_CHAR)
			game->exit_set++;
		if (line[index] == COLLECTIBLE_CHAR)
			game->collectible_total++;
		if (line[index] != PLAYER_CHAR
			&& line[index] != EXIT_CHAR && line[index]
			!= COLLECTIBLE_CHAR && line[index] != WALL_CHAR
			&& line[index] != FLOOR_CHAR && line[index] != BOMB_CHAR)
			show_error(game, "Invalid map: unknown char");
		index++;
	}
	return (0);
}

int	check_map(t_long *game)
{
	if (game->player_set < 1)
		show_error(game, "Invalid map: You must set a player 'P'");
	if (game->player_set > 1)
		show_error(game, "Multiplayer mode unavailable");
	if (game->exit_set < 1)
		show_error(game, "Invalid map: You must set an exit 'E'");
	if (game->exit_set > 1)
		show_error(game, "Only 1 exit is permitted");
	if (game->collectible_total == 0)
		show_error(game, "Invalid map: You must set a collectible 'C'");
	check_wall(game);
	return (0);
}

int	malloc_map(t_long *game)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * game->y);
	while (i < game->y)
	{
		game->map[i] = malloc(sizeof(char) * (game->x + 1));
		i++;
	}
	game->maptofree = 1;
	return (1);
}

int	checkifgood(char c)
{
	if (c != '0' && c != 'a' && c != '1' && c != 'P' && c != 'c' && c != 'E'
		&& c != 'd' && c != 'C' && c != 'e' && c != 'B' && c != 'f')
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:06:03 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/11 16:06:05 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/****************************************************************************
	-'check_extension' checks if the file has .ber extension and opens it.
		If not, it shows an error.
	-'flood_fill' performs a flood-fill algorithm on the game map, 
		recursively checking and updating cells based on certain conditions.
		It calls the 'checkaround' to validate the walls of each cell.
	-'flood_fill2' pdates specific cells on the map based on their values. 
		The 'checkaround' verifies if a cell is surrounded by walls.
	-'check_wall' performs flood-fill operations, and checks if 
		all collectibles are within the map boundaries and if the exit is 
		present on the map.
*****************************************************************************/

int	check_extension(char *filename, t_long *game)
{
	int	i;

	i = 0;
	while (filename[i] != '\0')
		i++;
	if (filename[i - 1] == FILE_EXTENSION[3]
		&& filename[i - 2] == FILE_EXTENSION[2]
		&& filename[i - 3] == FILE_EXTENSION[1]
		&& filename[i - 4] == FILE_EXTENSION[0])
	{
		i = open(filename, O_RDONLY);
		if (i == -1)
			show_error(game, "File Name isn't correct");
		else
			close(i);
		return (0);
	}
	show_error(game, "Files without .ber extension isn't accepted");
	return (0);
}

int	flood_fill(t_long *game, int mapy, int mapx)
{
	char	current_cell;

	current_cell = game->map[mapy][mapx];
	if (current_cell == 'a'
		|| current_cell == 'c'
		|| current_cell == 'd'
		|| current_cell == 'e')
	{
		if (checkaround(mapx, mapy, game) == 0)
			show_error(game, "Invalid map: not surrounded/closed by wall");
		flood_fill2(game, mapy, mapx);
		flood_fill(game, mapy, mapx + 1);
		flood_fill(game, mapy, mapx - 1);
		flood_fill(game, mapy + 1, mapx);
		flood_fill(game, mapy - 1, mapx);
	}
	return (1);
}

void	flood_fill2(t_long *game, int mapy, int mapx)
{
	char	current_cell;

	current_cell = game->map[mapy][mapx];
	if (current_cell == 'a')
		game->map[mapy][mapx] = '0';
	if (current_cell == 'c')
		game->map[mapy][mapx] = 'P';
	if (current_cell == 'd')
	{
		game->map[mapy][mapx] = 'E';
		game->exit_parse++;
	}
	if (current_cell == 'e')
	{
		game->map[mapy][mapx] = 'C';
		game->collectible_parse++;
	}
}

int	checkaround(int mapx, int mapy, t_long *game)
{
	int	map_width;
	int	map_height;

	map_width = game->x;
	map_height = game->y;
	if (mapy == 0 || mapy == map_height - 1
		|| mapx == 0 || mapx == map_width - 1)
		show_error(game, "Invalid map: not surrounded/closed by walls");
	if (checkifgood(game->map[mapy + 1][mapx]) == 0)
		return (0);
	if (checkifgood(game->map[mapy - 1][mapx]) == 0)
		return (0);
	if (checkifgood(game->map[mapy][mapx + 1]) == 0)
		return (0);
	if (checkifgood(game->map[mapy][mapx - 1]) == 0)
		return (0);
	return (1);
}

int	check_wall(t_long *game)
{
	int	mapx;
	int	mapy;

	mapy = (int)game->player_x;
	mapx = (int)game->player_y;
	game->collectible_parse = 0;
	game->exit_parse = 0;
	flood_fill(game, mapx, mapy + 1);
	flood_fill(game, mapx, mapy - 1);
	flood_fill(game, mapx + 1, mapy);
	flood_fill(game, mapx, mapy - 1);
	if (game->collectible_parse != game->collectible_total)
		show_error(game, "Some collectible are out of the map");
	if (game->exit_parse == 0)
		show_error(game, "Exit is out of the map");
	return (0);
}

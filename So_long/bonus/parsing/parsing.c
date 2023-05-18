/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:06:11 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/11 16:06:12 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	parsing(t_long *game, char *argv)
{
	check_extension(argv, game);
	get_map_dimension(game, argv);
	malloc_map(game);
	store_map(game, argv);
	check_map(game);
	return (0);
}

int	get_map_dimension(t_long *game, char *filename)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	game->oldx = ft_strlen(line);
	while (line[num_blank(line)] == WALL_CHAR || line[num_blank(line)] == '0')
	{
		game->x = ft_strlen(line);
		if (game->x != game->oldx)
			show_error(game, "Invalid map: not a rectangle");
		game->oldx = game->x;
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		game->y++;
	}
	if (game->y == 0 || game->x == 0)
		show_error(game, "Invalid map: not correct or not well formated");
	game->yscreen = game->y * 64;
	free(line);
	game->xscreen = game->x * 64;
	close(fd);
	return (0);
}

char	replace_char(char c)
{
	if (c == FLOOR_CHAR)
		return ('a');
	if (c == WALL_CHAR)
		return ('1');
	if (c == PLAYER_CHAR)
		return ('c');
	if (c == EXIT_CHAR)
		return ('d');
	if (c == COLLECTIBLE_CHAR)
		return ('e');
	if (c == BOMB_CHAR)
		return ('f');
	return (0);
}

int	init_var(t_long *game)
{
	game->keyboard[BACK] = 0;
	game->keyboard[RED_BUTTON] = 0;
	game->keyboard[ESC] = 0;
	game->keyboard[LEFT] = 0;
	game->keyboard[RIGHT] = 0;
	game->keyboard[ADVANCE] = 0;
	game->bpp = 0;
	game->case_in = 0;
	game->case_total = 0;
	game->y = 0;
	game->x = 0;
	game->collectible = 0;
	game->collectible_total = 0;
	game->s_line = 0;
	game->maptofree = -1;
	game->move = 0;
	game->player_set = 0;
	game->collectible_set = 0;
	game->exit_set = 0;
	game->lstplayer_x = -1;
	game->lstplayer_y = -1;
	game->mlx_ptr = NULL;
	return (0);
}

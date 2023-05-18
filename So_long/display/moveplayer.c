/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:00:49 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 12:00:53 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/****************************************************************************
	-'move_player' checks if the player can move in a specified direction 
		on the game map and calls the 'display_move' if the conditions are met.
	-'display_move' updates the player's position, increments the move count, 
		and calls the 'check_remove' to check if any collectibles 
		are collected or if the game is finished. 
	-'check_remove' handles collectible collection and determines 
		if the player has finished the game. 
	-'pos_player' updates the player's position and resets the keyboard input
	-'reset_keyboard' resets the keyboard state for various keys.
*****************************************************************************/

int	move_player(int direction, t_long *game)
{
	if (direction == MOVE_UP)
		if (game->map[game->player_y - 1][game->player_x] != '1')
			display_move(game, direction);
	if (direction == MOVE_DOWN)
		if (game->map[game->player_y + 1][game->player_x] != '1')
			display_move(game, direction);
	if (direction == MOVE_LEFT)
		if (game->map[game->player_y][game->player_x - 1] != '1')
			display_move(game, direction);
	if (direction == MOVE_RIGHT)
		if (game->map[game->player_y][game->player_x + 1] != '1')
			display_move(game, direction);
	return (0);
}

int	display_move(t_long *game, int direction)
{
	write(1, "\b\b\b\b\b\b\b\b\b\b\b", 12);
	if (direction == MOVE_UP)
		game->player_y--;
	if (direction == MOVE_DOWN)
		game->player_y++;
	if (direction == MOVE_LEFT)
		game->player_x--;
	if (direction == MOVE_RIGHT)
		game->player_x++;
	game->move++;
	write(1, "MOVE : ", 8);
	ft_putnbr(game->move);
	check_remove(game);
	return (0);
}

int	check_remove(t_long *game)
{
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->collectible++;
		game->map[game->player_y][game->player_x] = '0';
	}
	if (game->map[game->player_y][game->player_x] == 'E')
	{
		if (game->collectible == game->collectible_total)
		{
			write(1, "\b\b\b\b\b\b\b\b\b\b", 11);
			write(1, "Congratulation you finish with ", 31);
			ft_putnbr(game->move);
			write(1, " moves.\n", 9);
			free_exit(game);
		}
	}
	return (0);
}

int	pos_player(t_long *game)
{
	if (game->lstplayer_x != -1)
	{
		get_text_num(game->lstplayer_x, game->lstplayer_y, game);
		print_texture(game, game->lstplayer_x, game->lstplayer_y);
	}
	get_text_num(game->player_x, game->player_y, game);
	print_texture(game, game->player_x, game->player_y);
	game->actual_text = 3;
	print_texture(game, game->player_x, game->player_y);
	game->lstplayer_x = game->player_x;
	game->lstplayer_y = game->player_y;
	reset_keyboard(game);
	return (0);
}

void	reset_keyboard(t_long *game)
{
	game->keyboard[ESC] = 0;
	game->keyboard[RIGHT] = 0;
	game->keyboard[LEFT] = 0;
	game->keyboard[BACK] = 0;
	game->keyboard[ADVANCE] = 0;
}

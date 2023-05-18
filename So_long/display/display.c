/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:00:29 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 12:00:31 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/****************************************************************************
	Let's create and display a game window with MiniLibX
	-'display'sets up the window, loads textures, renders the game elements,
		and writes messages to the output.
	-'handle_events' sets up event hooks for keyboard input and window visibility.
	-'key_loop' handles repetitive keyboard events, updating 
		the player's position and refreshing the window.
	-'render' iterates over coordinates and prints textures on the window. 
	-'create_win' initializes the window and relevant variables. 
*****************************************************************************/

int	display(t_long *game)
{
	create_win(game);
	load_texture(game);
	render(game);
	write(1, "\n\033[31mThe Game was launched successfully\n", 43);
	write(1, "MOVE : ", 8);
	ft_putnbr(game->move);
	pos_player(game);
	mlx_put_image_to_window(game->mlx_ptr,
		game->mlx_win, game->img, 0, 0);
	handle_events(game);
	return (0);
}

int	handle_events(t_long *game)
{
	mlx_hook(game->mlx_win, 2, 1L, ft_key_hit, game);
	mlx_hook(game->mlx_win, 15, 1L << 16, visible, game);
	mlx_hook(game->mlx_win, CLOSERED, 1L << 17, close_redbutton, game);
	mlx_loop_hook(game->mlx_ptr, key_loop, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

int	key_loop(t_long *game)
{
	ft_keyboard(game);
	if (game->keyboard[ESC] == 1 || game->keyboard[RIGHT] == 1
		|| game->keyboard[LEFT] == 1 || game->keyboard[BACK] == 1
		|| game->keyboard[ADVANCE] == 1)
	{
		pos_player(game);
		mlx_put_image_to_window(game->mlx_ptr,
			game->mlx_win, game->img, 0, 0);
	}
	return (0);
}

int	render(t_long *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->y)
	{
		while (x < game->x)
		{
			game->case_in++;
			get_text_num(x, y, game);
			print_texture(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	create_win(t_long *game)
{
	game->mlx_ptr = mlx_init();
	game->img = mlx_new_image(game->mlx_ptr, game->xscreen, game->yscreen);
	game->pxl = mlx_get_data_addr(game->img,
			&(game->bpp), &(game->s_line),
			&(game->ed));
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->xscreen,
			game->yscreen, "42 so_long nkuzminy");
	return (0);
}

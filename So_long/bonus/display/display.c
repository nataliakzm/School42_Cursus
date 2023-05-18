/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:44 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 15:57:46 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	display(t_long *game)
{
	create_win(game);
	load_texture(game);
	render(game);
	fix_bomb(game);
	write(1, "\n\033[31mThe Game was launched successfully\n", 43);
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
	char	*line;

	line = ft_itoa(game->move);
	if ((game->drop_bomb % 5000) == 0)
	{
		fix_bomb(game);
		mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 20,
			0xffffff, line);
		free(line);
	}
	game->drop_bomb++;
	ft_keyboard(game);
	if (game->keyboard[ESC] == 1 || game->keyboard[RIGHT] == 1
		|| game->keyboard[LEFT] == 1 || game->keyboard[BACK] == 1
		|| game->keyboard[ADVANCE] == 1)
	{
		pos_player(game);
		mlx_put_image_to_window(game->mlx_ptr,
			game->mlx_win, game->img, 0, 0);
		mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 20, 0xffffff,
			line);
		free(line);
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

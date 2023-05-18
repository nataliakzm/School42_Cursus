/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:58 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 15:58:00 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_key_hit(int keycode, t_long *game)
{
	game->keyboard[keycode] = 1;
	return (0);
}

int	ft_keyboard(t_long *game)
{
	if (game->keyboard[ADVANCE])
		move_player(1, game);
	if (game->keyboard[BACK])
		move_player(-1, game);
	if (game->keyboard[LEFT])
		move_player(2, game);
	if (game->keyboard[RIGHT])
		move_player(3, game);
	if (game->keyboard[ESC] == 1 || game->keyboard[RED_BUTTON] == 1)
		free_exit(game);
	return (0);
}

int	close_redbutton(t_long *game)
{
	free_exit(game);
	game->keyboard[79] = 1;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:00:44 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 12:00:46 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/****************************************************************************
	-'ft_key_hit' is called when a key is pressed. It sets the value
 		of the key in the keyboard array to 1.
	-'ft_keyboard' checks  the values of specific keys in the keyboard array
		and performs certain actions accordingly.
	-'close_redbutton' calls the 'free_exit' and sets the RED_BUTTON key 
		in the t_long structure to 1.
*****************************************************************************/

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

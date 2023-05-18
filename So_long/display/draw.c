/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:00:37 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 12:00:39 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/****************************************************************************
	-'put_pxl' is placing a pixel of a specified color at given coordinates 
		on the screen, performing boundary checks and calculating 
		the memory location based on screen dimensions. 
	-'visible' is part of a rendering and player positioning process.
*****************************************************************************/

int	put_pxl(t_long *game, int x, int y, unsigned int c)
{
	char		*dest;

	if (y >= game->yscreen || x >= game->xscreen || x < 0 \
	|| y < 0)
		return (0);
	dest = game->pxl + game->s_line * y + x * (game->bpp / 8);
	*(unsigned int *)dest = c;
	return (0);
}

int	visible(t_long *game)
{
	render(game);
	pos_player(game);
	mlx_put_image_to_window(game->mlx_ptr,
		game->mlx_win, game->img, 0, 0);
	return (0);
}

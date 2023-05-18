/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:00:55 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 12:00:57 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/****************************************************************************
	-'load_texture' loads several textures (the floor, border, player, invader
		 exit textures) into the game and retrieves their data and info 
		 like width, height, bits per pixel, and more.
	-'print_texture' prints a specific texture on the game screen. It retrieves 
		the color value of each pixel from the texture's data and checks 
		if != 0 (i.e., not transparent). If the color is non-zero, 
		it calls the 'put_pxl' to draw the pixel on the game screen.
	-'print_textures' determines the texture number to be used based on 
		the character found in the game's map at a specific position, e.g.,
		'0' for the floor, '1' for the border, 'P' for the player, etc.
*****************************************************************************/

int	load_texture(t_long *game)
{
	game->text[0] = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR,
			&game->wdth_text[0], &game->hght_text[0]);
	game->ptr_text[0] = mlx_get_data_addr(game->text[0],
			&(game->bpp_text[0]), &(game->sline_text[0]), &(game->ed_text[0]));
	game->text[1] = mlx_xpm_file_to_image(game->mlx_ptr, BORDER,
			&game->wdth_text[1], &game->hght_text[1]);
	game->ptr_text[1] = mlx_get_data_addr(game->text[1],
			&(game->bpp_text[1]), &(game->sline_text[1]), &(game->ed_text[1]));
	game->text[3] = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER,
			&game->wdth_text[3], &game->hght_text[3]);
	game->ptr_text[3] = mlx_get_data_addr(game->text[3],
			&(game->bpp_text[3]), &(game->sline_text[3]), &(game->ed_text[3]));
	game->text[2] = mlx_xpm_file_to_image(game->mlx_ptr, INVADER,
			&game->wdth_text[2], &game->hght_text[2]);
	game->ptr_text[2] = mlx_get_data_addr(game->text[2],
			&(game->bpp_text[2]), &(game->sline_text[2]), &(game->ed_text[2]));
	game->text[4] = mlx_xpm_file_to_image(game->mlx_ptr, EXIT,
			&game->wdth_text[4], &game->hght_text[4]);
	game->ptr_text[4] = mlx_get_data_addr(game->text[4],
			&(game->bpp_text[4]), &(game->sline_text[4]), &(game->ed_text[4]));
	return (0);
}

int	print_texture(t_long *game, int starter_X, int starter_Y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->hght_text[game->actual_text])
	{
		while (x < game->wdth_text[game->actual_text])
		{
			game->color = *(unsigned int *)(game->ptr_text[game->actual_text]
					+ game->sline_text[game->actual_text] * y + x
					* (game->bpp_text[game->actual_text] / 8));
			if (game->color != 0)
			{
				put_pxl(game, starter_X * 64 + x, starter_Y * 64
					+ y, game->color);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	get_text_num(int X, int Y, t_long *game)
{
	if (game->map[Y][X] == '0' || game->map[Y][X] == 'a')
		game->actual_text = 0;
	if (game->map[Y][X] == '1')
		game->actual_text = 1;
	if (game->map[Y][X] == 'C')
		game->actual_text = 2;
	if (game->map[Y][X] == 'E')
		game->actual_text = 4;
	if (game->map[Y][X] == 'P')
		game->actual_text = 0;
	return (0);
}

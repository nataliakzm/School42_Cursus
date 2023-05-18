/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:58:22 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 15:58:35 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	load_texture2(game);
	load_texture3(game);
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

int	get_text_num_bomb(t_long *game)
{
	if (game->spritebomb == 15)
		game->spritebomb = 5;
	game->actual_text = game->spritebomb;
	game->spritebomb++;
	return (0);
}

int	load_texture2(t_long *game)
{
	game->text[5] = mlx_xpm_file_to_image(game->mlx_ptr, BOMB1,
			&game->wdth_text[5], &game->hght_text[5]);
	game->ptr_text[5] = mlx_get_data_addr(game->text[5],
			&(game->bpp_text[5]), &(game->sline_text[5]), &(game->ed_text[5]));
	game->text[6] = mlx_xpm_file_to_image(game->mlx_ptr, BOMB2,
			&game->wdth_text[6], &game->hght_text[6]);
	game->ptr_text[6] = mlx_get_data_addr(game->text[6],
			&(game->bpp_text[6]), &(game->sline_text[6]), &(game->ed_text[6]));
	game->text[7] = mlx_xpm_file_to_image(game->mlx_ptr, BOMB3,
			&game->wdth_text[7], &game->hght_text[7]);
	game->ptr_text[7] = mlx_get_data_addr(game->text[7],
			&(game->bpp_text[7]), &(game->sline_text[7]), &(game->ed_text[7]));
	game->text[8] = mlx_xpm_file_to_image(game->mlx_ptr, BOMB4,
			&game->wdth_text[8], &game->hght_text[8]);
	game->ptr_text[8] = mlx_get_data_addr(game->text[8],
			&(game->bpp_text[8]), &(game->sline_text[8]), &(game->ed_text[8]));
	game->text[9] = mlx_xpm_file_to_image(game->mlx_ptr, BOMB5,
			&game->wdth_text[9], &game->hght_text[9]);
	game->ptr_text[9] = mlx_get_data_addr(game->text[9],
			&(game->bpp_text[9]), &(game->sline_text[9]), &(game->ed_text[9]));
	game->text[10] = mlx_xpm_file_to_image(game->mlx_ptr,
			BOMB6, &game->wdth_text[10],
			&game->hght_text[10]);
	return (0);
}

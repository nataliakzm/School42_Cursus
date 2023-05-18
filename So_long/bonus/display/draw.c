/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:50 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 15:57:54 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	fix_bomb(t_long *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->y)
	{
		while (x < game->x)
		{
			if (game->map[y][x] == 'B')
			{
				get_text_num_bomb(game);
				print_texture(game, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (game->drop_bomb == 100000)
		game->drop_bomb = 0;
	mlx_put_image_to_window(game->mlx_ptr,
		game->mlx_win, game->img, 0, 0);
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

int	load_texture3(t_long *game)
{
	game->ptr_text[10] = mlx_get_data_addr(game->text[10],
			&(game->bpp_text[10]), &(game->sline_text[10]),
			&(game->ed_text[10]));
	game->text[11] = mlx_xpm_file_to_image(game->mlx_ptr,
			BOMB7, &game->wdth_text[11], &game->hght_text[11]);
	game->ptr_text[11] = mlx_get_data_addr(game->text[11],
			&(game->bpp_text[11]), &(game->sline_text[11]),
			&(game->ed_text[11]));
	game->text[12] = mlx_xpm_file_to_image(game->mlx_ptr,
			BOMB8, &game->wdth_text[12], &game->hght_text[12]);
	game->ptr_text[12] = mlx_get_data_addr(game->text[12],
			&(game->bpp_text[12]), &(game->sline_text[12]),
			&(game->ed_text[12]));
	game->text[13] = mlx_xpm_file_to_image(game->mlx_ptr,
			BOMB9, &game->wdth_text[13], &game->hght_text[13]);
	game->ptr_text[13] = mlx_get_data_addr(game->text[13],
			&(game->bpp_text[13]), &(game->sline_text[13]),
			&(game->ed_text[13]));
	game->text[14] = mlx_xpm_file_to_image(game->mlx_ptr,
			BOMB10, &game->wdth_text[14], &game->hght_text[14]);
	game->ptr_text[14] = mlx_get_data_addr(game->text[14],
			&(game->bpp_text[14]), &(game->sline_text[14]),
			&(game->ed_text[14]));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:01:54 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/10 14:02:04 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"

// Notations for the keys:
# define ADVANCE	119
# define BACK		115
# define RIGHT		100
# define LEFT		97
# define ESC		65307
# define RED_BUTTON	79
# define CLOSERED	33

// Notations for the map:
# define MOVE_UP	1
# define MOVE_DOWN	-1
# define MOVE_LEFT	2
# define MOVE_RIGHT	3

// Notations for the textures:
# define FLOOR			"./textures/floor.xpm"
# define BORDER			"./textures/border.xpm"
# define PLAYER			"./textures/player.xpm"
# define INVADER		"./textures/invader.xpm"
# define EXIT			"./textures/exit.xpm"

// Notations for the extensions:
# define FILE_EXTENSION		".ber"

// Notations for the characters:
# define WALL_CHAR			'1'
# define FLOOR_CHAR			'0'
# define PLAYER_CHAR		'P'
# define EXIT_CHAR			'E'
# define COLLECTIBLE_CHAR	'C'

typedef struct s_long
{
	char			**map;
	int				xscreen;
	int				yscreen;
	int				x;
	int				y;
	int				oldx;
	int				move;	
	int				player_set;	
	int				player_x;
	int				player_y;
	int				lstplayer_x;
	int				lstplayer_y;
	int				collectible;
	int				collectible_set;	
	int				collectible_total;
	int				collectible_parse;	
	int				exit_set;
	int				exit_parse;

	char			*pxl;
	int				bpp;
	int				s_line;
	double			case_total;
	double			case_in;
	int				ed;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				keyboard[70000];
	int				maptofree;

	int				bpp_text[10];
	int				sline_text[10];
	int				ed_text[10];
	char			*ptr_text[10];
	void			*text[10];
	int				wdth_text[10];
	int				hght_text[10];
	int				actual_text;
	unsigned int	color;
}					t_long;

char	*read_line(int depth, int *ret, int fd);
char	*ft_strcpy(char *dest, char *src);
char	replace_char(char c);

void	flood_fill2(t_long *game, int mapy, int mapx);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	reset_keyboard(t_long *game);

size_t	ft_strlen(const char *s);

int		get_next_line(int fd, char **out);
int		get_map_dimension(t_long *game, char *argv);
int		visible(t_long *game);

int		parsing(t_long *game, char *argv);
int		store_map(t_long *game, char *argv);
int		malloc_map(t_long *game);
int		render_calcul(t_long *game);
int		render(t_long *game);

int		check_map(t_long *game);
int		num_blank(char *str);
int		get_next_line(int fd, char **line);
int		print_texture(t_long *game, int starter_X, int starter_Y);
int		show_error(t_long *game, char *str);
int		check_extension(char *filename, t_long *game);
int		pos_player(t_long *game);

int		init_player(t_long *game);
int		load_texture(t_long *game);
int		load_texture3(t_long *game);
int		get_text_num(int X, int Y, t_long *game);
int		move_player(int direction, t_long *game);
int		check_remove(t_long *game);
int		store_line(t_long *game, char *line, int nb);
int		checkifgood(char c);

int		check_wall(t_long *game);
int		flood_fill(t_long *game, int mapy, int mapx);
int		display_move(t_long *game, int direction);
int		free_map(t_long *game);

int		checkaround(int mapx, int mapy, t_long *game);
int		ft_key_hit(int keycode, t_long *game);
int		ft_key_release(int keycode, t_long *game);
int		ft_keyboard(t_long *display);
int		close_redbutton(t_long *game);
int		free_exit(t_long *game);
int		display(t_long *game);
int		handle_events(t_long *game);
int		create_win(t_long *game);
int		key_loop(t_long *game);
int		put_pxl(t_long *game, int x, int y, unsigned int c);
int		init_var(t_long *game);

#endif

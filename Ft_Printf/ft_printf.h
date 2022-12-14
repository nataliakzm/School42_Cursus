/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:50:59 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/25 14:03:20 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard C Libraries

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"

// Prototypes
typedef struct s_print
{
	va_list	args;
	int		len;
	int		wdh;
	int		dwidth;
	int		prc;
	int		zero;
	int		pnt;
	int		sign;
	int		total_len;
	int		is_zero;
	int		dash;
	int		percentage;
	int		space;
}	t_print;

// Functions
int		ft_printf(const char *string, ...);
t_print	*ft_init_tab(t_print *table);
char	*ft_check_str(t_print *table, const char *string);
int		ft_char_in_array(char c, char *array);

// Printing functions
void	ft_print_char(t_print *table);
void	ft_print_str(t_print *table);
void	ft_print_addr(t_print *table);
void	ft_print_numb(t_print *table, char di);
void	ft_print_unsnumb(t_print *table);
void	ft_print_hex_tab(t_print *table, char xX);

// Printing Hexadecimal
size_t	ft_print_hex(unsigned long long n, int err);
size_t	ft_print_hex_upper(unsigned long long n, int err);

// Putting number without negative sign
size_t	ft_putnbr_nodash(int n);

// Handling Lengths
size_t	ft_ptr_len(unsigned long int n);
size_t	ft_unint_len(unsigned int n);
size_t	ft_hex_len(unsigned int n);

// Padding
void	ft_right_cs(t_print *table, int mode);
void	ft_left_cs(t_print *table, int mode);

// Update Table
void	ft_update_r(t_print *table, char type, int negative);
void	ft_update_r2(t_print *table, int negative, int tmp);
void	ft_update_r3(t_print *table, int negative);
void	ft_update_l(t_print *table);

#endif

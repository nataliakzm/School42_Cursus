/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:09:20 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/26 13:37:08 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_r3(t_print *table, int negative)
{
	if (table->wdh && !table->dash)
	{
		ft_right_cs(table, 1);
		if (negative)
			table->total_len += ft_putchar_fd('-', 1);
	}
	else if (negative)
		table->total_len += ft_putchar_fd('-', 1);
}

void	ft_update_r2(t_print *table, int negative, int tmp)
{
	if (table->zero && !table->dash && table->wdh && !table->pnt)
	{
		if (negative)
			table->total_len += ft_putchar_fd('-', 1);
		ft_right_cs(table, 0);
	}
	else if (table->prc && table->wdh <= table->prc)
	{
		table->wdh = table->prc;
		if (negative)
			table->total_len += ft_putchar_fd('-', 1);
		ft_right_cs(table, 0);
	}
	else if (table->wdh > table->prc && table->zero && table->prc > table->len)
	{
		tmp = table->wdh;
		table->wdh -= table->prc - table->len;
		ft_right_cs(table, 1);
		if (negative)
			table->total_len += ft_putchar_fd('-', 1);
		table->wdh = tmp - table->wdh + table->len;
		ft_right_cs(table, 0);
	}
	else
		ft_update_r3(table, negative);
}

void	ft_update_r(t_print *table, char type, int negative)
{
	int	tmp;

	tmp = 0;
	if (ft_char_in_array(type, "csp"))
		if (table->wdh && !table->dash)
			ft_right_cs(table, 1);
	if (ft_char_in_array(type, "diuxX"))
		ft_update_r2(table, negative, tmp);
	if (type == 'p' && table->prc)
	{
		table->wdh = table->prc;
		ft_right_cs(table, 0);
	}
}

void	ft_update_l(t_print *table)
{
	if (table->dwidth && table->dash)
		ft_left_cs(table, 1);
}

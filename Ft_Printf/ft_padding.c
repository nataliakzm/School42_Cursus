/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:52:22 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/26 12:59:56 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_right_cs(t_print *table, int mode)
{
	int	n;

	n = table->wdh - table->len;
	if (!mode)
		while (n-- > 0)
			table->total_len += ft_putchar_fd('0', 1);
	else
		while (n-- > 0)
			table->total_len += ft_putchar_fd(' ', 1);
}

void	ft_left_cs(t_print *table, int mode)
{
	int	n;

	n = table->dwidth - table->len;
	if (table->wdh - table->len > 0)
		n -= table->wdh - table->len;
	if (!mode)
		while (n-- > 0)
			table->total_len += ft_putchar_fd('0', 1);
	else
		while (n-- > 0)
			table->total_len += ft_putchar_fd(' ', 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_csp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:05:46 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/26 14:15:48 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//in case of c modifier
void	ft_print_char(t_print *table)
{
	char	c;

	c = va_arg(table->args, int);
	table->len = 1;
	ft_update_r(table, 'c', 0);
	table->total_len += write(1, &c, 1);
	ft_update_l(table);
}

//in case of s modifier
void	ft_print_str(t_print *table)
{
	char	*str;

	str = va_arg(table->args, char *);
	if (!str)
		str = "(null)\0";
	table->len = ft_strlen(str);
	if (table->len > table->prc && table->pnt)
	{
		table->len = table->prc;
		if (!ft_strncmp(str, "(null)", 7))
			str = "";
	}
	ft_update_r(table, 's', 0);
	table->total_len += ft_putnstr_fd(str, table->len, 1);
	ft_update_l(table);
}

//in case of p modifer
void	ft_print_addr(t_print *table)
{
	unsigned long	addr;

	addr = va_arg(table->args, unsigned long);
	if (addr)
	{
		if (table->prc)
		{
			table->len = ft_ptr_len(addr);
			table->total_len += ft_putstr_fd("0x", 1);
		}
		else
			table->len = ft_ptr_len(addr) + 2;
	}
	else
		table->len = 5;
	ft_update_r(table, 'p', 0);
	if (!addr)
		table->total_len += ft_putstr_fd("(nil)\0", 1);
	else
	{
		if (!table->prc)
			table->total_len += ft_putstr_fd("0x", 1);
		table->total_len += ft_print_hex((unsigned long long)addr, 0);
	}
	ft_update_l(table);
}

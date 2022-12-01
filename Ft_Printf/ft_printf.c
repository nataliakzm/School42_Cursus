/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:46:59 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/12 15:02:12 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_init_tab(t_print *table)
{
	table -> len = 0;
	table -> wdh = 0;
	table -> dwidth = 0;
	table -> prc = 0;
	table -> zero = 0;
	table -> pnt = 0;
	table -> sign = 0;
	table -> total_len = 0;
	table -> is_zero = 0;
	table -> dash = 0;
	table -> percentage = 0;
	table -> space = 0;
	return (table);
}

int	ft_printf(const char *string, ...)
{
	unsigned int	retval;
	t_print			*table;

	table = (t_print *)malloc(sizeof(t_print));
	if (!table || !string)
		return (-1);
	ft_init_tab(table);
	va_start(table->args, string);
	retval = 0;
	while (*string)
	{
		if (*string != '%')
			retval += write(1, string, 1);
		else
		{
			string = ft_check_str(table, string + 1);
			retval += table ->total_len;
			ft_init_tab(table);
		}
		string++;
	}
	va_end(table->args);
	free(table);
	return (retval);
}

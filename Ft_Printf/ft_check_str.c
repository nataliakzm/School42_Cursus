/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:18:13 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/25 13:58:17 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_isflag2(t_print *table, const char *string)
{
	if (*string == ' ')
	{
		table->space = 1;
		string++;
	}
	if (*string == '+')
	{
		table->sign = 1;
		string++;
	}
	if (*string == '.')
	{
		table->pnt = 1;
		string++;
		if (*string == '0')
			string++;
	}
	return (string);
}

const char	*ft_isflag1(t_print *table, const char *string)
{
	if (*string == '#')
	{
		table->is_zero = 1;
		string++;
	}
	if (*string == '0')
	{
		table->zero = 1;
		string++;
	}
	if (*string == '-')
	{
		table->dash = 1;
		string++;
	}
	return (ft_isflag2(table, string));
}

const char	*ft_isconversion(t_print *table, const char *string)
{
	if (*string == 'c')
		ft_print_char(table);
	if (*string == 's')
		ft_print_str(table);
	if (*string == 'p')
		ft_print_addr(table);
	if (*string == 'd' || *string == 'i')
		ft_print_numb(table, *string);
	if (*string == 'u')
		ft_print_unsnumb(table);
	if (*string == 'x' || *string == 'X')
		ft_print_hex_tab(table, *string);
	if (*string == '%')
		table->total_len += write(1, "%", 1);
	return (string);
}

char	*ft_check_str(t_print *table, const char *string)
{
	while (!ft_char_in_array(*string, "cspdiuxX%"))
	{
		string = ft_isflag1(table, string);
		if (!ft_char_in_array(*string, "#0- +."))
		{
			if (ft_isdigit(*string))
			{
				if (*(string - 1) == '-')
					table->dwidth = ft_atoi(string);
				else if (*(string - 1) == '.')
					table->prc = ft_atoi(string);
				else
					table->wdh = ft_atoi(string);
				while (ft_isdigit(*string))
					string++;
			}
			else
				break ;
		}
	}
	return ((char *)ft_isconversion(table, string));
}

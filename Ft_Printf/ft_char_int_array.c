/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:04:50 by nkuzminy          #+#    #+#             */
/*   Updated: 2022/11/25 14:05:50 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_in_array(char c, char *array)
{
	while (*array)
	{
		if (c == *array)
			return (1);
		array++;
	}
	return (0);
}

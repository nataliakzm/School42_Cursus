/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuzminy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:14:22 by nkuzminy          #+#    #+#             */
/*   Updated: 2023/05/13 12:14:24 by nkuzminy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_long	solong;

	init_var(&solong);
	if (argc == 1)
		show_error(&solong, "Missing map (./so_long maps/map.ber or make run)");
	if (argc > 2)
		show_error(&solong, "Too many arguments");
	parsing(&solong, argv[1]);
	display(&solong);
	return (0);
}

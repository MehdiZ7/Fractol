/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:36:27 by mzouhir           #+#    #+#             */
/*   Updated: 2025/12/23 11:42:01 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (!check_input(ac, av))
		exit(1);
	data.name = av[1];
	if (create_window(&data))
		return (1);
	fractal_calcul(&data);
	events_init(&data);
	mlx_loop(data.mlx_ptr);
	clear_window(&data);
	return (0);
}

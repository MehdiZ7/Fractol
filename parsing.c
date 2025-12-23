/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:36:52 by mzouhir           #+#    #+#             */
/*   Updated: 2025/12/23 13:25:48 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	check_input(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot\0", 11))
		return (1);
	else if (ac == 4 && !ft_strncmp(av[1], "julia\0", 6))
		return (1);
	else
	{
		ft_printf("Invalid command\n");
		return (0);
	}
}

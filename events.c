/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouhir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:23:36 by mzouhir           #+#    #+#             */
/*   Updated: 2025/12/23 13:29:32 by mzouhir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"


int	key_handle(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		clear_window(data);
		exit (0);
	}
	else if (keysym == XK_minus || keysym == XK_Page_Down)
		data->iteration -= 10;
	else if (keysym == XK_plus || keysym == XK_Page_Up)
		data->iteration += 10;
	else if (keysym == XK_Left)
		data->shift_x += 0.2;
	else if (keysym == XK_Right)
		data->shift_x -= 0.2;
	else if (keysym == XK_Up)
		data->shift_y -= 0.2;
	else if (keysym == XK_Down)
		data->shift_y += 0.2;
	fractal_calcul(data);
	return (0);
}

int	cross_handle(t_mlx_data *data)
{
	clear_window(data);
	exit (0);
}

int	mouse_handle(int button, int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	if (button == Button5)
		data->zoom *= 0.95;
	else if (button == Button4)
		data->zoom *= 1.05;
	fractal_calcul(data);
	return (0);
}

void	events_init(t_mlx_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_handle, data);
	mlx_hook(data->win_ptr, ButtonPress, ButtonPress, mouse_handle, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, cross_handle, data);
}

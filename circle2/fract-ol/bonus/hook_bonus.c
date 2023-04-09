/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:10:53 by yomin             #+#    #+#             */
/*   Updated: 2022/08/30 18:32:40 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	zoom(int btn, int x_pos, int y_pos, t_data *data)
{
	if (btn == 4)
	{
		if (data->z > 0)
			data->z = (1 / 1.2);
	}
	else if (btn == 5)
	{
		data->z *= 1.148;
	}
	else if (btn == 1)
	{
		moving(data, x_pos, y_pos);
		return (0);
	}
	acting(data, x_pos, y_pos);
	return (0);
}

int	move_m(int x_pos, int y_pos, t_data *data)
{
	int	tmp;

	tmp = x_pos;
	tmp = y_pos;
	if (data->mouse_flag == -1)
		return (0);
	if (data->re_flag == 1)
		data->c_re += 0.005;
	else if (data->re_flag == -1)
		data->c_re += -0.005;
	if (data->im_flag == 1)
		data->c_im += 0.005;
	else
		data->c_im += -0.005;
	if (data->c_re >= 0.48 || data->c_re < -0.8)
		data->re_flag *= -1;
	if (data->c_im >= 0.8 || data->c_im <= -0.8)
		data->im_flag *= -1;
	re_paint(data);
	return (0);
}

void	move_fractal(int key, t_data *data)
{
	if (data->iter_max <= 0)
		return ;
	if (key == 126)
		data->y += 20;
	else if (key == 125)
		data->y -= 20;
	else if (key == 123)
		data->x -= 20;
	else if (key == 124)
		data->x += 20;
	re_paint(data);
}

void	zooming_key_hook(int key, t_data *data)
{
	if (key == 0)
	{
		if (data->iter_max < 1000)
			data->iter_max *= 2;
	}
	else if (key == 1)
	{
		data->iter_max /= 2;
		if (data->iter_max < 1)
			data->iter_max = 1;
	}
	else if (key == 12)
		data->mouse_flag *= -1;
}

int	press_key_hook(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	else if (key == 126 || key == 125 || key == 123 || key == 124)
		move_fractal(key, data);
	else if (key == 27)
	{
		if (data->no_flag == 1)
			set_mandel_basic(1, data);
		else if (data->no_flag == 2)
			set_julia_basic(2, data);
		else if (data->no_flag == 3)
			set_ship_basic(3, data);
	}
	else if (key == 0 || key == 1 || key == 12)
		zooming_key_hook(key, data);
	re_paint(data);
	return (0);
}

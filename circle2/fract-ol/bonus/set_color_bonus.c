/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:04 by yomin             #+#    #+#             */
/*   Updated: 2022/08/29 18:11:05 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	set_color_mandel(t_data *data)
{
	double	tmp;
	int		col;

	data->r = 1.2 * (data->iter_max - data->cur_iter) / data->iter_max * 0xf;
	data->g = data->r * 1.8;
	data->b = data->r * 1.7;
	if (data->iter_max == data->cur_iter)
		data->cur_iter = 0;
	tmp = 1.0 * data->cur_iter / data->iter_max;
	tmp *= 4;
	col = ((int)tmp << 24) + ((int)data->r << 16) + \
	((int)data->g << 8) + ((int)data->b);
	return (col);
}

int	set_color_jul(t_data *data)
{
	int		col_tmp;
	int		col;

	data->g = 0x0000ff00;
	data->b = 0x000000ff;
	if (data->iter_max == data->cur_iter)
		data->cur_iter = 0;
	col = 0x15000000;
	col_tmp = data->r + data->g + data->b;
	return (col_tmp);
}

int	set_color_ship(t_data *data)
{
	double	tmp;
	int		col;

	data->r = 1.2 * (data->iter_max - data->cur_iter) / data->iter_max * 0xf;
	data->g = data->r * 1.8;
	data->b = data->r * 1.7;
	if (data->iter_max == data->cur_iter)
		data->cur_iter = 0;
	tmp = 1.0 * data->cur_iter / data->iter_max;
	tmp *= 4;
	col = ((int)tmp << 24) + ((int)data->r << 16) + \
	((int)data->g << 8) + ((int)data->b);
	return (col);
}

void	_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	unsigned int	*dst;
	char			*tmp;

	tmp = data->img_data + (x * data->bpp / 8) + (y * data->line_l);
	dst = (unsigned int *)tmp;
	*dst = (unsigned int)color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:09:05 by yomin             #+#    #+#             */
/*   Updated: 2022/08/29 18:09:07 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_julia(int w_cnt, int h_cnt, int iter, t_data *data)
{
	double	re;
	double	x_new;
	double	im;

	re = data->min_re + (data->max_re - data->min_re) * \
	(w_cnt + data->x) / WIN_WIDTH;
	im = data->min_im + (data->max_im - data->min_im) * \
	(h_cnt + data->y) / WIN_HEIGHT;
	while (((re * re) + (im * im) < 4) && (iter < data->iter_max))
	{
		x_new = (re * re) - (im * im) + data->c_re;
		im = 2 * re * im + data->c_im;
		re = x_new;
		iter++;
	}
	return (iter);
}

void	put_julia(t_data *data)
{
	int	iter;
	int	w_cnt;
	int	h_cnt;

	h_cnt = 0;
	while (h_cnt < WIN_HEIGHT)
	{
		w_cnt = 0;
		while (w_cnt < WIN_WIDTH)
		{
			iter = get_julia(w_cnt, h_cnt, 0, data);
			if (iter < data->iter_max)
				_mlx_pixel_put(data, w_cnt, h_cnt, (0x000000 + iter));
			else
				_mlx_pixel_put(data, w_cnt, h_cnt, 0xffffff);
			++w_cnt;
		}
		++h_cnt;
	}
}

void	set_julia_basic(int no, t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->iter_max = 120;
	data->z = 1;
	data->max_im = 2;
	data->max_re = 2;
	data->min_re = -2;
	data->min_im = -2;
	data->c_re = -0.4;
	data->c_im = -0.6;
	data->re_flag = 1;
	data->im_flag = 1;
	data->win_name = "julia";
	data->no_flag = no;
	data->mouse_flag = 1;
}

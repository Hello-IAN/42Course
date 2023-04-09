/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:07 by yomin             #+#    #+#             */
/*   Updated: 2022/08/29 18:11:08 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	get_b_ship(int w_cnt, int h_cnt, int iter, t_data *data)
{
	double	c_re;
	double	c_im;
	double	new;
	double	re;
	double	im;

	c_re = data->min_re + (data->max_re - data->min_re) * \
	(w_cnt + data->x) / WIN_WIDTH;
	c_im = data->min_im + (data->max_im - data->min_im) * \
	(h_cnt + data->y) / WIN_HEIGHT;
	re = 0;
	im = 0;
	while (((re * re) + (im * im) < 4) && (iter < data->iter_max))
	{
		new = (re * re) - (im * im) + c_re;
		im = fabs(2 * re * im) + c_im;
		re = new;
		iter++;
	}
	data->cur_iter = iter;
	return (iter);
}

void	put_b_ship(t_data *data)
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
			iter = get_b_ship(w_cnt, h_cnt, 0, data);
			data->cur_color = set_color_ship(data);
			if (iter < data->iter_max)
				_mlx_pixel_put(data, w_cnt, h_cnt, \
				(0x000000 + (iter * data->cur_color)));
			else
				_mlx_pixel_put(data, w_cnt, h_cnt, 0x000000);
			++w_cnt;
		}
		++h_cnt;
	}
}

void	set_ship_basic(int no, t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->iter_max = 120;
	data->z = 1;
	data->max_im = 1;
	data->max_re = 1;
	data->min_re = -2.5;
	data->min_im = -1;
	data->c_re = -0.4;
	data->c_im = -0.6;
	data->re_flag = 1;
	data->im_flag = 1;
	data->abs = 0;
	data->win_name = "burning_ship";
	data->no_flag = no;
}

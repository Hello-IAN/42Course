/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:10:47 by yomin             #+#    #+#             */
/*   Updated: 2022/08/29 18:10:48 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	re_paint(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (data->no_flag == 1)
		put_mandel(data);
	else if (data->no_flag == 2)
		put_julia(data);
	else if (data->no_flag == 3)
		put_b_ship(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}

void	moving(t_data *data, int x_pos, int y_pos)
{
	double	tmp;
	double	tmp2;

	tmp = data->min_re + (data->max_re - data->min_re) * x_pos / WIN_WIDTH;
	tmp2 = tmp - (data->max_re - data->min_re) / 2 ;
	data->max_re = tmp + (data->max_re - data->min_re) / 2;
	data->min_re = tmp2;
	tmp = data->min_im + (data->max_im - data->min_im) * y_pos / WIN_HEIGHT;
	tmp2 = tmp - (data->max_im - data->min_im) / 2;
	data->max_im = tmp + (data->max_im - data->min_im) / 2;
	data->min_im = tmp2;
	re_paint(data);
}

void	acting(t_data *data, int x_pos, int y_pos)
{
	double	tmp;
	double	tmp2;

	tmp = data->min_re + (data->max_re - data->min_re) * x_pos / WIN_WIDTH;
	tmp2 = tmp - (data->max_re - data->min_re) / 2 / data->z;
	data->max_re = tmp + (data->max_re - data->min_re) / 2 / data->z;
	data->min_re = tmp2;
	tmp = data->min_im + (data->max_im - data->min_im) * y_pos / WIN_HEIGHT;
	tmp2 = tmp - (data->max_im - data->min_im) / 2 / data->z;
	data->max_im = tmp + (data->max_im - data->min_im) / 2 / data->z;
	data->min_im = tmp2;
	re_paint(data);
}

void	init_fractal(int no)
{
	t_data	data;

	if (no == 1)
		set_mandel_basic(no, &data);
	else if (no == 2)
		set_julia_basic(no, &data);
	else if (no == 3)
		set_ship_basic(no, &data);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
	data.win_name);
	data.img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img_data = mlx_get_data_addr(data.img, &data.bpp, &data.line_l, \
	&data.endian);
	re_paint(&data);
	mlx_key_hook(data.mlx_win, press_key_hook, &data);
	mlx_mouse_hook(data.mlx_win, zoom, &data);
	if (data.no_flag == 2 && data.mouse_flag == 1)
		mlx_hook(data.mlx_win, 6, 6, move_m, &data);
	mlx_loop(data.mlx_ptr);
}

int	main(int argc, char *argv[])
{
	int		init_flag;	

	init_flag = isvalid(argc, argv[1]);
	if (init_flag <= 0)
	{
		write(2, "invalid argument\n", 17);
		return (-1);
	}
	else if (init_flag == 1 || init_flag == 2 || init_flag == 3)
		init_fractal(init_flag);
	else
	{
		write(2, "can't execute fractal\n", 22);
		return (-1);
	}
	return (0);
}

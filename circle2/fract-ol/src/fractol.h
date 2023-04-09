/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:10:34 by yomin             #+#    #+#             */
/*   Updated: 2022/08/29 18:10:36 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1280

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct s_data {
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*img_data;
	char	*win_name;
	int		bpp;
	int		line_l;
	int		endian;
	int		iter_max;
	int		abs;
	int		r;
	int		g;
	int		b;
	int		cur_iter;
	int		cur_color;
	int		re_flag;
	int		im_flag;
	int		no_flag;
	int		mouse_flag;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	z;
	double	x;
	double	y;
	double	c_re;
	double	c_im;
}	t_data;

int		ft_strcmp(char *s1, char *s2);
int		isvalidname(char *name);
int		isvalid(int argc, char *name);
int		set_color_mandel(t_data *data);
int		set_color_jul(t_data *data);
int		set_color_ship(t_data *data);
int		get_mandel(int w_cnt, int h_cnt, int iter, t_data *data);
int		get_julia(int w_cnt, int h_cnt, int iter, t_data *data);
int		move_m(int x_pos, int y_pos, t_data *data);
int		zoom(int btn, int x_pos, int y_pos, t_data *data);
int		press_key_hook(int key, t_data *data);
int		main(int argc, char *argv[]);
void	re_paint(t_data *data);
void	moving(t_data *data, int x_pos, int y_pos);
void	acting(t_data *data, int x_pos, int y_pos);
void	init_fractal(int no);
void	_mlx_pixel_put(t_data *data, int x, int y, int color);
void	move_fractal(int key, t_data *data);
void	zooming_key_hook(int key, t_data *data);
void	put_mandel(t_data *data);
void	put_julia(t_data *data);
void	set_mandel_basic(int no, t_data *data);
void	set_julia_basic(int no, t_data *data);
#endif

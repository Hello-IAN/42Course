/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:28:21 by yomin             #+#    #+#             */
/*   Updated: 2023/02/22 13:33:42 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../includes/ray.h"
#include "../includes/cam.h"
#include "../includes/mlx_window.h"

int	write_color(int a, t_color pixel_color)
{
	return (a << 24 | (int)(255.999 * pixel_color.x) << 16 | \
		(int)(255.999 * pixel_color.y) << 8 | (int)(255.999 * pixel_color.z));
}

/* input a color to pixel of window */
void	put_pixel_to_window(t_img_data *img, int x, int y, int color)
{
	char			*dst;
	unsigned int	*tmp;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	tmp = (unsigned int *)dst;
	*tmp = color;
}

void	draw_test(t_vars *vars)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color		pixel_color;

	j = vars->image_height - 1;
	control_camera(vars);
	while (j > 0)
	{
		i = 0;
		while (i < vars->image_width)
		{
			u = (double)i / (vars->image_width - 1);
			v = (double)j / (vars->image_height - 1);
			vars->ray = ray_primary(vars, u, v);
			pixel_color = ray_color(vars, 1);
			put_pixel_to_window(\
			vars->img, i, vars->image_height - j, write_color(0, pixel_color));
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_ptr, 0, 0);
}

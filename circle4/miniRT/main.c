/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:45:54 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/23 16:42:36 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/mlx_window.h"
#include "./includes/object.h"
#include "./includes/vec.h"
#include "./includes/vars.h"
#include "./includes/ray.h"
#include "./includes/cam.h"
#include "./includes/parser.h"
#include <math.h>
#include <stdlib.h>

void	mlx_screen(const char *filename)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		execute_err(2);
	ft_memset(vars, 0, sizeof(t_vars));
	vars->image_width = 640;
	vars->image_height = 400;
	parse(filename, vars);
	if (!vars->lights || !vars->cam)
		execute_err(3);
	vars->img = malloc(sizeof(t_img_data));
	vars->mlx = mlx_init();
	vars->win = \
	mlx_new_window(vars->mlx, vars->image_width, vars->image_height, "miniRT");
	vars->img->img_ptr = \
	mlx_new_image(vars->mlx, vars->image_width, vars->image_height);
	vars->img->addr = mlx_get_data_addr(vars->img->img_ptr, &vars->img->bpp, \
	&vars->img->line_length, &vars->img->endian);
	draw_test(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		write(2, "fail to execute, can't found file\n", 34);
		return (1);
	}
	if (vaild_check(argv[1]))
		return (1);
	mlx_screen(argv[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:04:46 by yomin             #+#    #+#             */
/*   Updated: 2023/02/23 16:30:53 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_window.h"
#include "stdlib.h"

void	camera_key_hook_org(int keycode, t_vars *vars)
{
	if (keycode == 12)
		vars->camera_origin = init_point(vars->camera_origin.x, \
		vars->camera_origin.y + 2, vars->camera_origin.z);
	else if (keycode == 0)
		vars->camera_origin = init_point(vars->camera_origin.x - 2, \
		vars->camera_origin.y, vars->camera_origin.z);
	else if (keycode == 13)
		vars->camera_origin = init_point(vars->camera_origin.x, \
		vars->camera_origin.y, vars->camera_origin.z - 2);
	else if (keycode == 1)
		vars->camera_origin = init_point(vars->camera_origin.x, \
		vars->camera_origin.y, vars->camera_origin.z + 2);
	else if (keycode == 14)
		vars->camera_origin = init_point(vars->camera_origin.x, \
		vars->camera_origin.y - 2, vars->camera_origin.z);
	else if (keycode == 2)
		vars->camera_origin = init_point(vars->camera_origin.x + 2, \
		vars->camera_origin.y, vars->camera_origin.z);
}

void	camera_key_hook_dir(int keycode, t_vars *vars)
{
	if (keycode == 123)
		vars->camera_dir = init_point(vars->camera_dir.x + 0.3, \
		vars->camera_dir.y, vars->camera_dir.z);
	else if (keycode == 124)
		vars->camera_dir = init_point(vars->camera_dir.x - 0.3, \
		vars->camera_dir.y, vars->camera_dir.z);
	else if (keycode == 125)
		vars->camera_dir = init_point(vars->camera_dir.x, \
		vars->camera_dir.y + 0.3, vars->camera_dir.z);
	else if (keycode == 126)
		vars->camera_dir = init_point(vars->camera_dir.x, \
		vars->camera_dir.y - 0.3, vars->camera_dir.z);
}

int	camera_key_hook(int keycode, t_vars *vars)
{
	if (keycode == 12 || keycode == 0 || keycode == 13 || keycode == 1 || \
	keycode == 14 || keycode == 2)
		camera_key_hook_org(keycode, vars);
	else if (keycode == 123 || keycode == 124 || keycode == 125 || \
			keycode == 126)
		camera_key_hook_dir(keycode, vars);
	mlx_clear_window(vars->mlx, vars->win);
	draw_test(vars);
	return (0);
}

int	light_key_hook(int keycode, t_vars *vars)
{
	t_light	*light;

	light = vars->lights->element;
	if (keycode == 16)
		light->origin.x++;
	else if (keycode == 4)
		light->origin.x--;
	else if (keycode == 32)
		light->origin.y++;
	else if (keycode == 38)
		light->origin.y--;
	else if (keycode == 34)
		light->origin.z++;
	else if (keycode == 40)
		light->origin.z--;
	mlx_clear_window(vars->mlx, vars->win);
	draw_test(vars);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
	{
		camera_key_hook(keycode, vars);
		light_key_hook(keycode, vars);
	}
	return (0);
}

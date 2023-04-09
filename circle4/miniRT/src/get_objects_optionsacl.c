/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_optionsacl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:16 by yomin             #+#    #+#             */
/*   Updated: 2023/02/16 21:18:17 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"
#include "../includes/cam.h"

/* check a option_cnt is three,
it meaning options setting was success.

fill a info object and check each range ratio and color,
then, fill a information in vars->ambient

if malloc fail when get option, info object
call execute err func.
or call free func for each objects.*/
void	set_ambient_light(const char *line, t_vars *vars)
{
	t_info		*info;
	t_options	*options;

	options = get_options(line);
	if (!options || options->option_cnt != 2)
		execute_err(1);
	info = malloc(sizeof(t_info));
	if (!info)
		execute_err(2);
	ft_memset(info, 0, sizeof(t_info));
	if (!is_valid_range_ratio(info, (const char **)options->option[0]) || \
		!is_valid_range_color(info, (const char **)options->option[1]))
		execute_err(1);
	vars->ambient = vec_mult_val(init_color(\
	info->colors[0], info->colors[1], info->colors[2]), info->ratio);
	free_input_objects(info, options);
}

/* check a option_cnt is three,
it meaning options setting was success.

fill a info object and check each coordinates point, 3d_vector,
and fov is in range.

then, fill a information is success, allocate t_camera obejct,
and call control_camera func.

if malloc fail when get option, info, vars->cam object
call execute err func.
or call free func for each objects.*/
void	set_cam(const char *line, t_vars *vars)
{
	t_info		*info;
	t_options	*options;

	options = get_options(line);
	if (!options || options->option_cnt != 3)
		execute_err(1);
	info = malloc(sizeof(t_info));
	if (!info)
		execute_err(2);
	ft_memset(info, 0, sizeof(t_info));
	if (!get_cooridinates_point(info, (const char **)options->option[0]) || \
		!get_3d_vector(info, (const char **)options->option[1]) || \
		!is_valid_range_fov(info, (const char **)options->option[2]))
		execute_err(1);
	vars->cam = malloc(sizeof(t_camera));
	if (!vars->cam)
		execute_err(2);
	vars->camera_origin = init_point(info->xyz[0], info->xyz[1], info->xyz[2]);
	vars->camera_dir = init_point(info->vector[0], info->vector[1], \
	info->vector[2]);
	vars->cam->fov = info->temp;
	control_camera(vars);
	free_input_objects(info, options);
}

/* check a option_cnt is 2 in mandetory parts,
but, bonus parts has difference. 
beacuse of a color set unused in mandetory parts a option_cnt should be 3.
it meaning options setting was success.

next, fill a info object coordinates light points, ratio range.
if for bonus parts, fill color set.

if malloc fail when get option, info, vars->cam object
call execute err func.
or call free func for each objects. */
void	set_light(const char *line, t_vars *vars)
{
	t_info		*info;
	t_options	*options;

	options = get_options(line);
	if (!options || options->option_cnt != 2)
		execute_err(1);
	info = malloc(sizeof(t_info));
	if (!info)
		execute_err(2);
	ft_memset(info, 0, sizeof(t_info));
	if (!get_cooridinates_point(info, (const char **)options->option[0]) || \
		!is_valid_range_ratio(info, (const char **)options->option[1]))
		execute_err(1);
	vars->light_point = init_point(info->xyz[0], info->xyz[1], info->xyz[2]);
	vars->lights = make_object(LIGHT, make_light_point(vars->light_point, \
		init_color(1, 1, 1), info->ratio), init_color(1, 1, 1));
	free_input_objects(info, options);
}

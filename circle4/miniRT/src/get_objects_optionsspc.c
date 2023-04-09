/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_optionsspc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:21 by yomin             #+#    #+#             */
/*   Updated: 2023/02/22 12:27:47 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/* check a option value is fure float and
get param int, check input target is. 
0 is diameter
1 is height */
static int	get_diameter(t_info *info, const char **option, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		info->diam = ft_atod(option[i]);
	else if (n == 1)
		info->height = ft_atod(option[i]);
	if (option[1])
		return (0);
	return (1);
}

/* check world already exist, call object_add or make first object of world
about cylinder. 
it can be extend get number
1 call about sphere
2 call about plane
3 call about cylinder
*/
static void	fill_world(t_vars *vars, t_info *info)
{
	if (!vars->world)
		vars->world = make_object(CYLINDER, make_cylinder(\
		init_point(info->xyz[0], info->xyz[1], info->xyz[2]), \
		vec_unit(\
		init_point(info->vector[0], info->vector[1], info->vector[2])), \
		info->diam, info->height), \
		init_color(info->colors[0], info->colors[1], info->colors[2]));
	else
		object_add(&vars->world, make_object(CYLINDER, make_cylinder(\
		init_point(info->xyz[0], info->xyz[1], info->xyz[2]), \
		vec_unit(\
		init_point(info->vector[0], info->vector[1], info->vector[2])), \
		info->diam, info->height), \
		init_color(info->colors[0], info->colors[1], info->colors[2])));
}
/* static void	fill_world(t_vars *vars, t_info *info, int n)
{
	if (n == 1)
	{
		if (!vars->world)
			vars->world = make_object(n, make_sphere(init_point(\
			info->xyz[0], info->xyz[1], info->xyz[2]), info->diam), \
			init_color(info->colors[0], info->colors[1], info->colors[2]));
		else
			object_add(&vars->world, make_object(n, make_sphere(init_point(\
			info->xyz[0], info->xyz[1], info->xyz[2]), info->diam), \
			init_color(info->colors[0], info->colors[1], info->colors[2])));
	}
	else if (n == 2)
	{
		if (!vars->world)
			vars->world = make_object(n, make_plane(init_point(\
			info->xyz[0], info->xyz[1], info->xyz[2]), vec_unit(\
			init_point(info->vector[0], info->vector[1], info->vector[2]))), \
			init_color(info->colors[0], info->colors[1], info->colors[2]));
		else
			object_add(&vars->world, make_object(n, make_plane(init_point(\
			info->xyz[0], info->xyz[1], info->xyz[2]), vec_unit(\
			init_point(info->vector[0], info->vector[1], info->vector[2]))), \
			init_color(info->colors[0], info->colors[1], info->colors[2])));

	}
	else if (n == 3)
	{
		if (!vars->world)
			vars->world = make_object(n, make_cylinder(\
			init_point(info->xyz[0], info->xyz[1], info->xyz[2]), \
			vec_unit(init_point(info->vector[0], info->vector[1], info->vector[2])), \
			info->diam, info->height), \
			init_color(info->colors[0], info->colors[1], info->colors[2]));
		else
			object_add(&vars->world, make_object(n, make_cylinder(\
			init_point(info->xyz[0], info->xyz[1], info->xyz[2]), \
			vec_unit(init_point(info->vector[0], info->vector[1], info->vector[2])), \
			info->diam, info->height), \
			init_color(info->colors[0], info->colors[1], info->colors[2])));
	}
}

*/

/* check a option_cnt is three,
it meaning options setting was success.

fill a info object and check each coordinates point, diameter
and colorset is in range.

if malloc fail when get option, info.
call execute err func.
or call free func for each objects.*/
void	set_sphere(const char *line, t_vars *vars)
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
		!get_diameter(info, (const char **)options->option[1], 0) || \
		!is_valid_range_color(info, (const char **)options->option[2]))
		execute_err(1);
	if (!vars->world)
		vars->world = make_object(SPHERE, make_sphere(init_point(\
		info->xyz[0], info->xyz[1], info->xyz[2]), info->diam), \
		init_color(info->colors[0], info->colors[1], info->colors[2]));
	else
		object_add(&vars->world, make_object(SPHERE, make_sphere(init_point(\
		info->xyz[0], info->xyz[1], info->xyz[2]), info->diam), \
		init_color(info->colors[0], info->colors[1], info->colors[2])));
	free_input_objects(info, options);
}

/* check a option_cnt is three,
it meaning options setting was success.

fill a info object and check each coordinates point, vector
and colorset is in range.

if malloc fail when get option, info.
call execute err func.
or call free func for each objects.*/
void	set_plane(const char *line, t_vars *vars)
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
		!is_valid_range_color(info, (const char **)options->option[2]))
		execute_err(1);
	if (!vars->world)
		vars->world = make_object(PLANE, make_plane(init_point(\
		info->xyz[0], info->xyz[1], info->xyz[2]), vec_unit(\
		init_point(info->vector[0], info->vector[1], info->vector[2]))), \
		init_color(info->colors[0], info->colors[1], info->colors[2]));
	else
		object_add(&vars->world, make_object(PLANE, make_plane(init_point(\
			info->xyz[0], info->xyz[1], info->xyz[2]), vec_unit(\
			init_point(info->vector[0], info->vector[1], info->vector[2]))), \
			init_color(info->colors[0], info->colors[1], info->colors[2])));
	free_input_objects(info, options);
}

/* check a option_cnt is 5,
it meaning options setting was success.

fill a info object and check each coordinates point, vector,
diameter, height, and colorset is in range.

if malloc fail when get option, info.
call execute err func.
or call free func for each objects.*/
void	set_cylinder(const char *line, t_vars *vars)
{
	t_info		*info;
	t_options	*options;

	options = get_options(line);
	if (!options || options->option_cnt != 5)
		execute_err(1);
	info = malloc(sizeof(t_info));
	if (!info)
		execute_err(2);
	ft_memset(info, 0, sizeof(t_info));
	if (!get_cooridinates_point(info, (const char **)options->option[0]) || \
		!get_3d_vector(info, (const char **)options->option[1]) || \
		!get_diameter(info, (const char **)options->option[2], 0) || \
		!get_diameter(info, (const char **)options->option[3], 1) || \
		!is_valid_range_color(info, (const char **)options->option[4]))
		execute_err(1);
	fill_world(vars, info);
	free_input_objects(info, options);
}

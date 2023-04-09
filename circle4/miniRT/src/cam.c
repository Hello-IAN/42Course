/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:55:14 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/23 16:32:55 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cam.h"
#include "../includes/vars.h"
#include "../includes/vec.h"
#include <math.h>
#include <stdlib.h>

t_vec	vup(t_vec dir)
{
	if (dir.x == 0 && dir.y != 0 && dir.z == 0)
		return (init_vec(0, dir.y, 1e-6));
	else if (dir.x == 0 && dir.y == -1 && dir.z == 0)
		return (init_vec(0, 0, -1));
	else if (dir.x == 0 && dir.y == 1 && dir.z == 0)
		return (init_vec(0, 0, 1));
	return (init_vec(0, 1, 0));
}

void	control_camera(t_vars *vars)
{
	t_point3		cam_unit_dir;
	const double	theta = vars->cam->fov * (M_PI / 180.0);
	double			h;
	t_vec			u;
	t_vec			v;

	h = tan(theta / 2);
	cam_unit_dir = vec_unit(vars->camera_dir);
	vars->cam->aspect_ratio = \
		(double)vars->image_width / (double)vars->image_height;
	vars->cam->viewport_height = 2.0 * h;
	vars->cam->viewport_width = \
		vars->cam->aspect_ratio * vars->cam->viewport_height;
	u = vec_unit(vec_cross(vup(cam_unit_dir), cam_unit_dir));
	v = vec_cross(cam_unit_dir, u);
	vars->cam->origin = vars->camera_origin;
	vars->cam->horizontal = vec_mult_val(u, vars->cam->viewport_width);
	vars->cam->vertical = vec_mult_val(v, vars->cam->viewport_height);
	vars->cam->left_bottom = vec_minus_vec \
		(vec_minus_vec \
		(vec_minus_vec \
		(vars->cam->origin, vec_divide_val \
		(vars->cam->horizontal, 2)), \
		vec_divide_val(vars->cam->vertical, 2)), cam_unit_dir);
}

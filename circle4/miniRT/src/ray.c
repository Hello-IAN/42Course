/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:49:56 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/10 07:29:49 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vars.h"
#include "../includes/ray.h"
#include "../includes/object.h"
#include "../includes/vec.h"
#include <stdlib.h>
#include <math.h>

t_ray	ray(t_point3 origin, t_vec dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = vec_unit(dir);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	return ((t_point3)vec_plus_vec(ray->origin, vec_mult_val(ray->dir, t)));
}

t_ray	ray_primary(t_vars *vars, double u, double v)
{
	t_ray	ray;

	ray.origin = vars->cam->origin;
	ray.dir = vec_unit \
	(vec_minus_vec \
	(vec_plus_vec \
	(vec_plus_vec \
	(vars->cam->left_bottom, vec_mult_val(vars->cam->horizontal, u)), \
	vec_mult_val(vars->cam->vertical, v)), vars->cam->origin));
	return (ray);
}

t_color	ray_color(t_vars *vars, int depth)
{
	double			t;

	if (depth <= 0)
		return (init_color(0, 0, 0));
	vars->rec = init_record();
	if (hit(vars->world, &vars->ray, &vars->rec))
	{
		ray_color(vars, depth - 1);
		return (phong_lighting(vars));
	}
	else
	{
		t = 0.5 * (vars->ray.dir.y + 1.0);
		return (vec_plus_vec \
			(vec_mult_val(init_color(1, 1, 1), 1.0 - t), \
			vec_mult_val(init_color(0.5, 0.7, 1.0), t)));
	}
}

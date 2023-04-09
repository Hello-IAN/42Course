/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:15:29 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 20:41:11 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ray.h"
#include "../includes/vec.h"
#include "../includes/vars.h"
#include "../includes/trace.h"
#include "../includes/object.h"
#include <math.h>

t_vec	reflect(t_vec v, t_vec n)
{
	return (vec_minus_vec(v, vec_mult_val(n, vec_dot(v, n) * 2)));
}

int	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 1e-6;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (1);
	return (0);
}

t_light_point	get_light_parameter(t_vars *vars, t_light *light)
{
	t_light_point	light_point;

	light_point.light_dir = vec_minus_vec(light->origin, vars->rec.p);
	light_point.light_len = vec_length(light_point.light_dir);
	light_point.light_ray = ray(vec_plus_vec(vars->rec.p, vec_mult_val \
						(vars->rec.normal, 1e-6)), light_point.light_dir);
	return (light_point);
}

t_light_point	get_reflection(t_vars *vars, t_light *light, t_light_point src)
{
	double	ksn;
	double	ks;

	src.diffuse = vec_mult_val(light->light_color, \
			fmax(vec_dot(vars->rec.normal, src.light_dir), 0.0));
	src.view_dir = vec_unit(vec_mult_val(vars->ray.dir, -1));
	src.reflect_dir = reflect \
						(vec_mult_val(src.light_dir, -1), vars->rec.normal);
	ksn = 60;
	ks = 0.5;
	src.spec = pow(fmax(vec_dot(src.view_dir, src.reflect_dir), 0.0), ksn);
	src.specular = vec_mult_val(vec_mult_val(light->light_color, ks), src.spec);
	return (src);
}

t_color	get_point_light(t_vars *vars, t_light *light)
{
	t_light_point	light_point;
	double			brightness;

	light_point = get_light_parameter(vars, light);
	if (in_shadow(vars->world, light_point.light_ray, light_point.light_len))
		return (init_color(0, 0, 0));
	light_point.light_dir = vec_unit(light_point.light_dir);
	light_point = get_reflection(vars, light, light_point);
	brightness = light->bright_ratio * 3;
	return (vec_mult_val(vec_plus_vec(vec_plus_vec \
	(vars->ambient, light_point.diffuse), light_point.specular), brightness));
}

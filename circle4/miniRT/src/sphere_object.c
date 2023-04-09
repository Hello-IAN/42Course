/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:33:22 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 20:40:54 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"
#include "../includes/vars.h"
#include "../includes/trace.h"
#include "../includes/object.h"
#include "../includes/vec.h"
#include <math.h>

static t_sp_disc	get_sp_discriminant(t_sphere *sp, t_ray *ray, t_vec oc)
{
	t_sp_disc	disc;

	disc.a = vec_length2(ray->dir);
	disc.half_b = vec_dot(oc, ray->dir);
	disc.c = vec_length2(oc) - sp->radius2;
	disc.discriminant = disc.half_b * disc.half_b - disc.a * disc.c;
	return (disc);
}

int	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec		oc;
	t_sp_disc	disc;
	double		root;
	t_sphere	*sphere;

	sphere = world->element;
	oc = vec_minus_vec(ray->origin, sphere->center);
	disc = get_sp_discriminant(sphere, ray, oc);
	if (disc.discriminant < 0)
		return (0);
	root = (-disc.half_b - sqrt(disc.discriminant)) / disc.a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-disc.half_b + sqrt(disc.discriminant)) / disc.a;
		if (root < rec->tmin || rec->tmax < root)
			return (0);
	}
	rec->t = root;
	rec->tmax = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec_divide_val \
				(vec_minus_vec(rec->p, sphere->center), sphere->radius);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (1);
}

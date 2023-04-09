/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:13:12 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:57 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vec.h"
#include "../includes/ray.h"
#include "../includes/vars.h"
#include "../includes/trace.h"
#include "../includes/object.h"
#include <math.h>

t_vec	get_cylinder_normal(t_cylinder *cy, t_vec at)
{
	t_vec	hit_height;

	hit_height = vec_mult_val(cy->dir, vec_dot \
			(vec_minus_vec(at, cy->point), cy->dir));
	return (vec_divide_val(vec_minus_vec \
			(at, vec_plus_vec(cy->point, hit_height)), cy->radius));
}

double	cy_boundary(t_cylinder *cy, t_vec at)
{
	double	hit_height;

	hit_height = vec_dot(vec_minus_vec(cy->point, at), cy->dir);
	if (fabs(hit_height) > cy->height / 2)
		return (0);
	return (1);
}

t_cy_disc	get_cylinder_discriminant(t_cylinder *cy, t_ray *ray)
{
	t_cy_disc	disc;
	t_vec		oc;

	oc = vec_minus_vec(ray->origin, cy->point);
	disc.a = vec_length2(vec_cross(ray->dir, cy->dir));
	disc.half_b = vec_dot(vec_cross(ray->dir, cy->dir), vec_cross(oc, cy->dir));
	disc.c = vec_length2(vec_cross(oc, cy->dir)) - pow(cy->radius / 2, 2);
	disc.discriminant = disc.half_b * disc.half_b - disc.a * disc.c;
	return (disc);
}

int	hit_cylinder_cap(t_object *world, t_ray *ray, t_hit_record *rec, double dir)
{
	t_point3	f;
	t_point3	p;
	double		numerator;
	double		t;
	t_cylinder	*cy;

	cy = world->element;
	if (fabs(vec_dot(ray->dir, cy->point)) < 1e-6)
		return (0);
	f = vec_plus_vec(cy->point, vec_mult_val(cy->dir, cy->height * dir / 2));
	numerator = vec_dot(vec_minus_vec(f, ray->origin), \
					vec_mult_val(cy->dir, dir));
	t = numerator / vec_dot(ray->dir, vec_mult_val(cy->dir, dir));
	if (t < rec->tmin || t >= rec->tmax)
		return (0);
	p = vec_plus_vec(ray->origin, vec_mult_val(ray->dir, t));
	if (vec_length(vec_minus_vec(f, p)) > cy->radius / 2)
		return (0);
	rec->t = t;
	rec->p = p;
	rec->tmax = t;
	rec->normal = vec_mult_val(cy->dir, dir);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (1);
}

int	hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	double		root;
	t_cy_disc	disc;
	t_cylinder	*cy;

	cy = world->element;
	disc = get_cylinder_discriminant(cy, ray);
	if (disc.discriminant < 0)
		return (0);
	root = (-disc.half_b - sqrt(disc.discriminant)) / disc.a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-disc.half_b + sqrt(disc.discriminant)) / disc.a;
		if (root < rec->tmin || rec->tmax < root)
			return (0);
	}
	if (!(cy_boundary(cy, ray_at(ray, root))))
		return (0);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->tmax = root;
	rec->normal = get_cylinder_normal(cy, rec->p);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (1);
}

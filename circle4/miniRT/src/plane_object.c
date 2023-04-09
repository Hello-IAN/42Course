/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:08:46 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 20:41:33 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/object.h"
#include "../includes/trace.h"
#include "../includes/ray.h"
#include "../includes/vars.h"
#include "../includes/vec.h"
#include <math.h>

t_pl_disc	get_pl_discriminant(t_plane *pl, t_ray *ray)
{
	t_pl_disc	pl_disc;

	pl_disc.denominator = vec_dot(ray->dir, pl->dir);
	pl_disc.numrator = vec_dot(vec_minus_vec(pl->point, ray->origin), pl->dir);
	pl_disc.root = pl_disc.numrator / pl_disc.denominator;
	return (pl_disc);
}

int	hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_plane		*pl;
	t_pl_disc	pl_disc;

	pl = world->element;
	pl_disc = get_pl_discriminant(pl, ray);
	if (fabs(pl_disc.denominator) < 1e-6)
		return (0);
	if (pl_disc.root < rec->tmin || rec->tmax < pl_disc.root)
		return (0);
	rec->t = pl_disc.root;
	rec->p = ray_at(ray, pl_disc.root);
	rec->normal = pl->dir;
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (1);
}

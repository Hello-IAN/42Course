/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:23:31 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/02 09:58:25 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vars.h"
#include "../includes/object.h"
#include "../includes/vec.h"

int	hit_cylinder_mass(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int	result;

	result = 0;
	result += hit_cylinder_cap(world, ray, rec, 1);
	result += hit_cylinder_cap(world, ray, rec, -1);
	result += hit_cylinder(world, ray, rec);
	return (result);
}

int	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = 0;
	if (world->type == SPHERE)
		hit_result = hit_sphere(world, ray, rec);
	else if (world->type == PLANE)
		hit_result = hit_plane(world, ray, rec);
	else if (world->type == CYLINDER)
	{
		hit_result = hit_cylinder_mass(world, ray, rec);
	}
	return (hit_result);
}

int	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int				hit_anything;
	t_hit_record	*temp_rec;

	temp_rec = rec;
	hit_anything = 0;
	while (world)
	{
		if (hit_obj(world, ray, temp_rec))
		{
			hit_anything = 1;
			temp_rec->tmax = temp_rec->t;
			rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

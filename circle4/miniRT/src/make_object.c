/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:09:28 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/31 12:33:01 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vars.h"
#include "../includes/ray.h"
#include "../includes/object.h"
#include "../includes/trace.h"
#include "../includes/vec.h"
#include <stdlib.h>

t_sphere	*make_sphere(t_point3 center, double diamater)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	if (!sp)
		return (0);
	sp->center = center;
	sp->radius = diamater / 2;
	sp->radius2 = sp->radius * sp->radius;
	return (sp);
}

t_plane	*make_plane(t_point3 point, t_point3 dir)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	if (!pl)
		return (0);
	pl->point = point;
	pl->dir = dir;
	return (pl);
}

t_cylinder	*make_cylinder(t_point3 point, t_point3 dir, double d, double h)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	if (!cy)
		return (0);
	cy->point = point;
	cy->dir = dir;
	cy->radius = d / 2;
	cy->radius2 = cy->radius * cy->radius;
	cy->height = h;
	return (cy);
}

t_light	*make_light_point(t_point3 light_org, t_color light_color, double ratio)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (0);
	light->origin = light_org;
	light->light_color = light_color;
	light->bright_ratio = ratio;
	return (light);
}

t_object	*make_object(int type, void *element, t_color albedo)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (0);
	new->type = type;
	new->element = element;
	new->next = 0;
	new->albedo = albedo;
	return (new);
}

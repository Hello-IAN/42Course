/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:48:33 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 18:51:35 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vars.h"
#include "../includes/ray.h"
#include "../includes/object.h"
#include "../includes/trace.h"
#include "../includes/vec.h"
#include <math.h>
#include <stdlib.h>

t_color	phong_lighting(t_vars *vars)
{
	t_color		light_color;
	t_object	*lights;

	light_color = init_color(0, 0, 0);
	lights = vars->lights;
	while (lights)
	{
		if (lights->type == LIGHT)
			light_color = vec_plus_vec(light_color, \
					get_point_light(vars, lights->element));
		lights = lights->next;
	}
	light_color = vec_plus_vec(light_color, vars->ambient);
	return (vec_min(vec_mult_vec(light_color, vars->rec.albedo), \
			init_color(1, 1, 1)));
}

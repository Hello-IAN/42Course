/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_vector_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:02:49 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/02 09:34:33 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vec.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double	vec_length2(t_vec vec)
{
	return (pow_int(vec.x, 2) + pow_int(vec.y, 2) + pow_int(vec.z, 2));
}

double	vec_length(t_vec vec)
{
	return (sqrt(vec_length2(vec)));
}

t_vec	vec_cross(t_vec vec, t_vec vec2)
{
	t_vec	cross_vec;

	cross_vec.x = vec.y * vec2.z - vec.z * vec2.y;
	cross_vec.y = vec.z * vec2.x - vec.x * vec2.z;
	cross_vec.z = vec.x * vec2.y - vec.y * vec2.x;
	return (cross_vec);
}

t_vec	vec_unit(t_vec vec)
{
	double	len;

	len = vec_length(vec);
	if (len == 0)
	{
		printf("Error\n");
		exit(0);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

double	vec_dot(t_vec vec, t_vec vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

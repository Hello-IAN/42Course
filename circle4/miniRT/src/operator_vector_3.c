/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_vector_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:12:33 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 10:21:05 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vec.h"

t_vec	vec_mult_vec(t_vec vec, t_vec vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;
	return (vec);
}

t_vec	vec_mult_val(t_vec vec, double val)
{
	vec.x *= val;
	vec.y *= val;
	vec.z *= val;
	return (vec);
}

t_vec	vec_divide_val(t_vec vec, double val)
{
	vec.x /= val;
	vec.y /= val;
	vec.z /= val;
	return (vec);
}

t_vec	vec_min(t_vec vec, t_vec vec2)
{
	if (vec.x > vec2.x)
		vec.x = vec2.x;
	if (vec.y > vec2.y)
		vec.y = vec2.y;
	if (vec.z > vec2.z)
		vec.z = vec2.z;
	return (vec);
}

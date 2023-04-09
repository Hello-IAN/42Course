/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:32:05 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 10:00:35 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/trace.h"
#include "../includes/vec.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	if (vec_dot(ray->dir, rec->normal) > 0.0)
	{
		rec->normal = vec_mult_val(rec->normal, -1);
		rec->front_face = 0;
	}
	else
		rec->front_face = 1;
}

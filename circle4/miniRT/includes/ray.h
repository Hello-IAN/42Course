/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:49:53 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/10 07:29:22 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vars.h"

t_ray		ray(t_point3 origin, t_vec dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_vars *vars, double u, double v);
t_color		phong_lighting(t_vars *vars);
t_color		get_point_light(t_vars *vars, t_light *light);
t_color		ray_color(t_vars *vars, int depth);

#endif

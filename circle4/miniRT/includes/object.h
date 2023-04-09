/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:48:13 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/31 15:39:56 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vars.h"

t_sphere		*make_sphere(t_point3 center, double radius);
t_plane			*make_plane(t_point3 point, t_point3 dir);
t_cylinder		*make_cylinder(t_point3 point, t_point3 dir, \
											double r, double h);
t_object		*make_object(int type, void *element, t_color albedo);
t_light			*make_light_point(t_point3 light_org, t_color light_color, \
															double ratio);
t_hit_record	init_record(void);
void			object_add(t_object **list, t_object *new_object);
t_object		*object_last(t_object *list);
int				in_shadow(t_object *objs, t_ray light_ray, double light_len);
int				hit(t_object *world, t_ray *ray, t_hit_record *rec);
int				hit_obj(t_object *world, t_ray *ray, t_hit_record *rec);
int				hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
int				hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec);
int				hit_cylinder_cap(t_object *world, t_ray *ray, \
									t_hit_record *rec, double dir);
int				hit_cylinder_mass(t_object *world, t_ray *ray, \
									t_hit_record *rec);
int				hit_plane(t_object *world, t_ray *ray, t_hit_record *rec);

#endif

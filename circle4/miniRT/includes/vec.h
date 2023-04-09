/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:01:56 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/16 22:16:23 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

typedef struct s_vec {
	double	x;
	double	y;
	double	z;
} t_vec, t_color,	t_point3;

/* vector util */

double		pow_int(double base, int exp);

/* init utils */

t_vec		init_vec(double x, double y, double z);
t_color		init_color(double r, double g, double b);
t_point3	init_point(double x, double y, double z);
void		vec_set(t_vec *vec, double x, double y, double z);

/* vector operator */

double		vec_length2(t_vec vec);
double		vec_length(t_vec vec);
t_vec		vec_plus_vec(t_vec vec, t_vec vec2);
t_vec		vec_plus_val(t_vec vec, double x, double y, double z);
t_vec		vec_minus_vec(t_vec vec, t_vec vec2);
t_vec		vec_minus_val(t_vec vec, double x, double y, double z);
t_vec		vec_mult_vec(t_vec vec, t_vec vec2);
t_vec		vec_mult_val(t_vec vec, double val);
t_vec		vec_divide_val(t_vec vec, double val);

/* inner & outer product */

double		vec_dot(t_vec vec, t_vec vec2);
t_vec		vec_cross(t_vec vec, t_vec vec2);
t_vec		vec_unit(t_vec vec);
t_vec		vec_min(t_vec vec, t_vec vec2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:00:16 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/23 16:30:08 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include "vec.h"

# define SPHERE		1
# define PLANE		2
# define CYLINDER	3
# define LIGHT		5

typedef struct s_img_data
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_ray
{
	t_point3	origin;
	t_vec		dir;
}	t_ray;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec		normal;
	double		tmin;
	double		tmax;
	double		t;
	int			front_face;
	t_color		albedo;
}	t_hit_record;

typedef struct s_sphere
{
	t_vec	center;
	double	radius;
	double	radius2;
}	t_sphere;

typedef struct s_plane
{
	t_vec		point;
	t_point3	dir;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	point;
	t_vec	dir;
	double	radius;
	double	radius2;
	double	height;
}	t_cylinder;

typedef struct s_object
{
	int		type;
	void	*element;
	void	*next;
	t_color	albedo;
}	t_object;

typedef struct s_sphere_discriminant
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
}	t_sp_disc;

typedef struct s_plane_discriminant
{
	double	numrator;
	double	denominator;
	double	root;
}	t_pl_disc;

typedef struct s_cylinder_discriminant
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
}	t_cy_disc;

typedef struct s_light
{
	t_point3	origin;
	t_color		light_color;
	double		bright_ratio;
	int			boolean;
}	t_light;

typedef struct s_light_point
{
	t_vec	light_dir;
	double	light_len;
	t_ray	light_ray;
	t_vec	view_dir;
	t_vec	reflect_dir;
	t_color	diffuse;
	t_color	specular;
	double	spec;
}	t_light_point;

typedef struct s_camera
{
	int				fov;
	double			aspect_ratio;
	t_point3		origin;
	t_point3		dir;
	double			viewport_height;
	double			viewport_width;
	double			focal_length;
	t_point3		left_bottom;
	t_vec			horizontal;
	t_vec			vertical;
}	t_camera;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_camera		*cam;
	t_point3		camera_origin;
	t_point3		camera_dir;
	t_point3		light_point;
	int				image_width;
	int				image_height;
	t_ray			ray;
	t_object		*world;
	t_object		*lights;
	t_hit_record	rec;
	t_color			ambient;
	t_img_data		*img;
}	t_vars;

#endif

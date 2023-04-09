/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:12:58 by yomin             #+#    #+#             */
/*   Updated: 2023/02/16 21:13:01 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "object.h"

typedef struct s_info {
	float	diam;
	float	height;
	float	ratio;
	float	xyz[3];
	float	vector[3];
	float	colors[3];
	int		temp;
}	t_info;

typedef struct s_options {
	char	**option[5];
	int		option_cnt;
}	t_options;

int			ft_convert_to_i(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			is_valid_range_ratio(t_info *info, const char **option);
int			is_valid_range_color(t_info *info, const char **options);
int			is_valid_range_fov(t_info *info, const char **option);

int			check_file_name(const char *argv);
int			vaild_check(char *argv);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			get_cooridinates_point(t_info *info, const char **options);
int			get_3d_vector(t_info *info, const char **options);

void		execute_err(int n);
void		parse(const char *filename, t_vars *vars);

void		set_ambient_light(const char *line, t_vars *vars);
void		set_cam(const char *line, t_vars *vars);
void		set_light(const char *line, t_vars *vars);
void		set_ambient_light(const char *line, t_vars *vars);
void		set_sphere(const char *line, t_vars *vars);
void		set_plane(const char *line, t_vars *vars);
void		set_cylinder(const char *line, t_vars *vars);
void		free_input_objects(t_info *info, t_options *options);
void		put_pixel_to_window(t_img_data *img, int x, int y, int color);

double		ft_atod(const char *str);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strrchr(const char *s, int c);
char		**ft_split(char const *s, char c);
t_options	*get_options(const char *str);

#endif

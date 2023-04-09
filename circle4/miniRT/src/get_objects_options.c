/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_options.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:31:25 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/22 12:33:34 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/* check a value in range 0.0 ~ 1.0 */
void	set_ambient_light(const char *line, t_vars *vars)
{
	t_options	*options;
	t_info		*info;

	options = get_options(line);
	if (!options || options->option_cnt != 2)
		execute_err(1);
	info = malloc(sizeof(t_info));
	if (!info)
		execute_err(2);
	ft_memset(info, 0, sizeof(t_info));
	if (!is_valid_range_ratio(info, (const char **)options->option[0]) || \
		!is_valid_range_color(info, (const char **)options->option[1]))
		execute_err(1);
	vars->ambient = vec_mult_val(init_color \
		(info->colors[0], info->colors[1], info->colors[2]), info->ratio);
	free(info);
	free_options(options);
}

void	set_cam(const char *line, t_vars *vars)
{
	t_options	*options;
	t_info		*info;

	options = get_options(line);
	if (!options || options->option_cnt != 3)
		execute_err(1);
	info = malloc(sizeof(t_info));
	if (!info)
		execute_err(2);
	ft_memset(info, 0, sizeof(t_info));
	if (!get_cooridinates_point(info, options->option[0]) || \
		!get_3d_vector(info, options->option[1]) || \
		!is_valid_range_fov(info, options->option[2]))
		execute_err(1);
}

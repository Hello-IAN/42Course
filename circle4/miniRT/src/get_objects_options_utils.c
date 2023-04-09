/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_options_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:18:07 by yomin             #+#    #+#             */
/*   Updated: 2023/02/16 21:18:08 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/* check a value in range 0.0 ~ 1.0 
and also it has only one value but if it has more vlaue,
return 0 */
int	is_valid_range_ratio(t_info *info, const char **option)
{
	int	i;

	i = 0;
	info->ratio = ft_atod(option[i]);
	if (info->ratio < 0.0 || info->ratio > 1.0)
		return (0);
	if (option[1])
		return (0);
	return (1);
}

/* check a value in range 0 ~ 255.
and if colorset hasn't enough value,
return 0.*/
int	is_valid_range_color(t_info *info, const char **options)
{
	int	i;

	i = 0;
	while (options[i])
	{
		info->colors[i] = ft_convert_to_i(options[i]);
		if (info->colors[i] < 0 || info->colors[i] > 255 || i > 3)
			return (0);
		info->colors[i] /= 255;
		++i;
	}
	if (i != 3)
		return (0);
	return (1);
}

/* check a fov value in range 0~180 
and also it has only one value but if it has more vlaue,
return 0 */
int	is_valid_range_fov(t_info *info, const char **option)
{
	info->temp = ft_convert_to_i(option[0]);
	if (info->temp < 0 || info->temp > 180)
		return (0);
	if (option[1])
		return (0);
	return (1);
}

/* get float value from options, if a few value, return 0 */
int	get_cooridinates_point(t_info *info, const char **options)
{
	int	i;

	i = 0;
	while (options[i])
	{
		info->xyz[i] = ft_atod(options[i]);
		++i;
	}
	if (i != 3)
		return (0);
	return (1);
}

/* get float value from options, if a value was not enough, return 0 
also if range over -1~1 return 0*/
int	get_3d_vector(t_info *info, const char **options)
{
	int	i;

	i = 0;
	while (options[i])
	{
		info->vector[i] = ft_atod(options[i]);
		if (info->vector[i] < -1 || info->vector[i] > 1)
			return (0);
		++i;
	}
	if (i != 3)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:57:27 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:28 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_convert_to_i(char *str)
{
	long	res;

	res = 0;
	if (*str < '0' && *str > '9')
		return (-1);
	while (*str && (*str >= '0' && *str <= '9'))
		res = (10 * res) + (*str++ - '0');
	if (*str != '\0')
		return (-1);
	else if (res > 2147483647)
		return (-1);
	return ((int)res);
}

t_info	*put_info_val(int argc, char *argv[])
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->max_cnt = ft_convert_to_i(argv[1]);
	info->time_to_die = ft_convert_to_i(argv[2]);
	info->time_to_eat = ft_convert_to_i(argv[3]);
	info->time_to_sleep = ft_convert_to_i(argv[4]);
	if (argc == 6)
		info->must_eat = ft_convert_to_i(argv[5]);
	else
		info->must_eat = -1;
	return (info);
}

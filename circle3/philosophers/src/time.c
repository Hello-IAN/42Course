/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:57:24 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:25 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	t_timeval	tmp;

	gettimeofday(&tmp, NULL);
	return ((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000));
}

long	get_timeflow(t_timeval begin)
{
	long		start_point;
	long		end_point;
	t_timeval	curr_point;

	start_point = (begin.tv_sec * 1000) + (begin.tv_usec / 1000);
	gettimeofday(&curr_point, NULL);
	end_point = (curr_point.tv_sec * 1000) + (curr_point.tv_usec / 1000);
	return (end_point - start_point);
}

void	pause_timeflow(long int ms, t_table *table)
{
	long	cur_point;
	long	end_point;

	cur_point = get_time();
	end_point = cur_point + ms;
	while (get_time() < end_point && is_finish(table) == E_TRUE)
		usleep(100);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:57:14 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:15 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	gen_dinner(t_table *table, t_info *info)
{
	int	i;

	i = -1;
	if (do_dining(table, info->max_cnt) != 0)
	{
		while (++i < info->max_cnt)
			pthread_detach(table[i].philos[i].t_id);
		free_all_set(info, NULL, table, info->max_cnt);
		return (-1);
	}
	while (chk_condition(table, table->philos, info, i) == E_FALSE)
		usleep(100);
	i = -1;
	while (++i < info->max_cnt)
		pthread_join(table[i].philos[i].t_id, NULL);
	free_all_set(info, table->philos, table, info->max_cnt);
	return (0);
}

int	gen_table(t_table *table, t_philo *philos, t_mutex *mutex, int max)
{
	int			id;
	t_bool		*endpoint;
	t_timeval	start;

	endpoint = malloc(sizeof(t_bool));
	if (!endpoint)
		return (-1);
	*endpoint = E_TRUE;
	id = -1;
	while (++id < max)
	{
		table[id].id = id;
		table[id].endpoint = endpoint;
		table[id].mutex = mutex;
		table[id].philos = philos;
	}
	if (gettimeofday(&start, NULL) != 0)
		return (-1);
	id = -1;
	while (++id < max)
		table[id].start = start;
	return (0);
}

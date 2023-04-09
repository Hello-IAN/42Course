/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:57:09 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:10 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_mutex(t_mutex *mutex, int max)
{
	int	i;

	i = -1;
	while (++i < max)
		pthread_mutex_destroy(&mutex->fork[i]);
	pthread_mutex_destroy(&mutex->eat);
	pthread_mutex_destroy(&mutex->finish);
	pthread_mutex_destroy(&mutex->printf);
	if (mutex->fork)
		free(mutex->fork);
	return (NULL);
}

void	*free_all_set(t_info *info, t_philo *philo, t_table *table, int max)
{
	int	max_cnt;

	max_cnt = max;
	if (table)
	{
		if (table->mutex)
		{
			free_mutex(table->mutex, max_cnt);
			free(table->mutex);
		}
		if (table->endpoint)
			free(table->endpoint);
		free(table);
	}
	if (info)
		free(info);
	if (philo)
		free(philo);
	return (NULL);
}

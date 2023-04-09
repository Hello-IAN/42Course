/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:57:04 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:07 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_finish(t_table *table)
{
	pthread_mutex_lock(&table->mutex->finish);
	if (*table->endpoint == E_TRUE)
	{
		pthread_mutex_unlock(&table->mutex->finish);
		return (E_TRUE);
	}
	pthread_mutex_unlock(&table->mutex->finish);
	return (E_FALSE);
}

t_bool	chk_condition(t_table *tab, t_philo *philos, t_info *info, int i)
{
	while (++i < info->max_cnt)
	{
		if (info->must_eat >= 0 && chk_eating_enough(tab, info) == E_TRUE)
		{
			pthread_mutex_lock(&tab->mutex->finish);
			*tab->endpoint = E_FALSE;
			pthread_mutex_unlock(&tab->mutex->finish);
			print_state(FULL, tab, philos, i);
			return (E_TRUE);
		}
		if (get_timeflow(philos[i].last_eat) > info->time_to_die)
		{
			pthread_mutex_lock(&tab->mutex->finish);
			*tab->endpoint = E_FALSE;
			pthread_mutex_unlock(&tab->mutex->finish);
			print_state(DIE, tab, philos, i);
			if (info->max_cnt == 1)
				pthread_mutex_unlock(\
				&(tab->mutex->fork[philos[i].right_fork - 1]));
			return (E_TRUE);
		}
	}
	return (E_FALSE);
}

t_bool	chk_eating_enough(t_table *table, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->max_cnt)
	{
		pthread_mutex_lock(&table->mutex->eat);
		if ((info->must_eat > table->philos[i].eat_cnt) || \
			(info->must_eat == -1))
		{
			pthread_mutex_unlock(&table->mutex->eat);
			return (E_FALSE);
		}
		pthread_mutex_unlock(&table->mutex->eat);
		i++;
	}
	return (E_TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:57:21 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:22 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_status status, t_table *table, t_philo *philos, int id)
{
	pthread_mutex_lock(&table->mutex->printf);
	if (status == DIE)
		printf("\e[3;31m%9ldms \e[3;91m%1d\e[m \e[3;31mdied\e[m\b\n", \
		get_timeflow(table->start), philos[id].id);
	else if (status == FULL)
		printf("\e[3;31m=====all of philosophers has eaten fully=====\n\e[m");
	if (status == FORK && is_finish(table) == E_TRUE)
		printf("\e[1;36m%9ldms \e[3;91m%1d\e[m \e[1;36mhas taken a fork\n\e[m"\
		, get_timeflow(table->start), philos[id].id);
	if (status == EATING && is_finish(table) == E_TRUE)
	{
		printf("\e[1;32m%9ldms \e[3;91m%1d\e[m \e[1;32mhas eating\n\e[m", \
		get_timeflow(table->start), philos[id].id);
		gettimeofday(&philos[id].last_eat, NULL);
	}
	if (status == SLEEPING && is_finish(table) == E_TRUE && \
		chk_eating_enough(table, table->philos[id].info) != E_TRUE)
		printf("\e[1;33m%9ldms \e[3;91m%1d\e[m \e[1;33mhas sleep\e[m\n", \
		get_timeflow(table->start), philos[id].id);
	if (status == THINKING && is_finish(table) == E_TRUE && \
		chk_eating_enough(table, table->philos[id].info) != E_TRUE)
		printf("\e[1;35m%9ldms \e[3;91m%1d\e[m \e[1;35mhas thinking\e[m\n", \
		get_timeflow(table->start), philos[id].id);
	pthread_mutex_unlock(&table->mutex->printf);
}

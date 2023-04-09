/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:56:59 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:02 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	action_fork(t_table *table, t_philo *philos, int id)
{
	pthread_mutex_lock(&(table->mutex->fork[philos[id].right_fork - 1]));
	print_state(FORK, table, philos, id);
	if (table->philos->info->max_cnt <= 1)
		return (-1);
	pthread_mutex_lock(&(table->mutex->fork[philos[id].left_fork - 1]));
	print_state(FORK, table, philos, id);
	return (0);
}

static void	action_eat(t_table *table, t_philo *philos, int id)
{
	print_state(EATING, table, philos, id);
	pthread_mutex_lock(&table->mutex->eat);
	philos[id].eat_cnt++;
	pthread_mutex_unlock(&table->mutex->eat);
	pause_timeflow(philos[id].info->time_to_eat, table);
	pthread_mutex_unlock(&(table->mutex->fork[philos[id].left_fork - 1]));
	pthread_mutex_unlock(&(table->mutex->fork[philos[id].right_fork - 1]));
	if (chk_eating_enough(table, philos[id].info) != E_TRUE)
		print_state(SLEEPING, table, philos, id);
	pause_timeflow(philos[id].info->time_to_sleep, table);
	if (chk_eating_enough(table, philos[id].info) != E_TRUE)
		print_state(THINKING, table, philos, id);
}

void	*action(void *arg)
{
	t_table	*table;
	t_philo	*philos;
	int		id;

	table = (t_table *)arg;
	id = table->id;
	philos = table->philos;
	while (is_finish(table) == E_TRUE)
		if (action_fork(table, philos, id) == 0)
			action_eat(table, philos, id);
	return (NULL);
}

int	do_dining(t_table *table, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (pthread_create(&table[i].philos[i].t_id, NULL, \
			&action, &table[i]) != 0)
			return (-1);
			i += 2;
	}
	usleep(5000);
	i = 1;
	while (i < max)
	{
		if (pthread_create(&table[i].philos[i].t_id, NULL, \
			&action, &table[i]) != 0)
			return (-1);
		i += 2;
	}
	return (0);
}

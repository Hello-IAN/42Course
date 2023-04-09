/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:57:17 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:18 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_info *info)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * info->max_cnt);
	if (!philos)
		return (NULL);
	while (++i < info->max_cnt)
	{
		philos[i].id = i + 1;
		philos[i].info = info;
		philos[i].eat_cnt = 0;
		if (i < 1)
			philos[i].left_fork = info->max_cnt;
		else
			philos[i].left_fork = i;
		philos[i].right_fork = i + 1;
		gettimeofday(&philos[i].last_eat, NULL);
	}
	return (philos);
}

static int	gen_mutex(t_mutex *mutex, int max_cnt)
{
	int	i;

	i = -1;
	while (++i < max_cnt)
		if (pthread_mutex_init(&(mutex->fork[i]), NULL) != 0)
			return (-1);
	if (pthread_mutex_init(&mutex->printf, NULL) != 0 || \
		pthread_mutex_init(&mutex->finish, NULL) != 0 || \
		pthread_mutex_init(&mutex->eat, NULL) != 0)
		return (-1);
	return (0);
}

static t_mutex	*init_mutex(t_info *info)
{
	t_mutex	*mutex;

	mutex = malloc(sizeof(t_mutex));
	if (!mutex)
		return (NULL);
	mutex->fork = malloc(sizeof(pthread_mutex_t) * info->max_cnt);
	if (!mutex->fork)
		return (NULL);
	if (gen_mutex(mutex, info->max_cnt) != 0)
		return (NULL);
	return (mutex);
}

static t_table	*set_table(t_info *info)
{
	t_philo	*philos;
	t_table	*table;
	t_mutex	*mutex;

	table = malloc(sizeof(t_table) * info->max_cnt);
	if (!table)
	{
		free(info);
		return (NULL);
	}
	mutex = init_mutex(info);
	if (!mutex)
		return (free_all_set(info, NULL, table, info->max_cnt));
	philos = init_philo(info);
	if (!philos)
		return (free_all_set(info, NULL, table, info->max_cnt));
	if (gen_table(table, philos, mutex, info->max_cnt) != 0)
		return (free_all_set(info, NULL, table, info->max_cnt));
	return (table);
}

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_table	*table;
	int		i;

	if (argc != 5 && argc != 6)
		return (write(2, "invalid input\n", 14));
	i = 0;
	while (++i < argc)
		if (ft_convert_to_i(argv[i]) <= 0)
			return (write(2, "invalid input\n", 14));
	info = put_info_val(argc, argv);
	if (!info)
		return (write(2, "allocation failed\n", 18));
	table = set_table(info);
	if (!table)
		return (write(2, "allocation failed\n", 18));
	if (gen_dinner(table, info) != 0)
		return (write(2, "Threads Create failed\n", 22));
	return (0);
}

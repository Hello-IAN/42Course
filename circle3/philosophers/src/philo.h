/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:57:46 by yomin             #+#    #+#             */
/*   Updated: 2022/11/23 16:57:52 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_bool {
	E_TRUE,
	E_FALSE,
}	t_bool;

typedef enum e_status {
	FORK,
	STARVING,
	EATING,
	SLEEPING,
	THINKING,
	DIE,
	FULL,
}	t_status;

typedef struct timeval	t_timeval;

typedef struct s_mutex {
	pthread_mutex_t	*fork;
	pthread_mutex_t	printf;
	pthread_mutex_t	finish;
	pthread_mutex_t	eat;
}	t_mutex;

typedef struct s_info {
	int	max_cnt;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_info;

typedef struct s_philo {
	int			eat_cnt;
	int			id;
	int			left_fork;
	int			right_fork;
	pthread_t	t_id;
	t_info		*info;
	t_status	*stat;
	t_timeval	last_eat;
}	t_philo;

typedef struct s_table
{
	int			id;
	t_bool		*endpoint;
	t_mutex		*mutex;
	t_philo		*philos;
	t_timeval	start;
}	t_table;

/* function define */

/* int */
int			ft_convert_to_i(char *str);
int			gen_dinner(t_table *table, t_info *info);
int			gen_table(t_table *table, t_philo *philos, t_mutex *mutex, int max);
int			do_dining(t_table *table, int max);

/* long */
long		get_timeflow(t_timeval begin);

/* long long */
long long	get_time(void);

/* void */
void		pause_timeflow(long int ms, t_table *table);
void		print_state(t_status status, t_table *table, t_philo *philos, \
							int id);
void		*free_mutex(t_mutex *mutex, int max);
void		*free_all_set(t_info *info, t_philo *philo, t_table *table, \
							int max);
void		*action(void *arg);

/* t_bool */
t_bool		is_finish(t_table *table);
t_bool		chk_condition(t_table *table, t_philo *philos, t_info *info, int i);
t_bool		chk_eating_enough(t_table *table, t_info *info);

/* t_info */
t_info		*put_info_val(int argc, char *argv[]);

#endif

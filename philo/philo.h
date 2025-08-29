/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:19:50 by mjameau           #+#    #+#             */
/*   Updated: 2024/11/23 15:30:05 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RST "\033[0m"

# define R "\033[1;31m"
# define G "\033[1;32m"
# define Y "\033[1;33m"
# define B "\033[1;34m"
# define M "\033[1;35m"
# define C "\033[1;36m"
# define W "\033[1;37m"
# define BLACK "\033[1;30m"

typedef struct s_philo	t_philo;

typedef enum e_status
{
	SLEEP,
	EAT,
	THINK,
	DEAD,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
}						t_status;

typedef enum e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_time;

typedef enum e_code
{
	INIT,
	CREATE,
	LOCK,
	UNLOCK,
	JOIN,
	DETACH,
	DESTROY,
}						t_code;

typedef pthread_mutex_t	t_mtx;

typedef struct s_forks
{
	t_mtx				fork;
	int					fork_id;
}						t_forks;

typedef struct s_data
{
	long				nb_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				limit_meals;
	long				start_time;
	long				active_threads;
	bool				end;
	bool				all_threads_ok;
	pthread_t			monitor;
	t_mtx				data_mutex;
	t_mtx				update_mutex;
	t_forks				*forks;
	t_philo				*philos;
}						t_data;

typedef struct s_philo
{
	int					philo_id;
	t_forks				*first_fork;
	t_forks				*second_fork;
	long				nb_meals;
	bool				finished;
	long				last_meal;
	pthread_t			thread_id;
	t_mtx				philo_mutex;
	t_data				*data;
}						t_philo;

// UTILS
void					error_exit(char *str);
void					*check_allocation(int bytes);
void					wait_all(t_data *data);
long					get_time(t_time time);
void					precise_usleep(long time, t_data *data);
void					increase_long(t_mtx *mutex, long *value);
bool					all_threads_working(t_mtx *mutex, long *threads,
							long philo_nb);
void					clean_table(t_data *data);
void					desync_philo(t_philo *philo);

// ROUTINE
void					think(t_philo *philo, bool flag);
void					*lunch_start(t_data *data);
void					*lunch_time(void *data);

// PARSING
void					parsing(t_data *data, char **argv);

// HANDLERS
void					handle_thread(pthread_t *thread, void *(*foo)(void *),
							void *data, t_code code);
void					handle_mutex(t_mtx *mutex, t_code code);

// INIT
void					data_init(t_data *data);

// GET SET GALEGETGET GETSET GALEGETEGET
void					set_bool(t_mtx *mutex, bool *dest, bool value);
bool					get_bool(t_mtx *mutex, bool *value);
void					set_long(t_mtx *mutex, long *dest, long value);
long					get_long(t_mtx *mutex, long *value);
bool					is_finished(t_data *data);

// UPDATE
void					update_status(t_status status, t_philo *philo);

// MONITOR
void					*monitor_lunch(void *dat);

#endif
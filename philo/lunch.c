/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:11:47 by mjameau           #+#    #+#             */
/*   Updated: 2024/12/02 14:52:40 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal, get_time(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->active_threads);
	update_status(TAKE_FIRST_FORK, philo);
	while (!is_finished(philo->data))
		usleep(200);
	return (NULL);
}

void	think(t_philo *philo, bool flag)
{
	long	teat;
	long	tsleep;
	long	tthink;

	if (!flag)
		update_status(THINK, philo);
	if (philo->data->nb_philo % 2 == 0)
		return ;
	teat = philo->data->time_to_eat;
	tsleep = philo->data->time_to_sleep;
	tthink = (teat * 2) - tsleep;
	if (tthink < 0)
		tthink = 0;
	precise_usleep(tthink * 0.3, philo->data);
}

static void	eat(t_philo *philo)
{
	handle_mutex(&philo->first_fork->fork, LOCK);
	update_status(TAKE_FIRST_FORK, philo);
	handle_mutex(&philo->second_fork->fork, LOCK);
	update_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal, get_time(MILLISECOND));
	philo->nb_meals++;
	update_status(EAT, philo);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->limit_meals > 0
		&& philo->nb_meals == philo->data->limit_meals)
		set_bool(&philo->philo_mutex, &philo->finished, true);
	handle_mutex(&philo->first_fork->fork, UNLOCK);
	handle_mutex(&philo->second_fork->fork, UNLOCK);
}

void	*lunch_time(void *datta)
{
	t_philo	*philo;

	philo = (t_philo *)datta;
	wait_all(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal, get_time(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->active_threads);
	desync_philo(philo);
	while (!is_finished(philo->data))
	{
		if (philo->finished)
			break ;
		eat(philo);
		update_status(SLEEP, philo);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		think(philo, false);
	}
	return (NULL);
}

/*
 * Creer un thread pour chaque nb de philosopher
 */
void	*lunch_start(t_data *data)
{
	int	i;

	i = -1;
	if (data->limit_meals == 0)
		return (NULL);
	else if (data->nb_philo == 1)
		handle_thread(&data->philos[0].thread_id, lone_philo, &data->philos[0],
			CREATE);
	else
	{
		while (++i < data->nb_philo)
			handle_thread(&data->philos[i].thread_id, lunch_time,
				&data->philos[i], CREATE);
	}
	handle_thread(&data->monitor, monitor_lunch, data, CREATE);
	data->start_time = get_time(MILLISECOND);
	set_bool(&data->data_mutex, &data->all_threads_ok, true);
	i = -1;
	while (++i < data->nb_philo)
	{
		handle_thread(&data->philos[i].thread_id, NULL, NULL, JOIN);
	}
	set_bool(&data->data_mutex, &data->end, true);
	handle_thread(&data->monitor, NULL, NULL, JOIN);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:20:50 by mjameau           #+#    #+#             */
/*   Updated: 2024/11/23 15:27:48 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	desync_philo(t_philo *philo)
{
	if (philo->data->nb_philo % 2 == 0)
	{
		if (philo->philo_id % 2 == 0)
			precise_usleep(3e4, philo->data);
	}
	else
	{
		if (philo->philo_id % 2 != 0)
			think(philo, true);
	}
}

void	increase_long(t_mtx *mutex, long *value)
{
	handle_mutex(mutex, LOCK);
	(*value)++;
	handle_mutex(mutex, UNLOCK);
}

bool	all_threads_working(t_mtx *mutex, long *threads, long philo_nb)
{
	bool	ret;

	ret = false;
	handle_mutex(mutex, LOCK);
	if (*threads == philo_nb)
		ret = true;
	handle_mutex(mutex, UNLOCK);
	return (ret);
}

void	clean_table(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < data->nb_philo)
	{
		philo = data->philos + i;
		handle_mutex(&philo->philo_mutex, DESTROY);
	}
	handle_mutex(&data->data_mutex, DESTROY);
	handle_mutex(&data->update_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
}

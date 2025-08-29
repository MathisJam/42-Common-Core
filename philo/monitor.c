/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:18:28 by mjameau           #+#    #+#             */
/*   Updated: 2024/12/02 15:08:52 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// On regarde d'abord si le philo a fini de manger, si oui alors on return
// Si il a pas fini de manger on va calculer le temps depuis son dernier
// repas, le temps actuel - le time ou il a manger la derniere fois
// ensuite on compare avec le time_to_die passe en argument,
// si le temps ecoule est superieur alors le philo est mort.
static bool	is_dead(t_philo *philo)
{
	long	passed_by;
	long	to_die;

	if (get_bool(&philo->philo_mutex, &philo->finished))
		return (false);
	passed_by = get_time(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal);
	to_die = philo->data->time_to_die / 1e3;
	if (passed_by > to_die)
		return (true);
	return (false);
}

// Ici c'est 'l'arbitre', il va faire le tour de la table
// tant que le repas n'est pas fini (que tout lesp hilos
// ont fini de manger), il va verifier chaque philo avec
// la fonction au dessus is_dead, et si cette fonction
// renvoie true alors il est mort et on update son status a DEAD
void	*monitor_lunch(void *dat)
{
	int		i;
	t_data	*data;

	data = (t_data *)dat;
	while (!all_threads_working(&data->data_mutex, &data->active_threads,
			data->nb_philo))
	{
		usleep(100);
	}
	while (!is_finished(data))
	{
		i = -1;
		while (++i < data->nb_philo && !is_finished(data))
		{
			if (is_dead(data->philos + i))
			{
				set_bool(&data->data_mutex, &data->end, true);
				update_status(DEAD, data->philos + i);
				break ;
			}
		}
		usleep(1000);
	}
	return (NULL);
}

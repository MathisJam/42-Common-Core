/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:13:25 by mjameau           #+#    #+#             */
/*   Updated: 2024/11/23 11:36:51 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// donne les fourchettes, si l'id du philo actuel est un nombre pair alors
// il commence par prendre la fourchette de droite, si impair la gauche.
static void	give_forks(t_philo *philo, t_forks *forks, int i)
{
	int	philo_nb;

	philo_nb = philo->data->nb_philo;
	philo->first_fork = &forks[(i + 1) % philo_nb];
	philo->second_fork = &forks[i];
	if (philo->philo_id % 2 == 0)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % philo_nb];
	}
}

// Init de ma liste de philo, on init aussi les mutex ici
static void	init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->nb_philo)
	{
		philo = data->philos + i;
		philo->philo_id = i + 1;
		philo->finished = false;
		philo->nb_meals = 0;
		handle_mutex(&philo->philo_mutex, INIT);
		philo->data = data;
		give_forks(philo, data->forks, i);
		i++;
	}
}

// Init de ma struct data, on init aussi les mutex ici
void	data_init(t_data *data)
{
	int	i;

	i = 0;
	data->end = false;
	data->all_threads_ok = false;
	data->active_threads = 0;
	data->philos = check_allocation(sizeof(t_philo) * data->nb_philo);
	data->forks = check_allocation(sizeof(t_forks) * data->nb_philo);
	handle_mutex(&data->update_mutex, INIT);
	handle_mutex(&data->data_mutex, INIT);
	while (i < data->nb_philo)
	{
		handle_mutex(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
		i++;
	}
	init_philo(data);
}

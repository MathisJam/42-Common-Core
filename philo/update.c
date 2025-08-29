/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:30:48 by mjameau           #+#    #+#             */
/*   Updated: 2024/11/23 15:27:02 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_status(t_status status, t_philo *philo)
{
	long	passed_by;

	passed_by = get_time(MILLISECOND) - philo->data->start_time;
	if (philo->finished)
		return ;
	handle_mutex(&philo->data->update_mutex, LOCK);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& !is_finished(philo->data))
		printf(C "%-6ld" RST B " %d has taken a fork\n", passed_by,
			philo->philo_id);
	if ((status == EAT) && !is_finished(philo->data))
		printf(C "%-6ld" RST G " %d is eating\n" RST, passed_by,
			philo->philo_id);
	if ((status == SLEEP) && !is_finished(philo->data))
		printf(C "%-6ld" RST W " %d is sleeping\n", passed_by, philo->philo_id);
	if (status == THINK && !is_finished(philo->data))
		printf(C "%-6ld" RST Y " %d is thinking\n", passed_by, philo->philo_id);
	if (status == DEAD)
		printf(R "%-6ld %d died\n" RST, passed_by, philo->philo_id);
	handle_mutex(&philo->data->update_mutex, UNLOCK);
}

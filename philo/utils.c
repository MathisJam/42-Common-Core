/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:33:24 by mjameau           #+#    #+#             */
/*   Updated: 2024/12/02 15:22:52 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(char *str)
{
	printf(R "%s\n" RST, str);
	exit(1);
}

void	*check_allocation(int bytes)
{
	void	*i;

	i = malloc(bytes);
	if (!i)
		error_exit("Malloc failed");
	return (i);
}

void	wait_all(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->all_threads_ok))
	{
		usleep(200);
	}
}

long	get_time(t_time time)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL))
		error_exit("gettimeofday failed");
	if (time == SECOND)
		return (time_value.tv_sec + (time_value.tv_usec / 1e6));
	else if (time == MILLISECOND)
		return ((time_value.tv_sec * 1e3) + (time_value.tv_usec / 1e3));
	else if (time == MICROSECOND)
		return ((time_value.tv_sec * 1e6) + time_value.tv_usec);
	else
		error_exit("Wrong input to get_time");
	return (4865);
}

void	precise_usleep(long time, t_data *data)
{
	long	start;
	long	passed_by;
	long	remaining;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < time)
	{
		if (is_finished(data))
			break ;
		passed_by = get_time(MICROSECOND) - start;
		remaining = time - passed_by;
		if (remaining > 1e3)
			usleep(remaining / 2);
		else
			while (get_time(MICROSECOND) - start < time)
				;
	}
}

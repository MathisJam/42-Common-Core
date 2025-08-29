/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:30:42 by mjameau           #+#    #+#             */
/*   Updated: 2024/11/07 15:17:56 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		parsing(&data, argv);
		data_init(&data);
		lunch_start(&data);
		clean_table(&data);
	}
	else
		error_exit("Wrong input\n" G "try ./philo 5 789 300 300 [4]" RST);
}

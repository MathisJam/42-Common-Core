/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:35:08 by mjameau           #+#    #+#             */
/*   Updated: 2024/11/23 11:34:58 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Fonctions pour gerer l'etat des mutex et des threads
// en gros on appelle la fonction avec le code souhaite (CREATE pour cree,
// DESTROY pour supprimer, LOCK pour verrouiller le mutex etc...)

static void	mutex_errors(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (code == LOCK || code == UNLOCK))
		error_exit("Mutex value is invalid");
	else if (status == EINVAL && code == INIT)
		error_exit("Mutex attribution failed");
	else if (status == EDEADLK)
		error_exit("Deadlock would occur");
	else if (status == EPERM)
		error_exit("Current thread has no lock on mutex");
	else if (status == ENOMEM)
		error_exit("Process cannot allocate enough memory");
	else if (status == EBUSY)
		error_exit("Mutex is locked");
}

void	handle_mutex(t_mtx *mutex, t_code code)
{
	if (code == LOCK)
		mutex_errors(pthread_mutex_lock(mutex), code);
	else if (code == UNLOCK)
		mutex_errors(pthread_mutex_unlock(mutex), code);
	else if (code == INIT)
		mutex_errors(pthread_mutex_init(mutex, NULL), code);
	else if (code == DESTROY)
		mutex_errors(pthread_mutex_destroy(mutex), code);
	else
	{
		printf("code options: LOCK, UNLOCK, INIT, DESTROY");
		return ;
	}
}

static void	thread_errors(int status, t_code code)
{
	if (status == 0)
		return ;
	else if (status == EAGAIN)
		error_exit("Can't create another thread");
	else if (status == EPERM)
		error_exit("Doesn't have permission");
	else if (status == EINVAL && code == CREATE)
		error_exit("Thread attribution is invalid");
	else if (status == EINVAL && (code == JOIN || code == DETACH))
		error_exit("Thread is not joinable");
	else if (status == ESRCH)
		error_exit("No thread could be found");
	else if (status == EDEADLK)
		error_exit("Deadlock detected");
}

void	handle_thread(pthread_t *thread, void *(*foo)(void *), void *data,
		t_code code)
{
	if (code == CREATE)
		thread_errors(pthread_create(thread, NULL, foo, data), code);
	else if (code == JOIN)
		thread_errors(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		thread_errors(pthread_detach(*thread), code);
	else
		error_exit("Wrong code for thread:" C "<CREATE> <JOIN> <DETACH>" RST);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:09:44 by mjameau           #+#    #+#             */
/*   Updated: 2024/08/15 15:52:49 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_len(int PID, char *msg)
{
	int	i;
	int	len;

	len = ft_strlen(msg);
	i = 31;
	while (i >= 0)
	{
		if ((len >> i) & 1)
			kill(PID, SIGUSR2);
		else
			kill(PID, SIGUSR1);
		usleep(300);
		i--;
	}
}

/*
* Envoie un signal en bits.
On parcourt chaque bits avec notre i--;
On decale le binaire de ascii de i positions, et on regarde si c'est
un 1.
Si oui on envoie SIGUSR2 (1) sinon, SIGUSR1 (0).
usleep() permet de s'assurer que les signaux ne sont pas envoyes trop
rapidement et donc qu'ils soient bien traites.
*/
static void	send_as_to_bits(int PID, char ascii)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((ascii >> i) & 1)
			kill(PID, SIGUSR2);
		else
			kill(PID, SIGUSR1);
		usleep(300);
		i--;
	}
}

/*
* Gere le nombre d'arguments.
On atoi le pid passe en argument.
On recupere la string de argv[2] et la stock dans msg.
Tant que le message n'est pas arriver sur le null byte, on  envoie
chaque caractere en bit.
*/
int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*msg;

	i = 0;
	if (argc != 3)
		ft_printf("./client PID <message> ");
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		send_len(pid, msg);
		while (msg[i])
		{
			send_as_to_bits(pid, msg[i]);
			usleep(100);
			i++;
		}
		send_as_to_bits(pid, '\0');
		usleep(500);
	}
}

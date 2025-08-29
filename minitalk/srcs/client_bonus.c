/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:38:27 by mjameau           #+#    #+#             */
/*   Updated: 2024/08/15 15:53:07 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

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
rapidement et donc qu'il soit bien traites.
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
* Ecris un message comme quoi le signal envoye a bien ete recu
par le server.
On utilise ensuite la fonction exit() pour quitter le programme et sortir
de notre boucle infinie.
*/
static void	handle_confirmation(int sig)
{
	ft_printf("Message received!\n", sig);
	exit(0);
}

/*
* Gere le nombre d'arguments.
On atoi le pid passe en argument.
On recupere la string de argv[2] et la stock dans msg.
On utilise signal pour recuperer le signal de bonne reception,
et on l'envoie dans handle_confirmation.
Tant que le message n'est pas arriver sur le null byte, on  envoie
chaque caractere en bit.
On fait une boucle infinie pour que le client puisse recevoir des signaux
a n'importe quel moment.
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
		signal(SIGUSR1, handle_confirmation);
		signal(SIGUSR2, handle_confirmation);
		while (msg[i])
		{
			send_as_to_bits(pid, msg[i]);
			usleep(100);
			i++;
		}
		send_as_to_bits(pid, '\0');
		while (1)
			pause();
	}
}

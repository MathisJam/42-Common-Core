/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:38:22 by mjameau           #+#    #+#             */
/*   Updated: 2024/08/15 16:01:09 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static int	convert_signal(int sig, int bits)
{
	if (sig == SIGUSR1)
		bits = (bits << 1) | 0;
	else if (sig == SIGUSR2)
		bits = (bits << 1) | 1;
	return (bits);
}

static char	*ft_malloc_len(int bits)
{
	char	*message;

	message = malloc((bits + 1) * sizeof(char));
	if (!message)
		return (NULL);
	return (message);
}

static void	process_message(char **msg, int *i, pid_t *client_pid)
{
	ft_printf("%s\n", *msg);
	kill(*client_pid, SIGUSR2);
	free(*msg);
	*msg = NULL;
	*i = 0;
	*client_pid = 0;
}

/*
* Gere les signaux recus et assemble les bits.
On decale les bits de 1 et ajoute un 0 ou un 1 en fonction du signal.
Une fois recu 8 bits alors on a un caractere, on ecrit et reinitialise.
Si bits == 0 alors on a recu le nul byte, on peut donc envoyer un message
de bonne recepetion au client.
*/
static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		bits = 0, bit_count = 0, i = 0;
	static pid_t	client_pid = 0;
	static char		*msg = NULL;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	bits = convert_signal(sig, bits);
	bit_count++;
	if (!msg && bit_count == 32)
	{
		msg = ft_malloc_len(bits);
		bits = 0;
	}
	else if (msg && (bit_count == 40 || bit_count == 8))
	{
		msg[i++] = (unsigned char)bits;
		if (bits == 0)
			process_message(&msg, &i, &client_pid);
		bits = 0;
		bit_count = 0;
	}
}

/*
* Gere le nombre d'arguments.
On recupere le pid et l'affiche.
La structure sigaction est une structure du include <signal.h> qu'on
va utiliser ici pour recuperer le pid du client dans handle_signal.
SIGUSR1 et SIGUSR2 seront rediriges dans handle_signal pour decrypter
le message et l'afficher car on a mit que le sa_sigaction de
la			structure = handle_signal.
On fait une boucle infinie pour que le server reste en activite et recoive
les signaux a n'importe quel moment.
La boucle se met en pause le temps de gerer un signal.
*/
int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	(void)**argv;
	i = 0;
	if (argc != 1)
		ft_printf("Error, try ./server");
	else
	{
		sa.sa_sigaction = handle_signal;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_SIGINFO;
		pid = getpid();
		ft_printf("The pid is : %d\n", pid);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
		{
			pause();
		}
	}
}

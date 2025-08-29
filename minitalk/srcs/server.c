/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:11 by mjameau           #+#    #+#             */
/*   Updated: 2024/08/15 15:26:49 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

/*
* Gere les signaux recus et assemble les bits.
On decale les bits de 1 et ajoute un 0 ou un 1 en fonction du signal.
Une fois recu 8 bits alors on a un caractere, on ecrit et reinitialise.
*/
static void	handle_signal(int sig)
{
	static int	bits = 0;
	static int	bit_count = 0;
	static char	*msg = NULL;
	static int	i = 0;

	bits = convert_signal(sig, bits);
	bit_count++;
	if (!msg && bit_count == 32)
	{
		msg = ft_malloc_len(bits);
		bits = 0;
	}
	if (msg && (bit_count == 40 || bit_count == 8))
	{
		msg[i++] = (unsigned char)bits;
		if (bits == 0)
		{
			ft_printf("%s\n", msg);
			free(msg);
			msg = NULL;
			i = 0;
		}
		bits = 0;
		bit_count = 0;
	}
}

/*
* Gere le nombre d'arguments.
On recupere le pid et l'affiche.
La fonction signal permet d'executer une fonction si on recoit le signal indique.
Ici SIGUSR1 et SIGUSR2 seront rediriges dans handle_signal pour decrypter
le message et l'afficher.
On fait une boucle infinie pour que le server reste en activite et recoive
les signaux a n'importe quel moment.
La boucle se met en pause le temps de gerer un signal.
*/
int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	(void)**argv;
	i = 0;
	if (argc != 1)
		ft_printf("Error, try ./server");
	else
	{
		pid = getpid();
		ft_printf("The pid is : %d\n", pid);
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		while (1)
		{
			pause();
		}
	}
}

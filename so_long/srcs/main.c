/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:34 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/21 16:35:04 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* Petite fonction pour check si le nom de la map est valide
et qu'elle comporte bien le .ber !
*/
int	check_name(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = len - 1;
	j = 3;
	if (i <= j)
		return (FAIL);
	while (big[i] == little[j])
	{
		if (little[j] == big[i] && j == 0)
			return (SUCCESS);
		j--;
		i--;
	}
	return (FAIL);
}

/*
* Fonction pour tout free et detruire si jamais
il y'a besoin (map trop grande etc...)
la fonction mlx_destroy_window free deja a l'interieur, mais pas la
destroy_display donc il faut free !
*/
int	free_all(t_data *data)
{
	int	i;

	i = -1;
	if (data == NULL)
		return (FAIL);
	if (data->sprite[0])
		while (++i <= 7)
			mlx_destroy_image(data->ptr, data->sprite[i]);
	if (data->window)
		mlx_destroy_window(data->ptr, data->window);
	if (data->ptr)
	{
		mlx_destroy_display(data->ptr);
		free(data->ptr);
	}
	if (data->map)
		free_tab(data->map);
	exit(SUCCESS);
}

/*
* Fonction qui gere les input du clavier, les keysym (XK_Escape etc...)
sont deja declares dans le header
On oublie pas d'appeler free_all pour tout free/detruire si le joueur
appuie sur echap.
On compte aussi le nombre de mouvement effectue.
*/
int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_all(data);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		move(data, 'L');
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		move(data, 'U');
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		move(data, 'D');
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		move(data, 'R');
	ft_printf("\rMovement count : %d\n", data->nb_move);
	return (SUCCESS);
}

/*
* Fonction qui sert a initialiser les variables de notre struct
et a appeler les fonctions 'utilitaires'
(recuperer les positions, faire la fenetre etc..)
*/
void	initialised(t_data *data, char *argv)
{
	int	i;

	i = -1;
	data->ptr = NULL;
	data->window = NULL;
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->nb_move = 0;
	data->ptr = mlx_init();
	while (++i <= 7)
		data->sprite[i] = NULL;
	if (data->ptr == NULL)
		return ;
	map_read(data, argv);
	if (data->x == 0 && data->y == 0)
		return ;
	data->window = mlx_new_window(data->ptr, data->x, data->y,
			"Bunny's field of carrots");
	if (data->window == NULL)
		return ;
	data->carrot = 0;
	set_position(data);
	data->img_size = 64;
	map_init_window(data);
}

/*
* Le main, on fait nos check du nombre d'arg et le nom de la map.
Ensuite on appelle notre fonction pour tout initialiser,
on ajoute une condition pour s'assurer la fenetre du jeu ne soit
pas trop grande et que le jeu reste jouable.
Ensuite on appelle les fonctions de la minilibx, hook et loop
pour gerer les events ;
2 c'est pour gerer les appuis sur le touches du clavier et
17 c'est pour gerer le fait de fermer le jeu en cliquant sur la croix
*/
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || check_name(argv[1], ".ber", ft_strlen(argv[1])) == 1)
	{
		ft_printf("Error, try : ./so_long [map].ber");
		exit(FAIL);
	}
	data.ptr = NULL;
	initialised(&data, argv[1]);
	if (data.ptr == NULL)
		return (1);
	if (!data.ptr || !data.window || !data.map || map_check(&data)
		|| data.x > 1920 || data.y > 1080)
	{
		if (data.x > 1920 || data.y > 1080)
			ft_printf("Error\nOh no... The map must be too long :( ");
		if (!data.map)
			ft_printf("Error\nOh no... The map must be or empty :( ");
		free_all(&data);
		return (1);
	}
	mlx_hook(data.window, 2, 0, handle_input, &data);
	mlx_hook(data.window, 17, 1, free_all, &data);
	mlx_loop(data.ptr);
	return (SUCCESS);
}

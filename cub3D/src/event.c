/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:06:03 by mjameau           #+#    #+#             */
/*   Updated: 2025/01/22 18:37:47 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	handle_mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (x < data->control->last_mouse_pos)
		turn_left(data, true);
	else if (x > data->control->last_mouse_pos)
		turn_right(data, true);
	data->control->last_mouse_pos = x;
	return (0);
}

int	handle_key_release(int key, t_data *data)
{
	if (key == XK_Left)
		data->control->look_left = 0;
	if (key == XK_Right)
		data->control->look_right = 0;
	if (key == XK_w || key == XK_W)
		data->control->move_fwd = 0;
	if (key == XK_s || key == XK_S)
		data->control->move_bwd = 0;
	if (key == XK_a || key == XK_A)
		data->control->move_left = 0;
	if (key == XK_d || key == XK_D)
		data->control->move_right = 0;
	return (0);
}

int	handle_key_press(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		printf("\rA la prochaine!");
		free_all(data, 0);
	}
	if (key == XK_Left)
		data->control->look_left = 1;
	if (key == XK_Right)
		data->control->look_right = 1;
	if (key == XK_w || key == XK_W)
		data->control->move_fwd = 1;
	if (key == XK_s || key == XK_S)
		data->control->move_bwd = 1;
	if (key == XK_a || key == XK_A)
		data->control->move_left = 1;
	if (key == XK_d || key == XK_D)
		data->control->move_right = 1;
	return (0);
}

void	event_executor(t_data *data)
{
	if (data->control->look_left)
		turn_left(data, false);
	if (data->control->look_right)
		turn_right(data, false);
	if (data->control->move_fwd)
		move_forward(data);
	if (data->control->move_bwd)
		move_backward(data);
	if (data->control->move_left)
		move_left(data);
	if (data->control->move_right)
		move_right(data);
}

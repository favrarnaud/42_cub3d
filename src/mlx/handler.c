/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:38:46 by afavre            #+#    #+#             */
/*   Updated: 2023/06/23 09:38:49 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

int	key_handler(int key, void *param)
{
	(void)param;
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	exit (0);
}

int move_key(int keycode, void *param) {
	t_data *data;
	float moveSpeed = 0.1f;

	data = param;

	if (keycode == KEY_LEFT)
	{
		data->ray.angle -= 3;
		if (data->ray.angle < 0)
			data->ray.angle += 360;
	}

	if (keycode == KEY_RIGHT)
	{
		data->ray.angle += 3;
		if (data->ray.angle >= 360)
			data->ray.angle -= 360;
	}

	float dx = moveSpeed * sin(degree_to_radians(data->ray.angle));
	float dy = moveSpeed * cos(degree_to_radians(data->ray.angle));

	if (keycode == KEY_A)
	{
		data->ray.player_pos.x -= dy;
		data->ray.player_pos.y += dx;
	}
	if (keycode == KEY_S)
	{
		data->ray.player_pos.x -= dx;
		data->ray.player_pos.y -= dy;
	}
	if (keycode == KEY_D)
	{
		data->ray.player_pos.x += dy;
		data->ray.player_pos.y -= dx;
	}
	if (keycode == KEY_W)
	{
		data->ray.player_pos.x += dx;
		data->ray.player_pos.y += dy;
	}
	update_img(data);
	return (0);
}

void	init_event(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, close_game, data);
	mlx_hook(data->mlx.win, 2, (1L<<0), move_key, data);
	mlx_key_hook(data->mlx.win, key_handler, NULL);
}

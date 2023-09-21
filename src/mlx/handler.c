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
	t_data *data;

	data = param;
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
	data = param;

	if (keycode == KEY_LEFT)
	{
		printf("ducon\n");
	}
	return (-2147483647);
}

void	init_event(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, close_game, data);
	mlx_hook(data->mlx.win, 2, (1L<<0), move_key, data);
	mlx_key_hook(data->mlx.win, key_handler, NULL);
}

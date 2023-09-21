/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:38:46 by afavre            #+#    #+#             */
/*   Updated: 2023/09/21 17:01:51 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	exit (0);
}

int	move_key(int keycode, void *param)
{
	t_data	*data;

	data = param;
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_LEFT)
		la_gauche(data);
	if (keycode == KEY_RIGHT)
		la_droite(data);
	if (keycode == KEY_W)
		devant(data);
	if (keycode == KEY_A)
		moonwalk_gauche(data);
	if (keycode == KEY_S)
		derriere(data);
	if (keycode == KEY_D)
		moonwalk_droit(data);
	update_img(data);
	return (0);
}

void	init_event(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, close_game, data);
	mlx_hook(data->mlx.win, 2, (1L << 0), move_key, data);
}

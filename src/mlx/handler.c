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

int	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	exit (0);
}

int move_key(int keycode, void *param) {
	t_data *data;
	double oldDirX;
	double old_planeX;

	data = param;
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_LEFT)
	{
		oldDirX = data->cam.dir_x;
		data->cam.dir_x = data->cam.dir_x * cos(data->cam.r_sp) - data->cam.dir_y * sin(data->cam.r_sp);
		data->cam.dir_y = oldDirX * sin(data->cam.r_sp) + data->cam.dir_y * cos(data->cam.r_sp);
		old_planeX = data->cam.plane_x;
		data->cam.plane_x = data->cam.plane_x * cos(data->cam.r_sp) - data->cam.plane_y * sin(data->cam.r_sp);
		data->cam.plane_y = old_planeX * sin(data->cam.r_sp) + data->cam.plane_y * cos(data->cam.r_sp);
	}
	if (keycode == KEY_RIGHT)
	{
		oldDirX = data->cam.dir_x;
		data->cam.dir_x = data->cam.dir_x * cos(-data->cam.r_sp) - data->cam.dir_y * sin(-data->cam.r_sp);
		data->cam.dir_y = oldDirX * sin(-data->cam.r_sp) + data->cam.dir_y * cos(-data->cam.r_sp);
		old_planeX = data->cam.plane_x;
		data->cam.plane_x = data->cam.plane_x * cos(-data->cam.r_sp) - data->cam.plane_y * sin(-data->cam.r_sp);
		data->cam.plane_y = old_planeX * sin(-data->cam.r_sp) + data->cam.plane_y * cos(-data->cam.r_sp);
	}
	if (keycode == KEY_W)
	{
		if(data->map.map[(int)(data->player.pos_x + data->cam.dir_x * data->cam.m_sp)][(int)(data->player.pos_y)] == 'F')
			data->player.pos_x += data->cam.dir_x * data->cam.m_sp;
		if(data->map.map[(int)(data->player.pos_x)][(int)(data->player.pos_y + data->cam.dir_y * data->cam.m_sp)] == 'F')
			data->player.pos_y += data->cam.dir_y * data->cam.m_sp;
	}
	if (keycode == KEY_A)
	{
		if(data->map.map[(int)(data->player.pos_x - data->cam.dir_y * data->cam.m_sp)][(int)(data->player.pos_y)] == 'F')
			data->player.pos_x -= data->cam.dir_y * data->cam.m_sp;
		if(data->map.map[(int)(data->player.pos_x)][(int)(data->player.pos_y + data->cam.dir_x * data->cam.m_sp)] == 'F')
			data->player.pos_y += data->cam.dir_x * data->cam.m_sp;
	}
	if (keycode == KEY_S)
	{
		if(data->map.map[(int)(data->player.pos_x - data->cam.dir_x * data->cam.m_sp)][(int)(data->player.pos_y)] == 'F')
			data->player.pos_x -= data->cam.dir_x * data->cam.m_sp;
		if(data->map.map[(int)(data->player.pos_x)][(int)(data->player.pos_y - data->cam.dir_y * data->cam.m_sp)] == 'F')
			data->player.pos_y -= data->cam.dir_y * data->cam.m_sp;
	}
	if (keycode == KEY_D)
	{
		if(data->map.map[(int)(data->player.pos_x + data->cam.dir_y * data->cam.m_sp)][(int)(data->player.pos_y)] == 'F')
			data->player.pos_x += data->cam.dir_y * data->cam.m_sp;
		if(data->map.map[(int)(data->player.pos_x)][(int)(data->player.pos_y - data->cam.dir_x * data->cam.m_sp)] == 'F')
			data->player.pos_y -= data->cam.dir_x * data->cam.m_sp;
	}
	update_img(data);
	return (0);
}

void	init_event(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, close_game, data);
	mlx_hook(data->mlx.win, 2, (1L<<0), move_key, data);
}

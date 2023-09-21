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
		oldDirX = data->cam.dirX;
		data->cam.dirX = data->cam.dirX * cos(data->cam.r_sp) - data->cam.dirY * sin(data->cam.r_sp);
		data->cam.dirY = oldDirX * sin(data->cam.r_sp) + data->cam.dirY * cos(data->cam.r_sp);
		old_planeX = data->cam.planeX;
		data->cam.planeX = data->cam.planeX * cos(data->cam.r_sp) - data->cam.planeY * sin(data->cam.r_sp);
		data->cam.planeY = old_planeX * sin(data->cam.r_sp) + data->cam.planeY * cos(data->cam.r_sp);
	}
	if (keycode == KEY_RIGHT)
	{
		oldDirX = data->cam.dirX;
		data->cam.dirX = data->cam.dirX * cos(-data->cam.r_sp) - data->cam.dirY * sin(-data->cam.r_sp);
		data->cam.dirY = oldDirX * sin(-data->cam.r_sp) + data->cam.dirY * cos(-data->cam.r_sp);
		old_planeX = data->cam.planeX;
		data->cam.planeX = data->cam.planeX * cos(-data->cam.r_sp) - data->cam.planeY * sin(-data->cam.r_sp);
		data->cam.planeY = old_planeX * sin(-data->cam.r_sp) + data->cam.planeY * cos(-data->cam.r_sp);
	}
	if (keycode == KEY_W)
	{
		if(data->map.map[(int)(data->player.posX + data->cam.dirX * data->cam.m_sp)][(int)(data->player.posY)] == 'F')
			data->player.posX += data->cam.dirX * data->cam.m_sp;
		if(data->map.map[(int)(data->player.posX)][(int)(data->player.posY + data->cam.dirY * data->cam.m_sp)] == 'F')
			data->player.posY += data->cam.dirY * data->cam.m_sp;
	}
	if (keycode == KEY_A)
	{
		if(data->map.map[(int)(data->player.posX - data->cam.dirY * data->cam.m_sp)][(int)(data->player.posY)] == 'F')
			data->player.posX -= data->cam.dirY * data->cam.m_sp;
		if(data->map.map[(int)(data->player.posX)][(int)(data->player.posY + data->cam.dirX * data->cam.m_sp)] == 'F')
			data->player.posY += data->cam.dirX * data->cam.m_sp;
	}
	if (keycode == KEY_S)
	{
		if(data->map.map[(int)(data->player.posX - data->cam.dirX * data->cam.m_sp)][(int)(data->player.posY)] == 'F')
			data->player.posX -= data->cam.dirX * data->cam.m_sp;
		if(data->map.map[(int)(data->player.posX)][(int)(data->player.posY - data->cam.dirY * data->cam.m_sp)] == 'F')
			data->player.posY -= data->cam.dirY * data->cam.m_sp;
	}
	if (keycode == KEY_D)
	{
		if(data->map.map[(int)(data->player.posX + data->cam.dirY * data->cam.m_sp)][(int)(data->player.posY)] == 'F')
			data->player.posX += data->cam.dirY * data->cam.m_sp;
		if(data->map.map[(int)(data->player.posX)][(int)(data->player.posY - data->cam.dirX * data->cam.m_sp)] == 'F')
			data->player.posY -= data->cam.dirX * data->cam.m_sp;
	}
	update_img(data);
	return (0);
}

void	init_event(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, close_game, data);
	mlx_hook(data->mlx.win, 2, (1L<<0), move_key, data);
}

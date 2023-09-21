/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:58:53 by afavre            #+#    #+#             */
/*   Updated: 2023/09/19 14:51:27 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void test(t_data *data)
{
	int x;
	int	h;
	int	w;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	t_point t;

	x = 0;
	h = data->mlx.screen_height;
	w = data->mlx.screen_width;

	while (x < w)
	{
		cameraX = 2 * x / (double)data->mlx.screen_width - 1;
		rayDirX = data->cam.dir_x + data->cam.plane_x * cameraX;
		rayDirY = data->cam.dir_y + data->cam.plane_y * cameraX;
		mapX = (int)data->player.pos_x;
		mapY = (int)data->player.pos_y;
		x++;

		if (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs(1 / rayDirX);
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1 / rayDirY);

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->player.pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->player.pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->player.pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->player.pos_y) * deltaDistY;
		}
		hit = 0;
		while (hit == 0) {
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->map.map[mapX][mapY] == '1')
			{
				hit = 1;
			}
		}
			if (side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);

		int lineheight = (int)(h / perpWallDist);
		t.x = -(lineheight) / 2 + h/2;
		if ( t.x < 0 )
			t.x = 0;
		t.y = lineheight / 2 + h/2;
		if (t.y >= h)
			t.y = h - 1;
		int color;
			color = 0x0000FF;
		if (side == 1)
			color = color /2;
		render_line(data, x, t, color);
	}
}
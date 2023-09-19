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
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
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

	x = 0;
	h = data->mlx.screen_height;
	w = data->mlx.screen_width;
	posX = 3.5;
	posY = 5.5;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 5;

	while (x < w)
	{
		cameraX = 2 * x / (double)data->mlx.screen_width - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		mapX = (int)posX;
		mapY = (int)posY;
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
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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
			printf("data ---> x = %d, y = %d -----> %c\n", mapX, mapY, data->map.map[mapX][mapY]);
			if (data->map.map[mapX][mapY] == '1' || data->map.map[mapX][mapY] == 'x')
			{
				hit = 1;
			}
		}
			if (side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);
			printf("dist de %d ---> %f\n", x, perpWallDist);

		int lineheight = (int)(h / perpWallDist);
		int drawstart = -(lineheight) / 2 + h/2;
		if ( drawstart < 0 )
			drawstart = 0;
		int drawend = lineheight / 2 + h/2;
		if (drawend >= h)
			drawend = h - 1;
		int color;
			color = 0x0000FF;
		if (side == 1)
			color = color /2;
		render_line(data, x, drawstart, drawend, color);
	}
}
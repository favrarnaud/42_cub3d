/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:58:53 by afavre            #+#    #+#             */
/*   Updated: 2023/09/13 16:58:55 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void test(t_data *data)
{
	int x;
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
	posX = 4;
	posY = 4;
	dirX = 1;
	dirY = 0;
	planeX = 0;
	planeY = 0;
	mapX = (int)posY;
	mapY = (int)posX;
	hit = 0;


	while (1)
	{
		while (x < 1920)
		{
			cameraX = 2 * x / (double)data->mlx.screen_width - 1;
			rayDirX = dirY + planeX * cameraX;
			rayDirY = dirX + planeY * cameraX;
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
			while (hit == 0) {
				//jump to next map square, either in x-direction, or in y-direction
				if (sideDistX < sideDistY) {
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				} else {
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (data->map.map[mapX][mapY] == '1')
				{
					hit = 1;
				}
				if (side == 0) perpWallDist = (sideDistX - deltaDistX);
				else perpWallDist = (sideDistY - deltaDistY);
			}
			printf("test %d --> %f\n", x, perpWallDist);
		}
		break;
	}
}
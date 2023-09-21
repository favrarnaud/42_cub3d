/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:36:03 by afavre            #+#    #+#             */
/*   Updated: 2023/09/21 17:36:05 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycast(t_data *data)
{
	t_raycast ray;

	ray = data->raycast;
	ray.x = 0;
	ray.h = data->mlx.screen_height;
	ray.w = data->mlx.screen_width;

	while (ray.x < ray.w)
	{
		ray.cameraX = 2 * ray.x / (double)data->mlx.screen_width - 1;
		ray.rayDirX = data->cam.dir_x + data->cam.plane_x * ray.cameraX;
		ray.rayDirY = data->cam.dir_y + data->cam.plane_y * ray.cameraX;
		ray.mapX = (int)data->player.pos_x;
		ray.mapY = (int)data->player.pos_y;
		ray.x++;
		phase1(data);
		if (ray.rayDirX == 0)
			ray.deltaDistX = 1e30;
		else
			ray.deltaDistX = fabs(1 / ray.rayDirX);
		if (ray.rayDirY == 0)
			ray.deltaDistY = 1e30;
		else
			ray.deltaDistY = fabs(1 / ray.rayDirY);
		printf("test --> %f, %f\n", ray.deltaDistX, ray.deltaDistY);
		if (ray.rayDirX < 0)
		{
			ray.stepX = -1;
			ray.sideDistX = (data->player.pos_x - ray.mapX) * ray.deltaDistX;
		}
		else
		{
			ray.stepX = 1;
			ray.sideDistX = (ray.mapX + 1.0 - data->player.pos_x) * ray.deltaDistX;
		}
		if (ray.rayDirY < 0)
		{
			ray.stepY = -1;
			ray.sideDistY = (data->player.pos_y - ray.mapY) * ray.deltaDistY;
		}
		else
		{
			ray.stepY = 1;
			ray.sideDistY = (ray.mapY + 1.0 - data->player.pos_y) * ray.deltaDistY;
		}
		ray.hit = 0;
		while (ray.hit == 0) {
			if (ray.sideDistX < ray.sideDistY) {
				ray.sideDistX += ray.deltaDistX;
				ray.mapX += ray.stepX;
				ray.side = 0;
			} else {
				ray.sideDistY += ray.deltaDistY;
				ray.mapY += ray.stepY;
				ray.side = 1;
			}
			if (data->map.map[ray.mapX][ray.mapY] == '1')
			{
				ray.hit = 1;
			}
		}
		if (ray.side == 0)
			ray.perpWallDist = (ray.sideDistX - ray.deltaDistX);
		else
			ray.perpWallDist = (ray.sideDistY - ray.deltaDistY);

		int lineheight = (int)(ray.h / ray.perpWallDist);
		ray.t.x = -(lineheight) / 2 + ray.h/2;
		if ( ray.t.x < 0 )
			ray.t.x = 0;
		ray.t.y = lineheight / 2 + ray.h/2;
		if (ray.t.y >= ray.h)
			ray.t.y = ray.h - 1;
		int color;
		color = 0x0000FF;
		if (ray.side == 1)
			color = color /2;
		render_line(data, ray.x, ray.t, color);
	}
}

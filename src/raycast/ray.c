/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:07:42 by afavre            #+#    #+#             */
/*   Updated: 2023/08/09 11:07:44 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	throw_ray(t_data *data, float angle, int iter)
{
	(void)iter;
	float rayDirX = cos(angle);
	float rayDirY = sin(angle);
	int mapX = (int)(data->ray.player_pos.x);
	int mapY = (int)(data->ray.player_pos.y);
	float deltaDistX = fabs(1 / rayDirX);
	float deltaDistY = fabs(1 / rayDirY);
	float sideDistX;
	float sideDistY;
	int stepX;
	int stepY;

	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (data->ray.player_pos.x - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - data->ray.player_pos.x) * deltaDistX;
	}

	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (data->ray.player_pos.y - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - data->ray.player_pos.y) * deltaDistY;
	}

	int hit = 0;
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			if (data->map.tab[mapX][mapY] == 1)
				hit = 1;
			render_line(data, iter, 10, 900, new_color(255, 0, 0, 0));
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			if (data->map.tab[mapX][mapY] == 1)
				hit = 1;
		}
	}
}

void ray_casting(t_data *data)
{
	float	expand;
	float	angle;
	float	angle_end;
	int		i;

	angle = data->ray.angle - data->ray.fov / 2;
	angle_end = data->ray.angle + data->ray.fov / 2;
	expand = data->ray.fov / data->mlx.screen_width;
	i = 0;
	while (angle <= angle_end)
	{
		throw_ray(data, angle, i);
		angle += expand;
		i++;
	}
}
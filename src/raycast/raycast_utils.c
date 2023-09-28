/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:43:06 by afavre            #+#    #+#             */
/*   Updated: 2023/09/22 14:54:51 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	phase1(t_data *data)
{
	if (data->raycast.rayDirX == 0)
		data->raycast.deltaDistX = 1e30;
	else
		data->raycast.deltaDistX = fabs(1 / data->raycast.rayDirX);
	if (data->raycast.rayDirY == 0)
		data->raycast.deltaDistY = 1e30;
	else
		data->raycast.deltaDistY = fabs(1 / data->raycast.rayDirY);
	if (data->raycast.rayDirX < 0)
	{
		data->raycast.stepX = -1;
		data->raycast.sideDistX = (data->player.pos_x - data->raycast.mapX) * \
		data->raycast.deltaDistX;
	}
	else
	{
		data->raycast.stepX = 1;
		data->raycast.sideDistX = (data->raycast.mapX + 1.0 - \
		data->player.pos_x) * data->raycast.deltaDistX;
	}
}

void	phase2(t_data *data)
{
	if (data->raycast.rayDirY < 0)
	{
		data->raycast.stepY = -1;
		data->raycast.sideDistY = (data->player.pos_y - data->raycast.mapY) * \
			data->raycast.deltaDistY;
	}
	else
	{
		data->raycast.stepY = 1;
		data->raycast.sideDistY = (data->raycast.mapY + 1.0 - \
			data->player.pos_y) * data->raycast.deltaDistY;
	}
	data->raycast.hit = 0;
}

void	phase3(t_data *data)
{
	while (data->raycast.hit == 0)
	{
		if (data->raycast.sideDistX < data->raycast.sideDistY)
		{
			data->raycast.sideDistX += data->raycast.deltaDistX;
			data->raycast.mapX += data->raycast.stepX;
			data->raycast.side = 0;
		}
		else
		{
			data->raycast.sideDistY += data->raycast.deltaDistY;
			data->raycast.mapY += data->raycast.stepY;
			data->raycast.side = 1;
		}
		if (data->map.map[data->raycast.mapX][data->raycast.mapY] == '1')
			data->raycast.hit = 1;
	}
}

void	phase4(t_data *data)
{
	int	lineheight;

	if (data->raycast.side == 0)
		data->raycast.perpWallDist = (data->raycast.sideDistX - \
			data->raycast.deltaDistX);
	else
		data->raycast.perpWallDist = (data->raycast.sideDistY - \
			data->raycast.deltaDistY);
	lineheight = (int)(data->raycast.h / data->raycast.perpWallDist);
	data->raycast.t.x = - (lineheight) / 2 + data->raycast.h / 2;
	if (data->raycast.t.x < 0)
		data->raycast.t.x = 0;
	data->raycast.t.y = lineheight / 2 + data->raycast.h / 2;
	if (data->raycast.t.y >= data->raycast.h)
		data->raycast.t.y = data->raycast.h - 1;
	//add_height(&data->block, lineheight);
}

t_wall_face	get_face(t_data *data)
{	
	if (data->raycast.side == 0)
	{
		if (data->raycast.rayDirX >= 0)
			data->raycast.wall = NORTH;
		else
			data->raycast.wall = SOUTH;
		
	}
	if (data->raycast.side == 1)
	{
		if (data->raycast.rayDirY >= 0)
			data->raycast.wall = WEST;
		else
			data->raycast.wall = EAST;
	}
	return (NONE);		
}



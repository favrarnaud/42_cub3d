/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:53:06 by afavre            #+#    #+#             */
/*   Updated: 2023/09/26 18:53:08 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	phase0(t_data *data)
{
	data->raycast.cameraX = 2 * data->raycast.x / \
			(double)data->mlx.screen_width - 1;
	data->raycast.rayDirX = data->cam.dir_x + data->cam.plane_x * \
			data->raycast.cameraX;
	data->raycast.rayDirY = data->cam.dir_y + data->cam.plane_y * \
			data->raycast.cameraX;
	data->raycast.mapX = (int)data->player.pos_x;
	data->raycast.mapY = (int)data->player.pos_y;
}

void	phasem1(t_data *data)
{
	data->raycast.x = 0;
	data->raycast.h = data->mlx.screen_height;
	data->raycast.w = data->mlx.screen_width;
	data->raycast.oldX = (int)data->player.pos_x;
	data->raycast.oldY = (int)data->player.pos_y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:36:03 by afavre            #+#    #+#             */
/*   Updated: 2023/09/22 16:52:45 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_data *data)
{
	int	color;

	data->raycast.x = 0;
	data->raycast.h = data->mlx.screen_height;
	data->raycast.w = data->mlx.screen_width;
	while (data->raycast.x < data->raycast.w)
	{
		data->raycast.cameraX = 2 * data->raycast.x / \
			(double)data->mlx.screen_width - 1;
		data->raycast.rayDirX = data->cam.dir_x + data->cam.plane_x * \
			data->raycast.cameraX;
		data->raycast.rayDirY = data->cam.dir_y + data->cam.plane_y * \
			data->raycast.cameraX;
		data->raycast.mapX = (int)data->player.pos_x;
		data->raycast.mapY = (int)data->player.pos_y;
		data->raycast.x++;
		phase1(data);
		phase2(data);
		phase3(data);
		phase4(data);
		get_face(data);
		init_tex(data);
		render_line(data, data->raycast.x, data->raycast.t, get_color(data));
	}
}

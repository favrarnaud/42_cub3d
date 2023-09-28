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

int	check_block(t_data *data)
{
	if (data->raycast.mapX == data->raycast.oldX && data->raycast.mapY == \
		data->raycast.oldY && data->block.face[data->raycast.x] == data->raycast.oldface)
	{
		data->raycast.oldX = data->raycast.mapX;
		data->raycast.oldY = data->raycast.mapY;
		data->raycast.oldface = data->block.face[data->raycast.x];
		return (1);
	}
	else
	{
		data->raycast.oldX = data->raycast.mapX;
		data->raycast.oldY = data->raycast.mapY;
		data->raycast.oldface = data->block.face[data->raycast.x];
		return (0);
	}
}

void	raycast(t_data *data)
{
	int temp_width;

	temp_width = 0;
	init_block(&data->block);
	phasem1(data);
	while (data->raycast.x < data->raycast.w)
	{
		phase0(data);
		phase1(data);
		phase2(data);
		phase3(data);
		phase4(data);
		get_face(data);
		render_line(data, data->raycast.x, data->raycast.t, \
		get_color(data));
		if (check_block(data) == 1)
			temp_width++;
		else if (data->raycast.x != 0)
		{
			render_line(data, data->raycast.x, data->raycast.t, new_color(255, 255, 255, 0));
			add_width(&data->block, temp_width);
			temp_width = 0;
		}
		if (data->raycast.x == 1919)
		{
			add_width(&data->block, temp_width);
		}
		data->raycast.x++;
	}
	draw_col(data);
}

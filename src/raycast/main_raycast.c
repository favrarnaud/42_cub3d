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
        double wallX;
        if (data->raycast.side == 0) wallX = data->player.pos_y + data->raycast.perpWallDist * data->raycast.rayDirY;
        else           wallX = data->player.pos_x + data->raycast.perpWallDist * data->raycast.rayDirX;
        wallX -= floor((wallX));
        int texX = (int)(wallX);
        if(data->raycast.side == 0 && data->raycast.rayDirX > 0) texX = TEXWIDTH - texX - 1;
        if(data->raycast.side == 1 && data->raycast.rayDirY < 0) texX = TEXWIDTH - texX - 1;
        double step = 1.0 * TEXHEIGHT / data->block.height[data->raycast.x];
        double texPos = ((data->raycast.t.x - WINDOWHEIGHT) / 2 + data->block.height[data->raycast.x] / 2) * step;
        for(int y = (int)data->raycast.t.x; y < data->raycast.t.y; y++)
        {
            int texY = (int)texPos & ((int)TEXHEIGHT - 1);
            texPos += step;
            int color = get_pixel_color(&data->texture.so_data, data->raycast.x, texY);
        if(data->raycast.side == 1) color = (color >> 1) & 8355711;
            add_pixel(data, data->raycast.x, y, color);
        }
        mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.mlx_img, 0, 0);
		data->raycast.x++;
	}
}

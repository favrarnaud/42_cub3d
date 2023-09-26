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
		data->raycast.oldY && data->raycast.wall == data->raycast.oldface)
	{
		data->raycast.oldX = data->raycast.mapX;
		data->raycast.oldY = data->raycast.mapY;
		data->raycast.oldface = data->raycast.wall;
		return (1);
	}
	else
	{
		data->raycast.oldX = data->raycast.mapX;
		data->raycast.oldY = data->raycast.mapY;
		data->raycast.oldface = data->raycast.wall;
		return (0);
	}
}

int	pixtur(t_data *data, double tx, double ty)
{
	char	*pixel;

	pixel = data->texture.no_tex.img + ((int)ty * data->img.line_len + \
		(int)tx * (data->img.bpp / 8));
	return (*(int *)pixel);
}

void	draw_col(t_data *data)
{

}

void	raycast(t_data *data)
{
	int nb_col;
	t_block	block;

	nb_col = 0;
	init_block(&block);
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
		{
			nb_col++;
		}
		else if (data->raycast.x != 0)
		{
			render_line(data, data->raycast.x, data->raycast.t, new_color(255, 255, 255, 0));
			block.width = nb_col;

			nb_col = 1;
		}
		data->raycast.x++;
	}
}

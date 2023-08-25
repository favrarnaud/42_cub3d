/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:29:28 by afavre            #+#    #+#             */
/*   Updated: 2023/06/23 09:29:30 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx.screen_width = 1920;
	data->mlx.screen_height = 1080;
	data->mlx.ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.ptr, data->mlx.screen_width, data->mlx.screen_height, "Cube3d");
	data->img.mlx_img = mlx_new_image(data->mlx.ptr, data->mlx.screen_width, data->mlx.screen_height);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	init_event(data);
}

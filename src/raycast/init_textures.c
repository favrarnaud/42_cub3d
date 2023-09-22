/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:03:25 by bberger           #+#    #+#             */
/*   Updated: 2023/09/22 17:06:50 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tex(t_data *data)
{
	if (data->texture.no_path != NULL)
		data->texture.no_tex.img = mlx_xpm_file_to_image(data->mlx.ptr, data->texture.no_path, &data->texture.no_tex.img_width, &data->texture.no_tex.img_height);
	if (data->texture.so_path != NULL)
		data->texture.so_tex.img = mlx_xpm_file_to_image(data->mlx.ptr, data->texture.so_path, &data->texture.so_tex.img_width, &data->texture.so_tex.img_height);
	if (data->texture.we_path != NULL)
		data->texture.we_tex.img = mlx_xpm_file_to_image(data->mlx.ptr, data->texture.we_path, &data->texture.we_tex.img_width, &data->texture.we_tex.img_height);
	if (data->texture.ea_path != NULL)
		data->texture.ea_tex.img = mlx_xpm_file_to_image(data->mlx.ptr, data->texture.ea_path, &data->texture.ea_tex.img_width, &data->texture.ea_tex.img_height);
}
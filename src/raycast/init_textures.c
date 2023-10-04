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

void	load_no(t_data *data)
{
	data->texture.no_tex.img = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->texture.no_path, &data->texture.no_tex.img_width, \
	&data->texture.no_tex.img_height);

	data->texture.no_data.addr = mlx_get_data_addr(\
	data->texture.no_tex.img, &data->texture.no_data.bpp, \
	&data->texture.no_data.line_len, &data->texture.no_data.endian);
}

void	load_so(t_data *data)
{
	data->texture.so_tex.img = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->texture.so_path, &data->texture.so_tex.img_width, \
	&data->texture.so_tex.img_height);

	data->texture.so_data.addr = mlx_get_data_addr(\
	data->texture.so_tex.img, &data->texture.so_data.bpp, \
	&data->texture.so_data.line_len, &data->texture.so_data.endian);
}

void	load_ea(t_data *data)
{
	data->texture.ea_tex.img = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->texture.ea_path, &data->texture.ea_tex.img_width, \
	&data->texture.ea_tex.img_height);

	data->texture.ea_data.addr = mlx_get_data_addr(\
	data->texture.ea_tex.img, &data->texture.ea_data.bpp, \
	&data->texture.ea_data.line_len, &data->texture.ea_data.endian);
}

void	load_we(t_data *data)
{
	data->texture.we_tex.img = mlx_xpm_file_to_image(data->mlx.ptr, \
	data->texture.we_path, &data->texture.we_tex.img_width, \
	&data->texture.we_tex.img_height);

	data->texture.we_data.addr = mlx_get_data_addr(\
	data->texture.we_tex.img, &data->texture.we_data.bpp, \
	&data->texture.we_data.line_len, &data->texture.we_data.endian);
}

void	init_tex(t_data *data)
{
	load_no(data);
	load_so(data);
	load_ea(data);
	load_we(data);
}

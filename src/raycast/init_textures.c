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

//t_texture_load	setup_load(void **img, char *path, t_img *i_d, t_t_img *t_d)
//{
//	t_texture_load	load_data;
//
//	load_data.img = img;
//	load_data.path = path;
//	load_data.img_data = i_d;
//	load_data.tex_data = t_d;
//	return (load_data);
//}
//
//void	load_texture(t_data *data, t_texture_load load)
//{
//	if (load.path != NULL)
//	{
//		*load.img = mlx_xpm_file_to_image(data->mlx.ptr, \
//		load.path, &load.tex_data->img_width, \
//		&load.tex_data->img_height);
//		if (*load.img == NULL)
//		{
//			printf("Error load an image\n");
//			exit(1);
//		}
//		load.img_data->addr = mlx_get_data_addr(*load.img, \
//		&load.img_data->bpp, &load.img_data->line_len, \
//		&load.img_data->endian);
//		if (load.img_data->addr == NULL)
//		{
//			printf("Error get data of an image\n");
//			exit(1);
//		}
//	}
//}
//
//void	init_tex(t_data *data)
//{
//	load_texture(data, setup_load(&data->texture.no_tex.img, \
//	data->texture.no_path, &data->texture.no_data, \
//	&data->texture.no_tex));
//	load_texture(data, setup_load(&data->texture.so_tex.img, \
//	data->texture.so_path, &data->texture.so_data, \
//	&data->texture.so_tex));
//	load_texture(data, setup_load(&data->texture.we_tex.img, \
//	data->texture.we_path, &data->texture.we_data, \
//	&data->texture.we_tex));
//	load_texture(data, setup_load(&data->texture.ea_tex.img, \
//	data->texture.ea_path, &data->texture.ea_data, \
//	&data->texture.ea_tex));
//}

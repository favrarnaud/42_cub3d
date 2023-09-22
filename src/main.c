/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:53:58 by afavre            #+#    #+#             */
/*   Updated: 2023/09/22 17:09:21 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	if (read_input(ac, av, &data) <= -1)
		exit(1);
	init_mlx(&data);
	draw_background(&data);
	raycast(&data);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.img.mlx_img, 0, 0);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.texture.no_tex.img, 5, 5);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.texture.so_tex.img, 74, 5);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.texture.we_tex.img, 143, 5);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.texture.ea_tex.img, 222, 5);
	mlx_loop(data.mlx.ptr);
	return (0);
}

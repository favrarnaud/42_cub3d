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
	(void)ac;
	(void)av;
	t_data	data;

	init_data(&data);
	if (read_input(ac, av, &data) <= -1)
		exit(1);
	init_mlx(&data);
	draw_background(&data);
	raycast(&data);
//	test(&data);
	mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.img.mlx_img, 0, 0);
	mlx_loop(data.mlx.ptr);
	free_all(&data);
	return (0);
}

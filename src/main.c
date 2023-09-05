/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:53:58 by afavre            #+#    #+#             */
/*   Updated: 2023/08/25 11:56:55 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 int	main(int ac, char **av)
 {
 	t_data	data;

	 init_data(&data);
	 if (read_input(ac, av, &data) == -1)
		 exit(1);
	 print_map(&data);
//	 init_mlx(&data);
//	 init_data(&data);
//	 draw_background(&data);
//	 ray_casting(&data);
//	 update_img(&data);
//	 mlx_loop(data.mlx.ptr);
//	 clear_map(&data);
	 return (0);
 }

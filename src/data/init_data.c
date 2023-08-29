/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:12:27 by afavre            #+#    #+#             */
/*   Updated: 2023/08/29 16:34:42 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO remove manual map generation and fixed player position after parsing completion.

// N (270º), S (90º), W (180º), E (0º)

void	init_ray(t_data *data)
{
	data->ray.angle = 0;
	data->ray.fov = 60;
	data->ray.player_pos = create_point(5, 5);
	data->ray.half_height = data->mlx.screen_height / 2;
}

int	init_data(t_data *data)
{
	data->map.map_size = 10;
	gen_map(data);
	init_ray(data);
	return (0);
}

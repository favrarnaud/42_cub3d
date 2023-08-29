/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:12:27 by afavre            #+#    #+#             */
/*   Updated: 2023/07/04 13:12:29 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO remove manual map generation and fixed player position after parsing completion.

// N (270º), S (90º), W (180º), E (0º)

void	init_ray(t_data *data)
{
	data->ray.angle = 0;
	data->ray.limit = 50;
	data->ray.precision = 100;
	data->ray.fov = 60;
	data->ray.x = 5;
	data->ray.y = 1;
	data->ray.half_height = data->mlx.screen_height / 2;
}

int	init_data(t_data *data)
{
	data->map.map_size = 10;
	gen_map(data);
	init_ray(data);
	return (0);
}

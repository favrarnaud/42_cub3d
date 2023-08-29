/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:07:42 by afavre            #+#    #+#             */
/*   Updated: 2023/08/09 11:07:44 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_wall(t_data *data, t_vec ray_vec)
{
	if (data->map.tab[(int)ray_vec.x][(int)ray_vec.y] == 1)
		return (0);
	return(1);
}

int check_stop(t_data *data, t_vec ray_vec)
{
	if (check_wall(data, ray_vec) == 0 ||
		(ray_vec.x > data->ray.limit || ray_vec.x < 0) ||
		(ray_vec.y > data->ray.limit || ray_vec.y < 0))
		return (0);
	return (1);
}

void	throw_ray(t_data *data, float angle, int iter)
{
	t_vec	start_vec;
	t_vec	ray_vec;
	double	distance;
	double	wall_height;
	int 	color;

	start_vec.x = data->ray.x;
	start_vec.y = data->ray.y;
	ray_vec.x = data->ray.x;
	ray_vec.y = data->ray.y;
	float cosV = cos(degree_to_radians(angle)) / data->ray.precision;
	float sinV = sin(degree_to_radians(angle)) / data->ray.precision;

	while (check_stop(data, ray_vec))
	{
		ray_vec.x += sinV;
		ray_vec.y += cosV;
	}
	distance = sqrt(powf(ray_vec.x - data->ray.x - 0.5, 2.) + powf(ray_vec.y - data->ray.y - 0.5, 2.));
	distance *= cos(degree_to_radians(angle - data->ray.angle));
	wall_height = (data->mlx.screen_height / ( 0.5 * distance));
	color = set_color(define_face(substract_vec(ray_vec, start_vec)));
	render_line(data, iter, data->ray.half_height - (wall_height / 2), data->ray.half_height + (wall_height / 2), color);
}



void ray_casting(t_data *data)
{
	float	expand;
	float	angle;
	float	angle_end;
	int		i;

	angle = data->ray.angle - data->ray.fov / 2;
	angle_end = data->ray.angle + data->ray.fov / 2;
	expand = data->ray.fov / data->mlx.screen_width;
	i = 0;
	while (angle <= angle_end)
	{
		throw_ray(data, angle, i);
		angle += expand;
		i++;
	}
}
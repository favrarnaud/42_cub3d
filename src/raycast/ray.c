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

int check_wall(t_data *data, double x, double y)
{
	if (data->map.tab[(int)x][(int)y] == 1)
		return (0);
	return(1);
}

int check_stop(t_data *data, double x, double y)
{
	if (check_wall(data, x, y) == 0 ||
		(x > data->ray.limit || x < 0) ||
		(y > data->ray.limit || y < 0))
		return (0);
	return (1);
}

int 	set_color(int iter)
{
	if (iter % 10 == 0)
		return(new_color(255, 0, 0, 0));
	return(new_color(0, 0, 255, 0));
}

void	throw_ray(t_data *data, float angle, int iter)
{
	double	x;
	double	y;
	double	distance;
	double	wall_height;
	int 	color;

	x = data->ray.x;
	y = data->ray.y;
	float cosV = cos(degree_to_radians(angle)) / data->ray.precision;
	float sinV = sin(degree_to_radians(angle)) / data->ray.precision;

	while (check_stop(data, x, y))
	{
		x += sinV;
		y += cosV;
	}
	distance = sqrt(powf(x - data->ray.x - 0.5, 2.) + powf(y - data->ray.y - 0.5, 2.));
	distance *= cos(degree_to_radians(angle - data->ray.angle));
	wall_height = (data->mlx.screen_height / ( 0.5 * distance));
	color = set_color(iter);
	render_line(data, iter, data->ray.half_height - (wall_height / 2), data->ray.half_height + (wall_height / 2),color);
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
	while ((angle += expand) <= angle_end)
	{
		throw_ray(data, angle, i);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:07:42 by afavre            #+#    #+#             */
/*   Updated: 2023/08/29 16:35:36 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_col_info	throw_ray(t_data *data, float angle)
{
	return (get_ne_ray(data, angle));
}


void ray_casting(t_data *data)
{
	float	expand;
	float	angle;
	float	angle_end;
	t_col_info col;
	int		i;

	angle = data->ray.angle - data->ray.fov / 2;
	angle_end = data->ray.angle + data->ray.fov / 2;
	expand = data->ray.fov / data->mlx.screen_width;
	i = 0;
	while (angle <= angle_end)
	{
		col = throw_ray(data, angle);
		render_line(data, i,  50 * col.dist, 1080, new_color(102, 51, 0, 0));
		angle += expand;
		i++;
	}
}
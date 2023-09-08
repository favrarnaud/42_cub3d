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

t_col_info set_col_info(t_data *data, float angle)
{
	t_col_info col;

	col.start.x = data->ray.player_pos.x;
	col.start.y = data->ray.player_pos.y;
	printf("player pos %f, %f\n", col.start.x, col.start.y);

	col.hyp_y = (floor(col.start.x + 1) - col.start.x) / cos(degree_to_radians(angle));
	col.hyp_x = (col.start.y - floor(col.start.y)) / sin(degree_to_radians(angle));

	if (col.hyp_x < col.hyp_y)
	{
		col.new.x = col.start.x + ((col.start.y - floor(col.start.y)) / tan(degree_to_radians(angle)));
		col.new.y = floorf(col.start.y);
	}
	else if (col.hyp_x > col.hyp_y)
	{
		col.new.x = floorf(col.start.x + 1);
		col.new.y = col.start.y - ((floor(col.start.x + 1) - col.start.x) * tan(degree_to_radians(angle)));
	}
	printf("test ---> x : %f, y : %f", col.new.x, col.new.y);
	return (col);
}

t_col_info	throw_ray(t_data *data, float angle)
{
	return (get_ne_ray(data, angle));
}


void ray_casting(t_data *data)
{
	float	expand;
	float	angle;
	float	angle_end;
	t_col_info vachier;
	int		i;

	angle = data->ray.angle - data->ray.fov / 2;
	angle_end = data->ray.angle + data->ray.fov / 2;
	expand = data->ray.fov / data->mlx.screen_width;
	i = 0;
	while (angle <= angle_end)
	{
		vachier = throw_ray(data, angle);
		printf("iter n : %d, angle : %f, dist : %f\n", i, angle, vachier.dist);
		render_line(data, i,  50 * vachier.dist, 1080, new_color(255, 0, 0, 0));
		angle += expand;
		i++;
	}
}
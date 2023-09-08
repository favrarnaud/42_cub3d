/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ne.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:32:25 by afavre            #+#    #+#             */
/*   Updated: 2023/09/07 15:32:28 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_ne_next_point(t_data *data, t_col_info *col, float angle)
{
	printf("sin --> %f\n", sin(degree_to_radians(angle)));
	printf("cos --> %f\n", cos(degree_to_radians(angle)));
	printf("tan --> %f\n", tan(degree_to_radians(angle)));
	col->hyp_y = (floorf(col->start.x + 1) - col->start.x) / cos(degree_to_radians(angle));
	col->hyp_x = (col->start.y - floorf(col->start.y)) / sin(degree_to_radians(angle));

	if (col->hyp_x < col->hyp_y && col->hyp_x != 0)
	{
		col->new.x = (float)(col->start.x + ((col->start.y - floorf(col->start.y)) / tan(degree_to_radians(angle))));
		col->new.y = (floorf(col->start.y));
		col->face = SOUTH;
		if (data->map.map[(int)col->new.x][(int)col->new.y - 1] == 'F')
			return (0);
		else
			return (1);
	}
	else
	{
		col->new.x = (floorf(col->start.x + 1));
		col->new.y = (col->start.y - ((floor(col->start.x + 1) - col->start.x) * tan(degree_to_radians(angle))));
		col->face = WEST;
		if (data->map.map[(int)col->new.x - 1][(int)col->new.y] == 'F')
			return (0);
		else
			return (1);
	}
}

float get_hypo(float adj, float opp)
{
	return (sqrt(pow(adj, 2) + pow(opp, 2)));
}

t_col_info get_ne_ray(t_data *data, float angle)
{
	t_col_info col;

	col.dist = 0;
	col.start.x = data->ray.player_pos.x;
	col.start.y = data->ray.player_pos.y;
	while (1)
	{
		if (get_ne_next_point(data, &col, angle) == 1)
			break;
		col.start.x = col.new.x;
		col.start.y = col.new.y;
	}
	printf("test x : %f, y : %f\n", col.start.x, col.start.y);
	return (col);
}
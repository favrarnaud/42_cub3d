/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ne.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:32:25 by afavre            #+#    #+#             */
/*   Updated: 2023/09/07 15:32:28 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_ne_next_point(t_data *data, t_col_info *col, float angle)
{
	col->hyp_y = (floorf(col->start.x + 1) - col->start.x) / cos(degree_to_radians(angle));
	col->hyp_x = (col->start.y - floorf(col->start.y)) / sin(degree_to_radians(angle));

	if (col->hyp_x < col->hyp_y && col->hyp_x != 0)
	{
		col->new.x = (col->start.x + ((col->start.y - floorf(col->start.y)) / tan(degree_to_radians(angle))));
		col->new.y = (floorf(col->start.y));
		if (data->map.map[(int)col->new.x][(int)col->new.y] == 'F')
		{
			col->face = WEST;
			return (0);
		}
		else
			return (1);
	}
	else
	{
		col->new.x = (floorf(col->start.x + 1));
		col->new.y = (col->start.y - ((floor(col->start.x + 1) - col->start.x) * tan(degree_to_radians(angle))));
		if (data->map.map[(int)col->new.x][(int)col->new.y] == 'F')
		{
			col->face = SOUTH;
			return (0);
		}
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
	int i = 0;

	col.dist = 0;
	col.start.x = data->ray.player_pos.x;
	col.start.y = data->ray.player_pos.y;
	while (get_ne_next_point(data, &col, angle) != 1)
	{
		col.start.x = col.new.x;
		col.start.y = col.new.y;
		i++;
	}
	col.dist = get_hypo((col.start.x - data->ray.player_pos.x), (col.start.y - data->ray.player_pos.y));
	printf("start pos = x : %f, y : %f, angle : %f, x : %f, y : %f, avec %d iteration pour une distance de %f avec une facade %u\n",data->ray.player_pos.x, data->ray.player_pos.y,  angle, col.start.x, col.start.y, i, col.dist, col.face);
	return (col);
}

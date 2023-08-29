/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radians.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:29:23 by afavre            #+#    #+#             */
/*   Updated: 2023/08/02 11:29:26 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

double dotProduct(t_vec a, t_vec b) {
	return a.x * b.x + a.y * b.y;
}

double vec_norm(t_vec vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

int define_face(t_vec ray)
{
	t_vec east = {1, 0};
//	t_vec west = {-1, 0};
//	t_vec north = {0, -1};
//	t_vec south = {0, 1};

	double p1 = dotProduct(ray, east) / vec_norm(ray);
	if (p1 >= -1 && p1 <= -sqrt(2) / 2)
	{
		return(WEST);
	}
	if (p1 >= -sqrt(2) / 2 && p1 <= sqrt(2) / 2)
	{
		if (ray.y > 0)
			return (SOUTH);
		return (NORTH);
	}
	if (p1 <= 1 && p1 >= sqrt(2) / 2)
	{
		return(EAST);
	}
	return (NONE);
}

int set_color(wall_face face)
{
	if (face == NORTH)
		return (new_color(0, 0, 255, 0));
	else if (face == SOUTH)
		return (new_color(255, 255, 0, 0));
	else if (face == EAST)
		return (new_color(255, 0, 0, 0));
	else if (face == WEST)
		return (new_color(0, 255, 0, 0));
	else
		return (new_color(0, 0, 0, 0));
}

t_vec substract_vec(t_vec a, t_vec b)
{
	t_vec res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	return (res);
}


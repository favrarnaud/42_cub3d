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

int 	set_color(wall_face face)
{
	if (face == NORTH)
		return (new_color(255, 0, 0, 0));
	else if (face == SOUTH)
		return (new_color(0, 255, 0, 0));
	else if (face == EAST)
		return (new_color(0, 0, 255, 0));
	else if (face == WEST)
		return (new_color(255, 255, 0, 0));
	return (new_color(255, 255, 255, 0));

}

double dotProduct(t_vec a, t_vec b) {
	return a.x * b.x + a.y * b.y;
}

int define_face(t_vec ray)
{
	t_vec east = {1, 0};
	t_vec west = {-1, 0};
	t_vec north = {0, 1};
	t_vec south = {0, -1};

	double p1 = dotProduct(ray, east);
	double p2 = dotProduct(ray, west);
	double p3 = dotProduct(ray, north);
	double p4 = dotProduct(ray, south);

	if (p1 > 0 && p1 >= p2 && p1 >= p3 && p1 >= p4) {
		return (new_color(0, 0, 255, 0));
	} else if (p2 > 0 && p2 >= p1 && p2 >= p3 && p2 >= p4) {
		return (new_color(255, 255, 0, 0));
	} else if (p3 > 0 && p3 >= p1 && p3 >= p2 && p3 >= p4) {
		return (new_color(255, 0, 0, 0));
	} else if (p4 > 0 && p4 >= p1 && p4 >= p2 && p4 >= p3) {
		return (new_color(0, 255, 0, 0));
	} else {
		return (new_color(255, 255, 255, 0));
	}
}


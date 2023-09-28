/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:00:50 by bberger           #+#    #+#             */
/*   Updated: 2023/09/22 15:32:28 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(t_data *data)
{
	if (data->block.face[data->raycast.x] == NORTH)
		return (new_color(255, 0, 0, 0));
	else if (data->block.face[data->raycast.x] == SOUTH)
		return (new_color(0, 255, 0, 0));
	else if (data->block.face[data->raycast.x] == WEST)
		return (new_color(0, 0, 255, 0));
	else if (data->block.face[data->raycast.x] == EAST)
		return (new_color(0, 0, 0, 0));
	return (new_color(45, 41, 56, 0));
}

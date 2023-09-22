/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:13:29 by afavre            #+#    #+#             */
/*   Updated: 2023/09/21 17:13:31 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	la_gauche(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->cam.dir_x;
	data->cam.dir_x = data->cam.dir_x * cos(-data->cam.r_sp) - \
	data->cam.dir_y * sin(-data->cam.r_sp);
	data->cam.dir_y = old_dir_x * sin(-data->cam.r_sp) + data->cam.dir_y * \
	cos(-data->cam.r_sp);
	old_plane_x = data->cam.plane_x;
	data->cam.plane_x = data->cam.plane_x * cos(-data->cam.r_sp) - \
	data->cam.plane_y * sin(-data->cam.r_sp);
	data->cam.plane_y = old_plane_x * sin(-data->cam.r_sp) + \
	data->cam.plane_y * cos(-data->cam.r_sp);
}

void	la_droite(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->cam.dir_x;
	data->cam.dir_x = data->cam.dir_x * cos(data->cam.r_sp) - \
	data->cam.dir_y * sin(data->cam.r_sp);
	data->cam.dir_y = old_dir_x * sin(data->cam.r_sp) + data->cam.dir_y * \
	cos(data->cam.r_sp);
	old_plane_x = data->cam.plane_x;
	data->cam.plane_x = data->cam.plane_x * cos(data->cam.r_sp) - \
	data->cam.plane_y * sin(data->cam.r_sp);
	data->cam.plane_y = old_plane_x * sin(data->cam.r_sp) + data->cam.plane_y * \
	cos(data->cam.r_sp);
}

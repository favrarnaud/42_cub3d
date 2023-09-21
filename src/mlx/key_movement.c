/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:02:03 by afavre            #+#    #+#             */
/*   Updated: 2023/09/21 17:02:15 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	devant(t_data *data)
{
	if (data->map.map[(int)(data->player.pos_x + \
	data->cam.dir_x * data->cam.m_sp)][(int)(data->player.pos_y)] == 'F')
		data->player.pos_x += data->cam.dir_x * data->cam.m_sp;
	if (data->map.map[(int)(data->player.pos_x)][(int)(data->player.pos_y \
	+ data->cam.dir_y * data->cam.m_sp)] == 'F')
		data->player.pos_y += data->cam.dir_y * data->cam.m_sp;
}

void	derriere(t_data *data)
{
	if (data->map.map[(int)(data->player.pos_x - data->cam.dir_x \
	* data->cam.m_sp)][(int)(data->player.pos_y)] == 'F')
		data->player.pos_x -= data->cam.dir_x * data->cam.m_sp;
	if (data->map.map[(int)(data->player.pos_x)][(int)(data->player.pos_y - \
	data->cam.dir_y * data->cam.m_sp)] == 'F')
		data->player.pos_y -= data->cam.dir_y * data->cam.m_sp;
}

void	moonwalk_gauche(t_data *data)
{
	if (data->map.map[(int)(data->player.pos_x - \
	data->cam.dir_y * data->cam.m_sp)][(int)(data->player.pos_y)] == 'F')
		data->player.pos_x -= data->cam.dir_y * data->cam.m_sp;
	if (data->map.map[(int)(data->player.pos_x)][(int)(data->player.pos_y + \
	data->cam.dir_x * data->cam.m_sp)] == 'F')
		data->player.pos_y += data->cam.dir_x * data->cam.m_sp;
}

void	moonwalk_droit(t_data *data)
{
	if (data->map.map[(int)(data->player.pos_x + \
	data->cam.dir_y * data->cam.m_sp)][(int)(data->player.pos_y)] == 'F')
		data->player.pos_x += data->cam.dir_y * data->cam.m_sp;
	if (data->map.map[(int)(data->player.pos_x)][(int)(data->player.pos_y - \
	data->cam.dir_x * data->cam.m_sp)] == 'F')
		data->player.pos_y -= data->cam.dir_x * data->cam.m_sp;
}

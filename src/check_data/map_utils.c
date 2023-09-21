/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:33:30 by bberger           #+#    #+#             */
/*   Updated: 2023/08/25 17:58:26 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_info(t_data *data)
{
	if (data->map.map[data->trash.ty][data->trash.tx] == 'x' || \
	data->map.map[data->trash.ty][data->trash.tx] == '0' || \
				data->map.map[data->trash.ty][data->trash.tx] == '1')
		data->trash.tx++;
	else if ((data->map.map[data->trash.ty][data->trash.tx] == 'N' || \
			data->map.map[data->trash.ty][data->trash.tx] == 'S' || \
			data->map.map[data->trash.ty][data->trash.tx] == 'E' || \
			data->map.map[data->trash.ty][data->trash.tx] == 'W') \
			&& data->trash.dup == 0)
	{
		data->player.pos_x = (data->trash.ty + 0.51);
		data->player.pos_y = (data->trash.tx + 0.51);
		set_orientation(data, data->map.map[data->trash.ty][data->trash.tx]);
		data->trash.dup = 1;
		data->trash.tx++;
	}
	else
		return (print_error("Double player detectee dans la map"));
	return (0);
}

int	check_char_dup(t_data *data)
{
	data->trash.ty = 0;
	data->trash.dup = 0;
	while (data->trash.ty < data->map.height)
	{
		data->trash.tx = 0;
		while (data->trash.tx < data->map.width)
		{
			if (set_info(data) == -1)
				return (-1);
		}
		data->trash.ty++;
	}
	if (data->trash.dup == 0)
		return (print_error("La map ne contient pas de player"));
	return (0);
}

int	flood_fill_map(t_data *data, int h, int l)
{
	if (data->map.map[h][l] == 'x')
	{
		printf("Hole in the wall of your map\n");
		exit(1);
	}
	else if (h < 0 || h >= data->map.height || l < 0 || l >= data->map.width
		|| data->map.map[h][l] == 'F' || data->map.map[h][l] == '1')
		return (0);
	data->map.map[h][l] = 'F';
	flood_fill_map(data, h - 1, l - 1);
	flood_fill_map(data, h - 1, l);
	flood_fill_map(data, h - 1, l + 1);
	flood_fill_map(data, h, l - 1);
	flood_fill_map(data, h, l + 1);
	flood_fill_map(data, h + 1, l - 1);
	flood_fill_map(data, h + 1, l);
	flood_fill_map(data, h + 1, l + 1);
	return (0);
}

int	check_closed_map(t_data *data)
{
	int	h;
	int	l;

	h = 0;
	while (h >= 0 && h < data->map.height)
	{
		l = 0;
		while (l < data->map.width)
		{
			if (data->map.map[h][l] == '0')
			{
				if (flood_fill_map(data, h, l) == -1)
				{
					free_all(data);
					exit(1);
				}
			}
			l++;
		}
		h++;
	}
	return (0);
}

int	check_line_start(char **tab)
{
	if (ft_strncmp(tab[0], "NO", 2) == 0 || \
		ft_strncmp(tab[0], "SO", 2) == 0 || \
		ft_strncmp(tab[0], "WE", 2) == 0 || \
		ft_strncmp(tab[0], "EA", 2) == 0 || \
		ft_strncmp(tab[0], "F", 1) == 0 || \
		ft_strncmp(tab[0], "C", 1) == 0)
		return (0);
	return (-1);
}

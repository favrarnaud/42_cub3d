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

int	check_char_dup(t_data *data)
{
	int	l;
	int h;
	int dup;

	h = 0;
	dup = 0;
	while (h < data->map.h_map)
	{
		l = 0;
		while (l < data->map.l_map)
		{
			if (data->map.map[h][l] == 'x' || data->map.map[h][l] == '0' || \
				data->map.map[h][l] == '1')
				l++;
			else if ((data->map.map[h][l] == 'N' || data->map.map[h][l] == 'S' || \
			data->map.map[h][l] == 'E' || data->map.map[h][l] == 'W') && dup == 0)
			{
				data->ray.player_pos.x = (h + 0.5);
				data->ray.player_pos.y = (l + 0.5);
				if (data->map.map[h][l] == 'N')
					data->ray.angle = 270;
				else if (data->map.map[h][l] == 'S')
					//TODO change this value
					data->ray.angle = 45;
				else if (data->map.map[h][l] == 'W')
					data->ray.angle = 180;
				else if (data->map.map[h][l] == 'E')
					data->ray.angle = 0;
				dup = 1;
				l++;
			}
			else
				return (print_error("Double player detectee dans la map"));
		}
		h++;
	}
	if (dup == 0)
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
	else if (h < 0 || h >= data->map.h_map || l < 0 || l >= data->map.l_map
		|| data->map.map[h][l] == 'F'  || data->map.map[h][l] == '1')
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
	while(h >= 0 && h < data->map.h_map)
	{
		l = 0;
		while (l < data->map.l_map)
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

int	Check_line_start(char **tab)
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

void clear_fmap(t_data *data)
{
	int h;
	int l;

	h = 0;
	while (h < data->map.h_map)
	{
		l = 0;
		while (l < data->map.l_map)
		{
			printf("test --> %d, %d", h, l);
			if (data->map.map[h][l] == 'F')
				data->map.map[h][l] = '0';
			l++;
		}
		h++;
	}
}
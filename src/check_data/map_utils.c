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

bool	check_char_dup(char **map, int *dup)
{
	int	l;
	int h;

	h = 0;
	while (map[h])
	{
		l = 0;
		while (map[h][l])
		{
			if (map[h][l] == 'x' || map[h][l] == '0' || map[h][l] == '1')
				l++;
			else if ((map[h][l] == 'N' || map[h][l] == 'S' || \
			map[h][l] == 'E' || map[h][l] == 'W') && !*dup)
			{
				*dup = 1;
				l++;
			}
			else
				return (false);
		}	
		h++;
	}
	return (true);
}

int	is_letter(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}


//  || data->map.map[h][l] == '1'
int	flood_fill_map(t_data *data, int h, int l)
{
	if (data->map.map[h][l] == 'x')
	{
		printf("map not valid\n");
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
	
bool	check_closed_map(t_data *data)
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
	return (true);
}
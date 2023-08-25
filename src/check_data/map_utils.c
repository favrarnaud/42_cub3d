/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:33:30 by bberger           #+#    #+#             */
/*   Updated: 2023/08/25 14:00:26 by bberger          ###   ########.fr       */
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

// int is_surrounded(char **map, int h, int l)
// {
// 	if (map[h][l])
// 	{
// 		if (h > 0 && h < map->map.h_map) && (l > 0 && l < map->map.l_map)
// 		{
// 			if (map[h-1][l-1] == '0' || map[h-1][l] == '0' || map[h-1][l+1] == '0')
// 				return (1);
// 			if (map[h][l-1] == '0' || map[h][l +1] == '0')
// 				return (1);
// 			if (map[h+1][l-1] == '0' || map[h+1][l] == '0' || map[h+1][l+1] == '0')
// 				return (1);
// 		}
		
// 		else if (h == 0 && (l > 0 && l < map->map.l_map))
// 		{
// 			if (map[h][l-1] == '0' || map[h][l +1] == '0')
// 				return (1);
// 			if (map[h+1][l-1] == '0' || map[h+1][l] == '0' || map[h+1][l+1] == '0')
// 				return (1);
// 		}
		
// 		else if (h == map->map.h_map -1) && (l > 0 && l < map->map.l_map)
// 		{
// 			if (map[h-1][l-1] == '0' || map[h-1][l] == '0' || map[h-1][l+1] == '0')
// 				return (1);
// 			if (map[h][l-1] == '0' || map[h][l +1] == '0')
// 				return (1);
// 		}

// 		else if (h > 0 && h < map->map.h_map) && (l == 0)
// 		{
// 			if (map[h-1][l] == '0' || map[h-1][l+1] == '0')
// 				return (1);
// 			if (map[h][l +1] == '0')
// 				return (1);
// 			if (map[h+1][l] == '0' || map[h+1][l+1] == '0')
// 				return (1);
// 		}
		
// 		else if (h > 0 && h < map->map.h_map) && (l == map->map.l_map)
// 		{
// 			if (map[h-1][l-1] == '0' || map[h-1][l] == '0')
// 				return (1);
// 			if (map[h][l-1] == '0')
// 				return (1);
// 			if (map[h+1][l-1] == '0' || map[h+1][l] == '0')
// 				return (1);
// 		}

// 		// 
// 		else if (h == 0 && l == 0)
// 		{
// 			if (map[h][l +1] == '0')
// 				return (1);
// 			if (map[h+1][l] == '0' || map[h+1][l+1] == '0')
// 				return (1);
// 		}
// 		else if (h == 0 && l == map->map.l_map)
// 		{
// 			if (map[h][l-1] == '0')
// 				return (1);
// 			if (map[h+1][l-1] == '0' || map[h+1][l] == '0')
// 				return (1);
// 		}
// 		else if (h == map->map.h_map) && (l == 0)
// 		{
// 			if (map[h-1][l] == '0' || map[h-1][l+1] == '0')
// 				return (1);
// 			if (map[h][l +1] == '0')
// 				return (1);
// 		}
// 		else if (h == map->map.h_map) && (l == map->map.l_map)
// 		{
// 			if (map[h-1][l-1] == '0' || map[h-1][l] == '0')
// 				return (1);
// 			if (map[h][l-1] == '0')
// 				return (1);
// 		}
		
// 	}
// 	return (0);	
// }

// bool 	check_char_surrounded(char **map)
// {
// 	int h;
// 	int l;

// 	h = 0;
// 	while (*map[h])
// 	{
// 		while (map[h][l])
// 		{
// 			if (is_letter(map[h][l]) == 1 && is_surrouned(map, h, l, map[h][l]))
// 			l++;
// 		}
// 		h++;
// 	}
// }

void	flood_fill_map(t_data *data, int h, int l)
{
	if (h < 0 || h >= data->map.h_map || l < 0 || l >= data->map.l_map
		|| data->map.map[h][l] != 'F')
		return;

	data->map.map[h][l] = 'F';
	flood_fill_map(data, h - 1, l - 1);
	flood_fill_map(data, h - 1, l);
	flood_fill_map(data, h - 1, l + 1);
	flood_fill_map(data, h, l - 1);
	flood_fill_map(data, h, l + 1);
	flood_fill_map(data, h + 1, l - 1);
	flood_fill_map(data, h + 1, l);
	flood_fill_map(data, h + 1, l + 1);

}
	
bool	check_closed_map(t_data *data)
{
	int	h;
	int	l;

	h = 0;
	while(h >= 0 && h <= data->map.h_map)
	{
		l = 0;
		while (l >= 0 && l >= data->map.l_map)
		{
			if (data->map.map[h][l] == '0')
			{
				flood_fill_map(data, h, l);
			}
				return (false);
			l++; 
		}
		h++;
	}
	return (true);
}
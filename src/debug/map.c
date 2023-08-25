/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:00:41 by afavre            #+#    #+#             */
/*   Updated: 2023/08/24 16:24:36 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_map(t_data *data)
{
	int i;
	int map_size;

	i = 0;
	map_size = data->map.map_size;
	data->map.tab = malloc(sizeof(int *) * map_size);
	while (i < map_size)
	{
		data->map.tab[i] = malloc(sizeof(int) * map_size);
		i++;
	}
}

void	set_raw(t_data *data, int raw, const char *str)
{
	int i;
	char c;

	i = 0;
	while (i < data->map.map_size)
	{
		c = str[i];
		if (c)
			data->map.tab[raw][i] = ft_atoi(&c);
		else
			data->map.tab[raw][i] = 99;
		i++;
	}
	i = 0;
}

void	gen_map(t_data *data)
{
	malloc_map(data);
	set_raw(data, 0, "1111101111");
	set_raw(data, 1, "1000010001");
	set_raw(data, 2, "1000010001");
	set_raw(data, 3, "1000010001");
	set_raw(data, 4, "1000010001");
	set_raw(data, 5, "1000000001");
	set_raw(data, 6, "1000000001");
	set_raw(data, 7, "1000000001");
	set_raw(data, 8, "1000000001");
	set_raw(data, 9, "1111111111");
}

void	clear_map(t_data *data)
{
	int i;
	int map_size;

	i = 0;
	map_size = data->map.map_size;
	while (i < map_size)
	{
		free(data->map.tab[i]);
		i++;
	}
	free(data->map.tab);
}

// void	print_map(t_data *data)
// {
// 	int i;
// 	int j;
// 	int map_size;

// 	i = 0;
// 	j = 0;
// 	map_size = data->map.map_size;
// 	while (i < map_size)
// 	{
// 		while (j < map_size)
// 		{
// 			printf("%d", data->map.tab[i][j]);
// //			if (j != map_size - 1)
// //				ft_printf(" | ");
// 			j++;
// 		}
// 		printf("\n");
// 		j = 0;
// 		i++;
// 	}
// }
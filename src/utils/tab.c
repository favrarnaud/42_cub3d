/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:15:23 by afavre            #+#    #+#             */
/*   Updated: 2023/08/25 13:42:21 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	print_map(t_data *data)
//{
//	int y;
//	int x;
//
//	y = 0;
//
//	printf("Texture nord : %s\n", data->texture.no_path);
//	printf("Texture sud : %s\n", data->texture.so_path);
//	printf("Texture est : %s\n", data->texture.ea_path);
//	printf("Texture west : %s\n", data->texture.we_path);
//	printf("couleur plafond : %d\n", data->texture.c_color);
//	printf("couleur sol: %d\n", data->texture.f_color);
//	printf("position player: x --> %f, y ---> %f\n", data->player.pos_x, data->player.pos_y);
//	printf("\n");
//
//	while (y < data->map.height)
//	{
//		x = 0;
//		while (x < data->map.width)
//		{
//			printf("%c", data->map.map[y][x]);
//			x++;
//		}
//		printf("\n");
//		y++;
//	}
//}
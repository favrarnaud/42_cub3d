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

void	print_map(t_data *data)
{
	int h;
	int l;

	h = 0;

	printf("Texture nord : %s\n", data->texture.NO_path);
	printf("Texture sud : %s\n", data->texture.SO_path);
	printf("Texture est : %s\n", data->texture.EA_path);
	printf("Texture west : %s\n", data->texture.WE_path);
	printf("couleur plafond : %d\n", data->texture.C_color);
	printf("couleur sol: %d\n", data->texture.F_color);
//	printf("position player: x --> %d, y ---> %d\n", data->ray.player_pos.x, data->ray.player_pos.y);
//	printf("horientation player: %d\n", data->ray.angle);
	printf("\n");

	while (h < data->map.h_map)
	{
		l = 0;
		while (l < data->map.l_map)
		{
			printf("%c", data->map.map[h][l]);
			l++;
		}
		printf("\n");
		h++;
	}
}
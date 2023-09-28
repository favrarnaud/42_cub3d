/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:40:29 by afavre            #+#    #+#             */
/*   Updated: 2023/09/27 14:40:41 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_block_info(t_block *block)
{
	printf("debug");
}

void	print_int_tab(int *tab, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("value --> %d\n", tab[i]);
		i++;
	}
}

//void	test(t_data *data)
//{
//	int i = 0;
//	int j = 0;
//	double k = 0;
//	double l = 0;
//	double stepx;
//	double stepy;
//	int color;
//
//	stepx = TEXWIDTH / 512;
//	stepy = TEXHEIGHT / 512;
//
//	while (i < 512)
//	{
//		while (j < 512)
//		{
//			color = get_pixel_color(&data->texture.no_data, (int)k, (int)l);
//			add_pixel(data, i, j, color);
//			l += stepy;
//			j++;
//		}
//		k += stepx;
//		l = 0;
//		j = 0;
//		i++;
//	}
//}
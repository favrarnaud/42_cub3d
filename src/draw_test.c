/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:29:22 by afavre            #+#    #+#             */
/*   Updated: 2023/09/26 18:29:24 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	draw_test(t_data *data)
//{
//	double	stepx;
//	double	stepy;
//	double	x;
//	double	y;
//	t_point	po;
//
//	po.x = 0;
//	stepx = TEXWIDTH / data->mlx.screen_width;
//	stepy = TEXHEIGHT / data->mlx.screen_height;
//	while (po.x < data->mlx.screen_height)
//	{
//		x = 0;
//		po.y = 0;
//		while (po.y < data->mlx.screen_width)
//		{
//			add_pixel(data, (int)po.y, (int)po.x, \
//			get_pixel_color(&data->texture.no_data, (int)x, \
//			(int)y));
//			x += stepx;
//			po.y++;
//		}
//		y += stepy;
//		po.x++;
//	}
//}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:58:53 by afavre            #+#    #+#             */
/*   Updated: 2023/09/19 14:12:44 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		new_color(int r, int g, int b, int a)
{
	int color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

void	add_pixel(t_data *data, t_img *img, int x, int y, int color)
{
	char    *pixel;

	if ((x >= data->mlx.screen_width || x <= 0 || y >= data->mlx.screen_height || y <= 0))
		return;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	render_rect(t_data *data, int x, int y, int height, int width, int color)
{
	int	i;
	int j;

	i = y;
	while (i < (y + height))
	{
		j = x;
		while (j < (x + width))
		{
			add_pixel(data, &data->img, j, i, color);
			j++;
		}
		++i;
	}
}

void	render_line(t_data *data, int col, int start, int end, int color)
{
	int i;

	i = start;
	while (i < end)
	{
		add_pixel(data, &data->img, col, i, color);
		i++;
	}
}



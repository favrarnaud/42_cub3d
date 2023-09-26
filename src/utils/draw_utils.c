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

int	new_color(int r, int g, int b, int a)
{
	int	color;

	color = (a << 24) + (r << 16) + (g << 8) + b;
	return (color);
}

void	add_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if ((x >= data->mlx.screen_width || x <= 0 || \
	y >= data->mlx.screen_height || y <= 0))
		return ;
	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)pixel = color;
}

int get_pixel_color(t_img *image, int x, int y)
{
	int location;

	location = (x * image->bpp / 8) + (y * image->line_len);
	return (*(int *)(image->addr + location));
}

void	render_rect(t_data *data, t_point t, t_rect r, int color)
{
	int	i;
	int	j;

	i = (int)t.y;
	while (i < (t.y + r.height))
	{
		j = (int)t.x;
		while (j < (t.x + r.width))
		{
			add_pixel(data, j, i, color);
			j++;
		}
		++i;
	}
}

void	render_line(t_data *data, int col, t_point t, int color)
{
	int	i;

	i = (int)t.x;
	while (i < t.y)
	{
		add_pixel(data, col, i, color);
		i++;
	}
}

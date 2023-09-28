/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:08:05 by afavre            #+#    #+#             */
/*   Updated: 2023/09/26 19:08:06 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pixtur(t_data *data, double tx, double ty)
{
	char	*pixel;

	pixel = data->texture.no_tex.img + ((int)ty * data->texture.no_data.line_len + (int)tx * (data->texture.no_data.bpp / 8));
	return (*(int *)pixel);
}

void	draw_col(t_data *data)
{
	int i;
	int j;
	int k;
	double l;
	double m;
	double stepw;
	double steph;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	while (i < data->block.nb_width)
	{
		stepw = TEXWIDTH / data->block.width[i];
		while (j < data->block.width[i])
		{
			while (k < data->block.height[data->block.xcol])
			{
				steph = TEXHEIGHT / data->block.height[data->block.xcol];
				add_pixel(data, j, k, get_pixel_color(&data->texture.no_data, (int)l, (int)m));
				m += steph;
				k++;
			}
			m = 0;
			l += stepw;
			data->block.xcol++;
			j++;
		}
		j = 0;
		i++;
	}
}

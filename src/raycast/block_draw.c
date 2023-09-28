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

	pixel = data->texture.no_tex.img + ((int)ty * data->img.line_len + \
		(int)tx * (data->img.bpp / 8));
	return (*(int *)pixel);
}

void	draw_col(t_data *data)
{
	int i;

	i = 0;
	while (i < data->block.nb_width)
	{
		i++;
	}
}

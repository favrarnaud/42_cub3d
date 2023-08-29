/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:39:42 by bberger           #+#    #+#             */
/*   Updated: 2023/08/25 17:03:57 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_int_tab(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

void	free_all(t_data *data)
{
	free(&data->texture.NO_path);
	free(&data->texture.SO_path);
	free(&data->texture.WE_path);
	free(&data->texture.EA_path);
	free_tab(data->map.map);
	free_int_tab(&data->texture.F_color);
	free_int_tab(&data->texture.C_color);
}
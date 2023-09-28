/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:46:53 by afavre            #+#    #+#             */
/*   Updated: 2023/09/27 15:46:55 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_block(t_block *block)
{

	block->nb_width = 0;
	block->nb_height = 0;
	block->nb_face = 0;
	block->xcol = 0;
	block->width = NULL;
	block->height = NULL;
	block->face = NULL;
}

void	add_height(t_block *block, int new_height)
{
	int *new;
	int i;

	i = 0;
	block->nb_height++;
	new = malloc(sizeof(int) * block->nb_height);
	while (i < block->nb_height - 1)
	{
		new[i] = block->height[i];
		i++;
	}
	new[i] = new_height;
	if (block->height != NULL)
		free(block->height);
	block->height = new;

}

void	add_width(t_block *block, int new_width)
{
	int *new;
	int i;

	i = 0;
	block->nb_width++;
	new = malloc(sizeof(int) * block->nb_width);
	while (i < block->nb_width - 1)
	{
		new[i] = block->width[i];
		i++;
	}
	new[i] = new_width;
	if (block->width != NULL)
		free(block->width);
	block->width = new;

}

void	add_face(t_block *block, int new_face)
{
	int *new;
	int i;

	i = 0;
	block->nb_face++;
	new = malloc(sizeof(int) * block->nb_face);
	while (i < block->nb_face - 1)
	{
		new[i] = block->face[i];
		i++;
	}
	new[i] = new_face;
	if (block->face != NULL)
		free(block->face);
	block->face = new;

}

void	free_all(t_data *data)
{
	free(data->block.width);
	free(data->block.height);
	free(data->block.face);
}






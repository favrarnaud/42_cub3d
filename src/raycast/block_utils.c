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

void init_block(t_block *block)
{
	block->height_len = 1;
	block->height = malloc(sizeof(int) * 1);
	block->height[0] = -1;
	block->width = 0;
}

t_block	add_height(t_block block, int height)
{
	t_block nb;
	int i;

	i = 0;
	nb.width = block.width;
	nb.height_len = block.height_len + 1;
	nb.height = malloc(sizeof(int) * nb.height_len);
	while (i < nb.height_len)
	{
		break;
	}
	return (nb);
}

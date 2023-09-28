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

void	print_int_tab(int *test, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("value --> %d\n", test[i]);
		i++;
	}
}
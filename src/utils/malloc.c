/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:29:22 by bberger           #+#    #+#             */
/*   Updated: 2023/08/24 16:45:47 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*pro_malloc(size_t size)
{
	void *ptr;
	
	ptr = malloc(size);
	if (!ptr)
	{
		printf("Error: Could not malloc");
		exit(1);
	}
	ft_bzero(ptr, size);
	return (ptr);		
}
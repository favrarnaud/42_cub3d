/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radians.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:29:23 by afavre            #+#    #+#             */
/*   Updated: 2023/08/02 11:29:26 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// referentiel X = horizontal  referentiel Y = vertical

double	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:59:45 by afavre            #+#    #+#             */
/*   Updated: 2023/08/18 11:59:48 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char* ftoa(float n, char* res, int afterpoint) {
	int ipart = (int)n;
	float fpart = n - (float)ipart;
	int i = sprintf(res, "%d", ipart);
	if (afterpoint != 0) {
		fpart = fpart * pow(10, afterpoint);
		sprintf(res + i, ".%d", (int)fpart);
	}
	return res;
}

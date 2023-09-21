/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:28 by afavre            #+#    #+#             */
/*   Updated: 2023/09/05 16:12:40 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	divided_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] != ' ' && str[i] != '\0')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\0')
		{
			printf("Les salles solitaires ne sont pas autorisees\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

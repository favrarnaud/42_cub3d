/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:09:08 by bberger           #+#    #+#             */
/*   Updated: 2023/08/29 16:20:57 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check if texture str is a .xpm file
int	check_xpm_file(char *str)
{
	if (ft_strlen(str) < 5)
	{
		printf("Error: texture file must be longer than 5 letters!");
		return (-1);
	}
	else if (ft_strncmp(&str[ft_strlen(str) - 4], ".xpm", 4) != 0)
	{
		printf("Error: texture must be a .xpm file");
		return (-1);
	}
	return (0);
}

// check if NO file is fill in data struct, access fct allows to check if path
// is valid, (2^0 = 1)
int	check_no_fill(t_data *data, char **tab)
{
	if (ft_strncmp("NO", tab[0], 2))
		return (1);
	if (data->texture.no_dup.north == 1)
	{
		printf("ERROR : Doublon dans NO\n");
		return (-1);
	}
	data->texture.no_dup.north = 1;
	if (access(tab[1], R_OK))
	{
		printf("ERROR : Fichier de NO inaccessible\n");
		return (-1);
	}
	if (check_xpm_file(tab[1]) != 0)
		return (-1);
	data->texture.no_path = pro_malloc(sizeof(char) * \
	(ft_strlen(tab[1]) + 1));
	data->texture.no_path = ft_strdup(tab[1]);
	return (0);
}

// 2^1 = 2
int	check_so_fill(t_data *data, char **tab)
{
	if (ft_strncmp("SO", tab[0], 2))
		return (1);
	if (data->texture.no_dup.south == 1)
	{
		printf("ERROR : Doublon dans SO\n");
		return (-1);
	}
	data->texture.no_dup.south = 1;
	if (access(tab[1], R_OK))
	{
		printf("ERROR : Fichier de SO inaccessible\n");
		return (-1);
	}
	if (check_xpm_file(tab[1]) != 0)
		return (-1);
	data->texture.so_path = pro_malloc(sizeof(char) * \
	(ft_strlen(tab[1]) + 1));
	data->texture.so_path = ft_strdup(tab[1]);
	return (0);
}

int	check_we_fill(t_data *data, char **tab)
{
	if (ft_strncmp("WE", tab[0], 2))
		return (1);
	if (data->texture.no_dup.west == 1)
	{
		printf("ERROR : Doublon dans WE\n");
		return (-1);
	}
	data->texture.no_dup.west = 1;
	if (access(tab[1], R_OK))
	{
		printf("ERROR : Fichier de WE inaccessible\n");
		return (-1);
	}
	if (check_xpm_file(tab[1]) == -1)
		return (-1);
	data->texture.we_path = pro_malloc(sizeof(char) * \
	(ft_strlen(tab[1]) + 1));
	data->texture.we_path = ft_strdup(tab[1]);
	return (0);
}

int	check_ea_fill(t_data *data, char **tab)
{
	if (ft_strncmp("EA", tab[0], 2))
		return (1);
	if (data->texture.no_dup.east == 1)
	{
		printf("ERROR : Doublon dans EA\n");
		return (-1);
	}
	data->texture.no_dup.east = 1;
	if (access(tab[1], R_OK))
	{
		printf("ERROR : Fichier de EA inaccessible\n");
		return (-1);
	}
	if (check_xpm_file(tab[1]) == -1)
		return (-1);
	data->texture.ea_path = pro_malloc(sizeof(char) * \
	(ft_strlen(tab[1]) + 1));
	data->texture.ea_path = ft_strdup(tab[1]);
	return (0);
}

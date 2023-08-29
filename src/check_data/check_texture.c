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
		return (1);
	}
	else if (ft_strncmp(&str[ft_strlen(str) - 4], ".xpm", 4) != 0)
	{
		printf("Error: texture must be a .xpm file");
		return (2);
	}
	return (0);
}

// check if NO file is fill in data struct, access fct allows to check if path is valid, (2^0 = 1)
bool	check_NO_fill(t_data *data, char **tab, char *no_dup)
{
	if (ft_strncmp("NO", tab[0], 2))
		return (false);
	if (*no_dup & 1)
	{
		printf("ERROR : Doublon dans NO");
		return (false);
	}
	*no_dup += 1;
	if (access(tab[1], R_OK))
	{
		printf("ERROR : Fichier de NO inaccessible\n");
		return (false);
	}
	if (check_xpm_file(tab[1]) != 0)
		return (false);
	data->texture.NO_path = pro_malloc(sizeof(char) * \
	(ft_strlen(tab[1]) + 1));
	data->texture.NO_path = ft_strdup(tab[1]);
	printf("%s\n", data->texture.NO_path);
	return (true);
}

// 2^1 = 2
bool	check_SO_fill(t_data *data, char **tab, char *no_dup)
{
	if (ft_strncmp("SO", tab[0], 2))
		return (false);
	if (*no_dup & 2)
	{
		printf("ERROR : Doublon dans SO");
		return (false);
	}
	*no_dup += 2;
	if (access(tab[1], R_OK))
	{
		printf("ERROR : Fichier de SO inaccessible\n");
		return (false);
	}
	if (check_xpm_file(tab[1]) != 0)
		return (false);
	data->texture.SO_path = pro_malloc(sizeof(char) * \
	(ft_strlen(tab[1]) + 1));
	data->texture.SO_path = ft_strdup(tab[1]);
	printf("%s\n", data->texture.SO_path);
	return (true);
}

bool	check_WE_fill(t_data *data, char **tab, char *no_dup)
{
	if (ft_strncmp("WE", tab[0], 2))
		return (false);
	if (*no_dup & 4)
	{
		printf("ERROR : Doublon dans WE\n");
		return (false);
	}
	*no_dup += 4;
	if (access(tab[1], R_OK))
	{
		printf("ERROR : Fichier de WE inaccessible\n");
		return (false);
	}
	if (check_xpm_file(tab[1]) != 0)
		return (false);
	data->texture.WE_path = pro_malloc(sizeof(char) * \
	(ft_strlen(tab[1]) + 1));
	data->texture.WE_path = ft_strdup(tab[1]);
	printf("%s\n", data->texture.WE_path);
	return (true);
}

bool	check_EA_fill(t_data *data, char **tab, char *no_dup)
{
	if (ft_strncmp("EA", tab[0], 2))
		return (false);
	if (*no_dup & 8)
	{
		printf("ERROR : Doublon dans EA\n");
		return (false);
	};
	*no_dup += 8;
	if (access(tab[1], R_OK))
	{
		printf("ERROR : Fichier de EA inaccessible\n");
		return (false);
	}
	if (check_xpm_file(tab[1]) != 0)
		return (false);
	data->texture.EA_path = pro_malloc(sizeof(char) * \
	(ft_strlen(tab[1]) + 1));
	data->texture.EA_path = ft_strdup(tab[1]);
	printf("%s\n", data->texture.EA_path);
	return (true);
}
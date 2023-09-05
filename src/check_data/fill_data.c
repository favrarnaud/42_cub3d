/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:57:58 by bberger           #+#    #+#             */
/*   Updated: 2023/08/29 16:09:14 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_F_fill(t_data *data, char **tab)
{
	int		rgb;
	int		i;
	int		j;
	char	**tmp;
	int 	*cold;

	if (ft_strncmp("F", tab[0], 1))
		return (1);
	if (data->texture.no_dup.floor == 1)
	{
		printf("ERROR : Doublon dans floor color\n");
		return (-1);
	}
	data->texture.no_dup.floor = 1;
	cold = pro_malloc(sizeof(int) * (3));
	tmp = ft_split(tab[1], ',');
	if (tab_size(tmp) != 3)
		return (-1);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] < '0' || tmp[i][j] > '9')
			{
				free_tab(tmp);
				return (-1);
			}
			j++;
		}
		rgb = ft_atoi(tmp[i]);
		if (rgb < 0 || rgb > 255)
		{
			free_tab(tmp);
			return (-1);
		}	
		cold[i] = rgb;
		i++;
	}
	data->texture.F_color = new_color(cold[0], cold[1], cold[2], 0);
	free(cold);
	free_tab(tmp);
	return (0);
}

int	check_C_fill(t_data *data, char **tab)
{
	int		rgb;
	int		i;
	int		j;
	char	**tmp;
	int 	*cold;

	if (ft_strncmp("C", tab[0], 1))
		return (1);
	if (data->texture.no_dup.ceilling == 1)
	{
		printf("ERROR : Doublon dans ceilling color\n");
		return (-1);
	}
	data->texture.no_dup.ceilling = 1;
	cold = pro_malloc(sizeof(int) * 3);
	tmp = ft_split(tab[1], ',');
	if (tab_size(tmp) != 3)
		return (-1);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] < '0' || tmp[i][j] > '9')
			{
				free_tab(tmp);
				return (-1);
			}
			j++;
		}
		rgb = ft_atoi(tmp[i]);
		if (rgb < 0 || rgb > 255)
		{
			free_tab(tmp);
			return (-1);
		}	
		cold[i] = rgb;
		i++;
	}
	data->texture.C_color = new_color(cold[0], cold[1], cold[2], 0);
	free(cold);
	free_tab(tmp);
	return (0);
}

int	check_dbstruct(t_data *data)
{
	int res;

	res = 0;
	res += data->texture.no_dup.north;
	res += data->texture.no_dup.south;
	res += data->texture.no_dup.east;
	res += data->texture.no_dup.west;
	res += data->texture.no_dup.floor;
	res += data->texture.no_dup.ceilling;

	return (res);
}

int	fill_data(t_data *data, char **tab)
{
	
	if (check_NO_fill(data, tab) == -1)
		return (-1);
	if (check_SO_fill(data, tab) == -1)
		return (-1);
	if (check_WE_fill(data, tab) == -1)
		return (-1);
	if (check_EA_fill(data, tab) == -1)
		return (-1);
	if (check_F_fill(data, tab) == -1)
		return (-1);
	if (check_C_fill(data, tab) == -1)
		return (-1);
	
	free_tab(tab);
	return (0);
}


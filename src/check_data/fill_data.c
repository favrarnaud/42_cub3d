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
void	print_color(int *tab)
{
	int i;
	
	i = 0;
	while (i < 3)
	{
		printf("%d\n", tab[i]);
		
		i++;
	}
}

bool	check_F_fill(t_data *data, char **tab, char *no_dup)
{
	int		rgb;
	int		i;
	int		j;
	char	**tmp;
	int 	*cold;

	if (ft_strncmp("F", tab[0], 1))
		return (false);
	if (*no_dup & 16)//2^4 = 16
	{
		printf("ERROR : Doublon dans floor color\n");
		return (false);
	}
	*no_dup += 16;
	cold = pro_malloc(sizeof(int) * (3));
	tmp = ft_split(tab[1], ',');
	if (tab_size(tmp) != 3)
		return (false);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] < '0' || tmp[i][j] > '9')
			{
				free_tab(tmp);
				return (false);
			}
			j++;
		}
		rgb = ft_atoi(tmp[i]);
		if (rgb < 0 || rgb > 255)
		{
			free_tab(tmp);
			return (false);
		}	
		cold[i] = rgb;
		i++;
	}
	data->texture.F_color = new_color(cold[0], cold[1], cold[2], 0);
	printf("F: %d\n", data->texture.F_color);
	free(cold);
	free_tab(tmp);
	return (true);
}

bool	check_C_fill(t_data *data, char **tab, char *no_dup)
{
	printf("lajoie est pas la \n");
	int		rgb;
	int		i;
	int		j;
	char	**tmp;
	int 	*cold;

	if (ft_strncmp("C", tab[0], 1))
	{
		printf("tu e 1 conar\n");
		return (false);
	}

	if (*no_dup & 32)
	{
		printf("ERROR : Doublon dans ceilling color\n");
		return (false);
	}
	*no_dup += 32;
	cold = pro_malloc(sizeof(int) * 3);
	tmp = ft_split(tab[1], ',');
	if (tab_size(tmp) != 3)
		return (false);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] < '0' || tmp[i][j] > '9')
			{
				free_tab(tmp);
				return (false);
			}
			j++;
		}
		rgb = ft_atoi(tmp[i]);
		if (rgb < 0 || rgb > 255)
		{
			free_tab(tmp);
			return (false);
		}	
		cold[i] = rgb;
		i++;
	}
	data->texture.C_color = new_color(cold[0], cold[1], cold[2], 0);
	printf("C: %d\n", data->texture.C_color);
	free(cold);
	free_tab(tmp);
	return (true);
}

bool	fill_data(t_data *data, char **tab, char *no_dup)
{	

	bool	option;
	
	option = false;
	
	option = check_NO_fill(data, tab, no_dup) || \
	check_SO_fill(data, tab, no_dup) || \
	check_WE_fill(data, tab, no_dup) || \
	check_EA_fill(data, tab, no_dup) || \
	check_C_fill(data, tab, no_dup) || \
	check_F_fill(data, tab, no_dup);
	
	free_tab(tab);
	return (option);
}


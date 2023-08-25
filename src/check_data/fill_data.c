/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:57:58 by bberger           #+#    #+#             */
/*   Updated: 2023/08/24 19:00:16 by bberger          ###   ########.fr       */
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
	printf("test_F\n");	
	int		rgb;
	int		i;
	int		j;
	char	**tmp;

	if (ft_strncmp("F", tab[0], 1) || *no_dup & 16)//2^4 = 16
		return (false);
	*no_dup += 16;
	data->texture.F_color = pro_malloc(sizeof(int) * (3));
	if (!data->texture.F_color)
		return (false); 
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
		data->texture.F_color[i] = rgb;
		i++;
	}
	print_color(data->texture.F_color);
	free_tab(tmp);
	return (true);
}

bool	check_C_fill(t_data *data, char **tab, char *no_dup)
{
	printf("test_C\n");	
	int		rgb;
	int		i;
	int		j;
	char	**tmp;

	if (ft_strncmp("C", tab[0], 1) || *no_dup & 32)
		return (false);
	*no_dup += 32;
	data->texture.C_color = pro_malloc(sizeof(int) * (3));
	if (!data->texture.C_color)
		return (false); 
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
		data->texture.C_color[i] = rgb;
		i++;
	}
	print_color(data->texture.C_color);
	free_tab(tmp);
	return (true);
}

bool	fill_data(t_data *data, char **tab, char *no_dup)
{	

	bool	option;
	
	option = false;
	option = check_NO_fill(data, tab, no_dup) || check_SO_fill(data, tab, no_dup) || \
	check_WE_fill(data, tab, no_dup) || check_EA_fill(data, tab, no_dup) || \
	check_F_fill(data, tab, no_dup) || check_F_fill(data, tab, no_dup) || \
	check_C_fill(data, tab, no_dup);
	// if (check_NO_fill(data, tab, no_dup) == true)
	// 	bol += 1;
	// if (check_SO_fill(data, tab, no_dup) == true)
	// 	bol += 1; 
	// if (check_WE_fill(data, tab, no_dup) == true)
	// 	bol += 1;
	// if (check_EA_fill(data, tab, no_dup) == true)
	// 	bol += 1;
	// if (check_F_fill(data, tab, no_dup) == true)
	// 	bol += 1;
	// if (check_C_fill(data, tab, no_dup) == true)
	// 	bol += 1;
	if (option  == true)
		printf("true\n");
	else
		printf("false\n");
	free_tab(tab);
	return (option);
}


// bool	fill_data(t_data *data, char **tab, char *no_dup)
// {	
// 	if (check_NO_fill(data, tab, no_dup) == false || check_SO_fill(data, tab, no_dup) == false || \
// 	check_WE_fill(data, tab, no_dup) == false || check_EA_fill(data, tab, no_dup) == false || \
// 	check_F_fill(data, tab, no_dup) == false || check_C_fill(data, tab, no_dup) == false)
// 		return (false);
// 	free_tab(tab);
// 	return (true);
// }


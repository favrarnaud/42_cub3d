/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:43:39 by bberger           #+#    #+#             */
/*   Updated: 2023/08/25 17:39:22 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verify_map(t_data *data)
{
	if (check_char_dup(data) == -1)
		return (-1);
	if (check_closed_map(data) == -1)
		return (-1);
	return (0);
}

void	fill_tab_x(char **map, int tab_len, int len)
{
	int	x;
	int y;

	y = 0;
	while(y < tab_len)
	{
		map[y] = pro_malloc((len + 1) * (sizeof(char)));
		x = 0;
		while(x < len)
		{
			map[y][x] = 'x';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
}

void	fill_map(char **map, char **tab_tmp, int h_len)
{
	int	y;
	int x;

	y = 1;
	while (y < h_len - 1)
	{
		x = 1;
		while (map[y][x] && tab_tmp[y-1][x-1])
		{
			if (tab_tmp[y-1][x-1] != 'x' && tab_tmp[y-1][x-1] != ' ')
				map[y][x] = tab_tmp[y-1][x-1];
			x++;
		}
		y++;
	}
}

int	longest_str(char **tab_tmp)
{
	int i;
	size_t max_len;

	i = 0;
	max_len = ft_strlen(tab_tmp[i]);
	while (tab_tmp[i])
	{
		if (ft_strlen(tab_tmp[i+1]) >= max_len)
			max_len = ft_strlen(tab_tmp[i+1]);
		i++; 
	}
	return ((int)max_len);
}

int		check_map(t_data *data, int fd, char *fstr)
{
	char	*tmp;
	char	*tmp2;
	char	**tab_tmp;
	char	*str;
	
	tmp = NULL;
	str = ft_strdup(fstr);
	free(fstr);
	while (str && !empty_line(str))
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str)
	{
		if (divided_line(str) == -1)
			return (-1);
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, str);
		free(tmp2);
		free(str);
		str = get_next_line(fd);
	}
	tab_tmp = ft_split(tmp, '\n');
	free(tmp);

	data->map.height = tab_size(tab_tmp) + 2;
	data->map.width = longest_str(tab_tmp) + 2;
	data->map.map = pro_malloc((data->map.height + 1) * (sizeof(char *)));
	fill_tab_x(data->map.map, data->map.height, data->map.width);
	fill_map(data->map.map, tab_tmp, data->map.height);
	return (verify_map(data));
}

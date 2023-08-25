/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:37:22 by bberger           #+#    #+#             */
/*   Updated: 2023/08/25 12:59:10 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// replace \n at the end of each string of the tab by \0
char **replace_last_char(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '\n')
				tab[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (tab);
}

// check if file is a .cub file
int	check_cub_file(char *str)
{
	if (ft_strlen(str) < 5)
		return (1);
	else if (ft_strncmp(&str[ft_strlen(str) - 4], ".cub", 4) != 0)
		return (2);
	return (0);
}

// check if file is a .cub + open it
int	ft_check_av(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf("Arg must be the path + name of a .cub file!");
		return (-2);
	}
	if (check_cub_file(av[1]) != 0)
	{
		printf("Arg must be a .cub file!");
		return (-3);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		printf("File could not be openned!");
	return (fd);
}



//  set 3 tabs (1. chemin des textures, 2.couleurs du floor, 3. map)
bool	set_tabs(t_data *data, int fd)
{
	char	*str;
	char	**tab;
	char	no_dup;
	int i = 2;

	no_dup = 0;
	str = get_next_line(fd);
	//vire \n de str : str[ft_strlen(str) - 2] = '\0';
	while (str)
	{
		if (empty_line(str) && no_dup != 63) // recolte  la non map
		{
			printf("bouh\n");
			tab = ft_split(str, ' ');
			replace_last_char(tab);
			if (tab_size(tab) != 2)
			{
				free(str);
				free_tab(tab);
				return (false);
			}
			if (!fill_data(data, tab, &no_dup))
				return (false);
		}
		printf("%s %d %d\n", str, i++, no_dup);
		free(str);
		if (no_dup == 63)
			break ;
		str = get_next_line(fd);
		//vire \n de str : str[ft_strlen(str) - 2] = '\0';
	}
	printf("check_Map\n");
	return (check_map(data, fd));
}

// check av and init map
int	read_input(int ac, char **av, t_data *data)
{
	int		fd;
	
	fd = ft_check_av(ac, av);
	if (fd < 0)
		return (fd);
	else if(set_tabs(data, fd) == false)
		return (-4);
	return (0);
}


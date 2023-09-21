/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:37:22 by bberger           #+#    #+#             */
/*   Updated: 2023/08/25 15:08:17 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**replace_last_char(char **tab)
{
	int	i;
	int	j;

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

int	set_tabs(t_data *data, int fd)
{
	char	*str;
	char	**tab;

	str = get_next_line(fd);
	while (str)
	{
		if (check_inside(data, str, tab) != 0)
			return (-1);
		free(str);
		if (check_dbstruct(data) == 6)
			break ;
		str = get_next_line(fd);
	}
	if (check_dbstruct(data) != 6)
		return (print_error("Parametres manquant"));
	str = get_next_line(fd);
	if (str && str[0] != ' ' && str[0] != '1' && str[0] != '\n')
		return (printf("doublon dans %c%c\n", str[0], str[1]));
	return (check_map(data, fd, str));
}

int	read_input(int ac, char **av, t_data *data)
{
	int		fd;

	fd = ft_check_av(ac, av);
	if (fd < 0)
		return (fd);
	else if (set_tabs(data, fd) == -1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:47:41 by afavre            #+#    #+#             */
/*   Updated: 2023/09/21 16:47:43 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_inside(t_data *data, char *str, char **tab)
{
	if (empty_line(str))
	{
		tab = ft_split(str, ' ');
		if (check_line_start(tab) == -1)
			return (print_error("Ligne invalide dans la map"));
		replace_last_char(tab);
		if (tab_size(tab) != 2)
		{
			free(str);
			free_tab(tab);
			return (print_error("Incorrect informations format"));
		}
		if (fill_data(data, tab) == -1)
			return (-1);
	}
	return (0);
}

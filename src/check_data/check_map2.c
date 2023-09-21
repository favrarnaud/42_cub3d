/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:11:24 by afavre            #+#    #+#             */
/*   Updated: 2023/09/21 15:11:26 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map_info(t_data *data, char ***tab_tmp, char **tmp)
{
	*tab_tmp = ft_split(*tmp, '\n');
	data->map.height = tab_size(*tab_tmp) + 2;
	data->map.width = longest_str(*tab_tmp) + 2;
	data->map.map = pro_malloc((data->map.height + 1) * (sizeof(char *)));
	fill_tab_x(data->map.map, data->map.height, data->map.width);
	fill_map(data->map.map, *tab_tmp, data->map.height);
}

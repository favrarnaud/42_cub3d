/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:03:07 by afavre            #+#    #+#             */
/*   Updated: 2023/08/25 17:00:26 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

#include <stdio.h>
#include <math.h>

#include "../libs/libft/gnl/include/get_next_line.h"
#include "../libs/libft/libft/include/libft.h"
#include "../libs/miniLibX/mlx.h"
#include "key.h"

#define bool _Bool
#define true 1
#define false 0

typedef enum
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE
}	wall_face;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_vec {
	float x;
	float y;
}	t_vec;

typedef struct s_ray {
	float	x;
	float 	y;
	float	fov;
	float	limit;
	float 	precision;
	float	angle;
	int		half_height;

}	t_ray;

typedef struct s_map {
	char **map;
	int  **tab;
	int  h_map;
	int  l_map;
	int	map_size;
}	t_map;

typedef struct s_mlx {
	void *ptr;
	void *win;
	int screen_width;
	int screen_height;
}	t_mlx;

typedef struct s_texture
{
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	int		*F_color;
	int		*C_color;
	
}	t_texture;

typedef struct s_data {
	t_mlx 		mlx;
	t_map 		map;
	t_ray 		ray;
	t_img 		img;
	t_texture	texture;
	
}	t_data;

// ---> MLX
//init_mlx.c
void	init_mlx(t_data *data);
//handler.c
void	init_event(t_data *data);
//draw.c
void	init_img(t_data *data);
void	update_img(t_data *data);

// --> CHECK_DATA
//read_input.c
int		read_input(int ac, char **av, t_data *data);

// fill_data.c
bool	fill_data(t_data *data, char **tab, char *no_dup);

// data_utils.c
int		empty_line(char *str);
void	free_tab(char **tab);
int		tab_size(char **tab);

// check_texture.c
bool	check_NO_fill(t_data *data, char **tab, char *no_dup);
bool	check_SO_fill(t_data *data, char **tab, char *no_dup);
bool	check_WE_fill(t_data *data, char **tab, char *no_dup);
bool	check_EA_fill(t_data *data, char **tab, char *no_dup);

// check_map.c
bool	check_map(t_data *data, int fd);

// map_utils.c
bool	check_char_dup(char **map, int *dup);
bool	check_closed_map(t_data *data);

// free_data.c
void	free_all(t_data *data);

// --> DATA
//init_data.c
int		init_data(t_data *data);

// ---> DEBUG
//map.c
void	gen_map(t_data *data);
void	clear_map(t_data *data);
void	print_map(t_data *data);
//vector.c
void	print_vector(t_vec *vec);

// ---> UTILS
//radians.c
double	degree_to_radians(float degree);
//tab.c
void	print_int_tab(int *tab);
void	print_char_tab(char **tab);
void	print_map(t_data *data);

//draw_utils.c
int		new_color(int r, int g, int b, int a);
void	render_rect(t_data *data, int x, int y, int height, int width, int color);
void	render_line(t_data *data, int col, int start, int end, int color);
//float_utils.c
char	*ftoa(float n, char* res, int afterpoint);
// malloc.c
void *pro_malloc(size_t size);

// ---> RAYCAST
//ray.c
void	ray_casting(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:03:07 by afavre            #+#    #+#             */
/*   Updated: 2023/09/19 14:08:41 by bberger          ###   ########.fr       */
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

typedef enum
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE
}	wall_face;

typedef struct s_player
{
	double posX;
	double posY;
}	t_player;

typedef struct s_nodb
{
	int north;
	int south;
	int east;
	int west;
	int floor;
	int ceilling;
} t_nodb;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map {
	char **map;
	int  **tab;
	int  height;
	int  width;
}	t_map;

typedef struct s_mlx {
	void *ptr;
	void *win;
	int screen_width;
	int screen_height;
}	t_mlx;

typedef struct s_texture
{
	t_nodb 	no_dup;
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	int		F_color;
	int		C_color;
}	t_texture;

typedef struct s_cam
{
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double rot_speed;
}	t_cam;

typedef struct s_data {
	t_mlx 		mlx;
	t_map 		map;
	t_img 		img;
	t_player	player;
	t_cam		cam;
	t_texture	texture;
}	t_data;

// ---> MLX
//init_mlx.c
void	init_mlx(t_data *data);
//handler.c
void	init_event(t_data *data);
//draw.c
void	draw_background(t_data *data);
void	update_img(t_data *data);

// --> CHECK_DATA
//read_input.c
int		read_input(int ac, char **av, t_data *data);

// fill_data.c
int	check_dbstruct(t_data *data);
int	fill_data(t_data *data, char **tab);

// data_utils.c
int		empty_line(char *str);
void	free_tab(char **tab);
int		tab_size(char **tab);

// check_texture.c
int	check_NO_fill(t_data *data, char **tab);
int	check_SO_fill(t_data *data, char **tab);
int	check_WE_fill(t_data *data, char **tab);
int	check_EA_fill(t_data *data, char **tab);

// check_map.c
int		check_map(t_data *data, int fd, char *fstr);

// map_utils.c
int	check_char_dup(t_data *data);
int	check_closed_map(t_data *data);
int	Check_line_start(char **tab);

// free_data.c
void	free_int_tab(int **tab);
void	free_all(t_data *data);

// read_utils.c
int	divided_line(char *str);

// error.c
int	print_error(char *msg);

// --> DATA
//init_data.c
void		init_data(t_data *data);

// ---> UTILS
//ray_utils.c
double	degree_to_radians(float degree);

//tab.c
void	print_map(t_data *data);


//draw_utils.c
int		new_color(int r, int g, int b, int a);
void	add_pixel(t_data *data, t_img *img, int x, int y, int color);
void	render_rect(t_data *data, int x, int y, int height, int width, int color);
void	render_line(t_data *data, int col, int start, int end, int color);

// malloc.c
void *pro_malloc(size_t size);

// TODO remove this debug
// ---TEST ---> DEBUG
void test(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:03:07 by afavre            #+#    #+#             */
/*   Updated: 2023/09/22 15:30:44 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>

# include "../libs/libft/gnl/include/get_next_line.h"
# include "../libs/libft/libft/include/libft.h"
# include "../libs/miniLibX/mlx.h"
# include "key.h"

typedef enum t_face
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE
}	t_wall_face;

typedef struct s_trash
{
	int			dup;
	int 		tx;
	int 		ty;
}	t_trash;

typedef struct s_point
{
	double		x;
	double		y;
}	t_point;

typedef struct s_rect
{
	double		height;
	double		width;
}	t_rect;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
}	t_player;

typedef struct s_nodb
{
	int			north;
	int			south;
	int			east;
	int			west;
	int			floor;
	int			ceilling;
}	t_nodb;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_map {
	char		**map;
	int			**tab;
	int			height;
	int			width;
}	t_map;

typedef struct s_mlx {
	void		*ptr;
	void		*win;
	int			screen_width;
	int			screen_height;
}	t_mlx;

typedef struct s_texture
{
	t_nodb		no_dup;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			f_color;
	int			c_color;
}	t_texture;

typedef struct s_cam
{
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		r_sp;
	double		m_sp;
}	t_cam;

typedef struct s_raycast
{
	int x;
	int	h;
	int	w;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	t_point t;
	t_wall_face	wall;	
}	t_raycast;

typedef struct s_data {
	t_mlx		mlx;
	t_map		map;
	t_img		img;
	t_player	player;
	t_cam		cam;
	t_texture	texture;
	t_raycast	raycast;
	t_trash		trash;
}	t_data;

// ---> MLX
//init_mlx.c
void	init_mlx(t_data *data);

//handler.c
void	init_event(t_data *data);

// key_movement.c

void	devant(t_data *data);
void	derriere(t_data *data);
void	moonwalk_gauche(t_data *data);
void	moonwalk_droit(t_data *data);

//key_rotation.c
void	la_gauche(t_data *data);
void	la_droite(t_data *data);

//draw.c
void	draw_background(t_data *data);
void	update_img(t_data *data);

// --> CHECK_DATA
//read_input.c
char	**replace_last_char(char **tab);
int		read_input(int ac, char **av, t_data *data);

// read_input2.c
int		check_inside(t_data *data, char *str, char **tab);

// fill_data.c
int		check_dbstruct(t_data *data);
int		fill_data(t_data *data, char **tab);

// data_utils.c
int		empty_line(char *str);
void	free_tab(char **tab);
int		tab_size(char **tab);

// check_texture.c
int		check_no_fill(t_data *data, char **tab);
int		check_so_fill(t_data *data, char **tab);
int		check_we_fill(t_data *data, char **tab);
int		check_ea_fill(t_data *data, char **tab);

// check_map.c
void	fill_tab_x(char **map, int tab_len, int len);
void	fill_map(char **map, char **tab_tmp, int h_len);
int		longest_str(char **tab_tmp);
int		check_map(t_data *data, int fd, char *fstr);

// check_map2.c
void	set_map_info(t_data *data, char ***tab_tmp, char **tmp);

// map_utils.c
int		check_char_dup(t_data *data);
int		check_closed_map(t_data *data);
int		check_line_start(char **tab);

// map_utils2.c
void	set_orientation(t_data *data, char c);

// free_data.c
void	free_all(t_data *data);

// read_utils.c
int		divided_line(char *str);

// error.c
int		print_error(char *msg);

// --> DATA
//init_data.c
void	init_data(t_data *data);

// ---> UTILS

//tab.c
void	print_map(t_data *data);

//draw_utils.c
int		new_color(int r, int g, int b, int a);
void	add_pixel(t_data *data, int x, int y, int color);
void	render_rect(t_data *data, t_point t, t_rect rect, int color);
void	render_line(t_data *data, int col, t_point t, int color);

// malloc.c
void	*pro_malloc(size_t size);

// --> RAYCAST
//main_raycast.c
void	raycast(t_data *data);

//raycast_utils.c
void	phase1(t_data *data);
void	phase2(t_data *data);
void	phase3(t_data *data);
void	phase4(t_data *data);
t_wall_face	get_face(t_data *data);

//color_utils.c
int		get_color(t_data *data);
#endif

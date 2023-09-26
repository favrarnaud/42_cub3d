/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:23:18 by afavre            #+#    #+#             */
/*   Updated: 2023/09/26 18:23:20 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

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

typedef struct s_tex_img
{
	void	*img;
	int		img_width;
	int 	img_height;
} t_t_img;

typedef struct s_texture
{
	t_nodb		no_dup;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			f_color;
	int			c_color;
	t_t_img		no_tex;
	t_t_img		so_tex;
	t_t_img		we_tex;
	t_t_img		ea_tex;
	t_img		no_data;
	t_img		so_data;
	t_img		ea_data;
	t_img		we_data;

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
	int	oldX;
	int oldY;
	int oldface;
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

typedef struct s_texture_load
{
	void **img;
	char *path;
	t_img *img_data;
	t_t_img *tex_data;
} t_texture_load;

typedef struct s_block
{
	int width;
	int *height;
	int height_len;

}	t_block;

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

#endif

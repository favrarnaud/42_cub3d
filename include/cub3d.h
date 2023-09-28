/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberger <bberger@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:03:07 by afavre            #+#    #+#             */
/*   Updated: 2023/09/22 16:40:11 by bberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>

# include "../libs/libft/gnl/include/get_next_line.h"
# include "../libs/libft/libft/include/libft.h"
# include "../libs/miniLibX/mlx.h"
# include "define.h"
# include "struct.h"

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
void	free_char_tab(char **tab);

// map_utils.c
int		check_char_dup(t_data *data);
int		check_closed_map(t_data *data);
int		check_line_start(char **tab);

// map_utils2.c
void	set_orientation(t_data *data, char c);

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
int		get_pixel_color(t_img *image, int x, int y);
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

// raycast_utils2.c
void	phase0(t_data *data);
void	phasem1(t_data *data);

// block_utils.c

int		pixtur(t_data *data, double tx, double ty);
void	draw_col(t_data *data);

//color_utils.c
int		get_color(t_data *data);

//init_textures.c
void	init_tex(t_data *data);

//block_utils.c
void	init_block(t_block *block);
void	add_height(t_block *block, int new_height);
void	add_width(t_block *block, int new_width);
void	add_face(t_block *block, int new_face);
void	free_all(t_data *data);

//debug.c
void	print_block_info(t_block *block);
void	print_int_tab(int *test, int size);
void	test(t_data *data);

#endif

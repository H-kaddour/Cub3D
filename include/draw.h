/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:19:56 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/21 14:30:24 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "cub3d.h"

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	x_next;
	double	y_next;
	double	angle;
	int		x_index_map;
	int		y_index_map;
	//int	ply_x_pos;
	//int	ply_y_pos;
	double	ply_x_pos;
	double	ply_y_pos;

	double	x1;
	double	y1;
	//int	ply_x_index;
	//int	ply_y_index;
} t_coord;

typedef	struct	s_keys
{
	int	key_up;
	int	key_down;
	int	key_right;
	int	key_left;
	int	rot_lft;
	int	rot_rght;
	int	view_up;
	int	view_down;
	int	chk_mlx_loop;
} t_keys;

typedef struct s_camera
{
	double	ray_angle;

	double	x_horizontal;
	double	y_horizontal;
	double	x_vertical;
	double	y_vertical;

	double	dist_vert;
	double	dist_horz;

	int		chk_if_horz;
	int		chk_if_vert;

	double	x_step;
	double	y_step;

	//projection
	double	ray_dist;
	double	dist_ply_proj;
	double	proj_wall;

	double	start_wall;
	double	end_wall;

	double	view_up_down;

	//this for texture
	double	offset_x;
	double	offset_y;
	//int		sight;
} t_cam;

typedef struct image_utils
{
	void	*img;
	char	*addr;
	unsigned int	*addr2;
	int		bpp;
	int		size_line;
	int		endian;
} t_img;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:19:56 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/06 18:24:39 by hkaddour         ###   ########.fr       */
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
	//int	ply_x_index;
	//int	ply_y_index;
} t_coord;

//typedef struct s_camera
//{
//	//int	ply_x_move;
//	//int	ply_y_move;
//} t_cam;

typedef struct image_utils
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
} t_img;

#endif

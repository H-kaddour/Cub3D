/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:19:56 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/16 17:47:17 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "cub3d.h"

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	ply_x_pos;
	int	ply_y_pos;
	int	ply_x_index;
	int	ply_y_index;
} t_coord;

typedef struct key_move
{
	int	ply_x_move;
	int	ply_y_move;
} t_key_move;

typedef struct image_utils
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
} t_img;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:56:21 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 12:32:48 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	mini_map_draw(t_data *data)
{
	int	hld_x;
	int	hld_y;
	int	x1;
	int	y1;
	int	x;
	int	y;
	int	start_x;
	int	start_y;
	int	ply_x;
	int	ply_y;
	int	end_x;
	int	end_y;

	hld_x = (int)(floor(data->draw_utils->ply_x_pos) / SQR_SIZE);
	hld_y = (int)(floor(data->draw_utils->ply_y_pos) / SQR_SIZE);
	y = (int)(floor(data->draw_utils->ply_y_pos) / SQR_SIZE) * 10;
	x = (int)(floor(data->draw_utils->ply_x_pos) / SQR_SIZE) * 10;
	//mlx_put_pixel_to_img(data, 350, 350, 0xffffff);
	//return ;

	start_x = x - (340 / 2);
	ply_x = start_x + (340 / 2);
	if (start_x < 0)
	{
		//ply_x = abs(start_x);
		ply_x = (340 / 2);
		start_x = 0;
	}
	end_x = start_x + 340;
	if (end_x >= data->map->width * 10)
		end_x = data->map->width * 10;
	start_y = y - (200 / 2);
	ply_y = start_y + (200 / 2);
	if (start_y < 0)
	{
		ply_y = (200/ 2) ;
		//ply_y = abs(start_y);
		start_y = 0;
	}
	end_y = start_y + 200;
	if (end_y >= data->map->height * 10)
		end_y = data->map->height * 10;
	y = start_y;
	y1 = 0;
	while (y < end_y)
	{
		x = start_x;
		x1 = 0;
		while (x < end_x)
		{
			if (data->map->map[y / 10][x / 10] == '1')
				mlx_put_pixel_to_img(data, x1, y1, 0xAA5656);
			if (data->map->map[y / 10][x / 10] == '0' \
					|| data->map->map[y / 10][x / 10] == data->map->player)
				mlx_put_pixel_to_img(data, x1, y1, 0xFFFBEB);
			x++;
			x1++;
		}
		y++;
		y1++;
	}
	ply_x = (int)(floor(data->draw_utils->ply_x_pos) / SQR_SIZE) * 10;
	ply_y = (int)(floor(data->draw_utils->ply_y_pos) / SQR_SIZE) * 10;
	y = start_y;
	y1 = 0;
	while (y < end_y)
	{
		x = start_x;
		x1 = 0;
		while (x < end_x)
		{
			if (x == ply_x && y == ply_y)
			{
				ply_x = x1;
				ply_y = y1;
				break ;
			}
			x++;
			x1++;
		}
		y++;
		y1++;
	}
	//draw player and ray
	data->draw_utils->x = ply_x + 5;
	data->draw_utils->y = ply_y + 5;
  data->draw_utils->x_next = data->draw_utils->x + cos(data->draw_utils->angle) * 20;
  data->draw_utils->y_next = data->draw_utils->y + sin(data->draw_utils->angle) * 20;
	dda(data, 0xff0000);
	x1 = ply_x;
	while (x1 < ply_x + 10)
	{
		y1 = ply_y;
		while (y1 < ply_y + 10)
			mlx_put_pixel_to_img(data, x1, y1++, 0x698269);
		x1++;
	}
}

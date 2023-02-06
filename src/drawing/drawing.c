/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:39 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/06 19:04:48 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	catch_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == data->map->player)
			{
				//data->draw_utils->ply_x_index = j * SQR_SIZE;
				//data->draw_utils->ply_y_index = i * SQR_SIZE;
				data->draw_utils->ply_x_pos = j * SQR_SIZE;
				data->draw_utils->ply_y_pos = i * SQR_SIZE;
			}
			j++;
		}
		i++;
	}
}

static int	color_desision(t_data *data, int i, int x, int chk)
{
	int	clr;

	//empty place and player
	if (!chk)
	{
		if (i == 0 || i == SQR_SIZE - 1)
			clr = 0xD6E4E5;
		else if (x == data->draw_utils->x || x == (data->draw_utils->x + SQR_SIZE) - 1)
			clr = 0xD6E4E5;
		else
			clr = 0xFBFACD;
	}
	//walls
	else
	{
		if (i == 0 || i == SQR_SIZE - 1)
			clr = 0xFF8FB1;
		else if (x == data->draw_utils->x || x == (data->draw_utils->x + SQR_SIZE) - 1)
			clr = 0xFF8FB1;
		else
			clr = 0xBA94D1;
	}
	return (clr);
}

static void	draw_line(t_data *data, int chk)
{
	int	i;
	int	x;
	int	y;
	int	clr;

	i = 0;
	x = data->draw_utils->x;
	y = data->draw_utils->y;
	while (i < SQR_SIZE)
	{
		x = data->draw_utils->x;
		while (x < data->draw_utils->x + SQR_SIZE)
		{
			clr = color_desision(data, i, x, chk);
			mlx_put_pixel_to_img(data, x++, y, clr);
		}
		y++;
		i++;
	}
}

static void	draw_player(t_data *data)
{
	//int	x;
	//int	y;

	//data->draw_utils->ply_x_pos += 25;
	//data->draw_utils->ply_y_pos += 25;
	mlx_put_pixel_to_img(data, data->draw_utils->ply_x_pos, data->draw_utils->ply_y_pos, 0x000000);
	//y = data->draw_utils->ply_y_pos;
	//while (y < data->draw_utils->ply_y_pos + 30)
	//{
	//	x = data->draw_utils->ply_x_pos;
	//	while (x < data->draw_utils->ply_x_pos + 30)
	//	{
	//		mlx_put_pixel_to_img(data, x, y, 0x497174);
	//		//mlx_put_pixel_to_img(data, x, y, data->color->ceiling);
	//		x++;
	//	}
	//	y++;
	//}
}

static void	draw_border_of_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->draw_utils->y = 0;
	while (data->map->map[i])
	{
		j = 0;
		data->draw_utils->x = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] != 'D')
			{
				if (data->map->map[i][j] == '1')
					draw_line(data, 1);
				else
					draw_line(data, 0);
			}
			data->draw_utils->x += SQR_SIZE;
			j++;
		}
		data->draw_utils->y += SQR_SIZE;
		i++;
	}
}

void	einstein_drawing(t_data *data)
{
	make_and_init_image(data);
	draw_border_of_map(data);
	draw_rays(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, \
			data->mlx->utils->img, 0, 0);
}

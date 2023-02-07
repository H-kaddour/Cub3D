/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/07 22:06:40 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int close_win(t_data *data)
{
	printf("Window closed!\n");
	(void)data;
	exit(0);
}

int convert_rad2deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

void left_and_right(int key, t_data *data)
{
	if (key == LEFT || key == RIGHT)
	{
		if (key == RIGHT)
		{
			data->draw_utils->x_index_map = (int)floor((data->draw_utils->ply_x_pos - sin(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			data->draw_utils->y_index_map = (int)floor((data->draw_utils->ply_y_pos + cos(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			if (data->map->map[data->draw_utils->y_index_map][data->draw_utils->x_index_map] != '1')
			{
				data->draw_utils->ply_x_pos -= sin(data->draw_utils->angle) * 2.0;
				data->draw_utils->ply_y_pos += cos(data->draw_utils->angle) * 2.0;
			}
		}
		if (key == LEFT)
		{
			data->draw_utils->x_index_map = (int)floor((data->draw_utils->ply_x_pos +\
				sin(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			data->draw_utils->y_index_map = (int)floor((data->draw_utils->ply_y_pos -\
				cos(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			if (data->map->map[data->draw_utils->y_index_map][data->draw_utils->x_index_map] != '1')
			{
				data->draw_utils->ply_x_pos += sin(data->draw_utils->angle) * 2.0;
				data->draw_utils->ply_y_pos -= cos(data->draw_utils->angle) * 2.0;
			}
		}
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
}

void up_and_down(int key, t_data *data)
{
	if (key == UP || key == DOWN)
	{
		if (key == UP)
		{
			data->draw_utils->x_index_map = (int)floor((data->draw_utils->ply_x_pos + cos(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			data->draw_utils->y_index_map = (int)floor((data->draw_utils->ply_y_pos + sin(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			if (data->map->map[data->draw_utils->y_index_map][data->draw_utils->x_index_map] != '1')
			{
				data->draw_utils->ply_x_pos += cos(data->draw_utils->angle) * 2.0;
				data->draw_utils->ply_y_pos += sin(data->draw_utils->angle) * 2.0;
			}
			else
				return;
		}
		if (key == DOWN)
		{
			data->draw_utils->x_index_map = (int)floor((data->draw_utils->ply_x_pos -\
				cos(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			data->draw_utils->y_index_map = (int)floor((data->draw_utils->ply_y_pos -\
				sin(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			if (data->map->map[data->draw_utils->y_index_map][data->draw_utils->x_index_map] != '1')
			{
				data->draw_utils->ply_x_pos -= cos(data->draw_utils->angle) * 2.0;
				data->draw_utils->ply_y_pos -= sin(data->draw_utils->angle) * 2.0;
			}
		}
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
}

double limite_angle(double angle)
{
	angle = fmod(angle , M_PI * 2);
	if (angle < 0)
		angle += M_PI * 2;
	return (angle);
}

int keys(int key, t_data *data)
{
	if (key == ESC)
		close_win(data);
	left_and_right(key, data);
	up_and_down(key, data);
	data->draw_utils->angle = limite_angle(data->draw_utils->angle);
	if (key == ROT_RIGHT)
	{
		data->draw_utils->angle -= 5.0 * (M_PI / 180);
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
	if (key == ROT_LEFT)
	{
		data->draw_utils->angle += 5.0 * (M_PI / 180);
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
	return (0);
}

void window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Cub3D");
	// i have to make an init function for drawing and init angle depend on the player sight
	data->draw_utils->angle = 3 * M_PI / 2;
	// data->draw_utils->angle = 0;
	catch_player_pos(data);
	data->draw_utils->ply_x_pos += 25;
	data->draw_utils->ply_y_pos += 25;
	// printf("%f\n", data->draw_utils->ply_x_pos);
	// printf("%f\n", data->draw_utils->ply_y_pos);
	einstein_drawing(data);
	mlx_hook(data->mlx->win, 17, 1L << 0, close_win, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, keys, data);
	mlx_loop(data->mlx->init);
}

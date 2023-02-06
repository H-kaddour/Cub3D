/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/06 19:19:17 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_win(t_data *data)
{
	printf("Window closed!\n");
	(void)data;
	//free_all(data);
	exit(0);
}

double convert_rad2deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

int	keys(int key, t_data *data)
{
	//if (data->draw_utils->angle %)
	printf("%f\n", data->draw_utils->angle);
	//if (data->draw_utils->angle == (2 * M_PI))
	//{
	//	data->draw_utils->angle = 0;
	//	printf("ok");
	//}
	if (key == ESC)
		close_win(data);
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
			data->draw_utils->x_index_map = (int)floor((data->draw_utils->ply_x_pos + sin(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			data->draw_utils->y_index_map = (int)floor((data->draw_utils->ply_y_pos - cos(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			if (data->map->map[data->draw_utils->y_index_map][data->draw_utils->x_index_map] != '1')
			{
				data->draw_utils->ply_x_pos += sin(data->draw_utils->angle) * 2.0;
				data->draw_utils->ply_y_pos -= cos(data->draw_utils->angle) * 2.0;
			}
		}
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
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
				return (0);
		}
		if (key == DOWN)
		{
			data->draw_utils->x_index_map = (int)floor((data->draw_utils->ply_x_pos - cos(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			data->draw_utils->y_index_map = (int)floor((data->draw_utils->ply_y_pos - sin(data->draw_utils->angle) * 2.0) / SQR_SIZE);
			if (data->map->map[data->draw_utils->y_index_map][data->draw_utils->x_index_map] != '1')
			{
				data->draw_utils->ply_x_pos -= cos(data->draw_utils->angle) * 2.0;
				data->draw_utils->ply_y_pos -= sin(data->draw_utils->angle) * 2.0;
			}
		}
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
	printf("%f\n", (data->draw_utils->angle * (180 / M_PI)));
	//if ((int)(data->draw_utils->angle * (180 / M_PI)) == 360)
	//	printf("**ok***\n");
	if (convert_rad2deg(data->draw_utils->angle) == 0)
	{
		printf("ok \n");
	}
	if (key == ROT_RIGHT)
	{
		data->draw_utils->angle -=  5.0 * (M_PI/180);
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
	if (key == ROT_LEFT)
	{
		data->draw_utils->angle +=  5.0 * (M_PI/180);
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
	return (0);
}

void	window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Cub3D");
	//i have to make an init function for drawing and init angle depend on the player sight
	data->draw_utils->angle = 3 * M_PI / 2;
	//data->draw_utils->angle = 0;
	catch_player_pos(data);
	data->draw_utils->ply_x_pos += 25;
	data->draw_utils->ply_y_pos += 25;
	//printf("%f\n", data->draw_utils->ply_x_pos);
	//printf("%f\n", data->draw_utils->ply_y_pos);
	einstein_drawing(data);
	mlx_hook(data->mlx->win, 17, 1L<<0, close_win, data);
	mlx_hook(data->mlx->win, 2, 1L<<0, keys, data);
	mlx_loop(data->mlx->init);
}

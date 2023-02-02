/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/02 14:43:03 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_win(t_data *data)
{
	printf("Window closed!\n");
	free_all(data);
	exit(0);
}

int	keys(int key, t_data *data)
{
	if (key == ESC)
		close_win(data);
	if (key == RIGHT)
	{
		if (data->map->map[((data->draw_utils->ply_y_pos) + 20) / SQR_SIZE]\
				[((data->draw_utils->ply_x_pos + 10) + 20) / SQR_SIZE] != '1')
		{
			data->draw_utils->ply_x_pos += 10;
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
		}
	}
	if (key == LEFT)
	{

		if (data->map->map[((data->draw_utils->ply_y_pos) + 20) / SQR_SIZE]\
				[((data->draw_utils->ply_x_pos - 10) + 20) / SQR_SIZE] != '1')
		{
			data->draw_utils->ply_x_pos -= 10;
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
		}
	}
	if (key == UP)
	{
		if (data->map->map[((data->draw_utils->ply_y_pos - 10) + 20) / SQR_SIZE]\
				[((data->draw_utils->ply_x_pos) + 20) / SQR_SIZE] != '1')
		{
			data->draw_utils->ply_y_pos -= 10;
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
		}
	}
	if (key == DOWN)
	{
		if (data->map->map[((data->draw_utils->ply_y_pos + 10) + 20) / SQR_SIZE]\
				[((data->draw_utils->ply_x_pos) + 20) / SQR_SIZE] != '1')
		{
			data->draw_utils->ply_y_pos += 10;
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
		}
	}
	return (0);
}

void	window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Cub3D");
	catch_player_pos(data);
	einstein_drawing(data);
	mlx_hook(data->mlx->win, 17, 1L<<0, close_win, data);
	mlx_hook(data->mlx->win, 2, 1L<<0, keys, data);
	mlx_loop(data->mlx->init);
}

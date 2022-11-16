/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/16 21:26:10 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_win(void)
{
	printf("Window closed!\n");
	exit(0);
}

int	keys(int key, t_data *data)
{
	//w == 13
	//s == 1
	//d == 2
	//a == 0

	//printf("%d\n", key);

	//mlx_clear_window(data->mlx->init, data->mlx->win);
	if (key == 53)
		close_win();
	//if (key == 0)
	//{
	//	data->draw_utils->ply_x_pos -= 10;
	//	//data->key_mv->ply_x_move -= 10;
	//}
	if (key == 2)
	{
		if (data->map->map[((data->draw_utils->ply_y_pos) + 20) / 50]\
				[((data->draw_utils->ply_x_pos + 10) + 20) / 50] != '1')
		{
				data->draw_utils->ply_x_pos += 10;
			//mlx_clear_window(data->mlx->init, data->mlx->win);
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
		}
		//data->draw_utils->ply_x_pos += 10;
		//data->key_mv->ply_x_move += 10;
	}
	if (key == 0)
	{

		if (data->map->map[((data->draw_utils->ply_y_pos) + 20) / 50]\
				[((data->draw_utils->ply_x_pos - 10) + 20) / 50] != '1')
		{
				data->draw_utils->ply_x_pos -= 10;
			//mlx_clear_window(data->mlx->init, data->mlx->win);
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
		}
		//data->key_mv->ply_y_move -= 10;
	}
	if (key == 13)
	{

		if (data->map->map[((data->draw_utils->ply_y_pos - 10) + 20) / 50]\
				[((data->draw_utils->ply_x_pos) + 20) / 50] != '1')
		{
				data->draw_utils->ply_y_pos -= 10;
			//mlx_clear_window(data->mlx->init, data->mlx->win);
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
		}
		//data->key_mv->ply_y_move -= 10;
	}
	if (key == 1)
	{
		if (data->map->map[((data->draw_utils->ply_y_pos + 10) + 20) / 50]\
				[((data->draw_utils->ply_x_pos) + 20) / 50] != '1')
		{
				data->draw_utils->ply_y_pos += 10;
			//mlx_clear_window(data->mlx->init, data->mlx->win);
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
		}
		//data->draw_utils->ply_y_pos += 10;
		//data->key_mv->ply_y_move += 10;
	}
	//einstein_drawing(data);
	return (0);
}

int	loop(t_data *data)
{
	//printf("%d\n", key);
	einstein_drawing(data);
	//mlx_key_hook(data->mlx->win, keys, data);
	//mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
	//einstein_drawing(data);

	return (0);
}

void	window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Okay");
	catch_player_pos(data);
	einstein_drawing(data);
	//mlx_key_hook(data->mlx->win, keys, data);
	mlx_hook(data->mlx->win, 17, 1L<<0, close_win, data);
	mlx_hook(data->mlx->win, 2, 1L<<0, keys, data);
	//mlx_loop_hook(data->mlx->init, loop, data);
	mlx_loop(data->mlx->init);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2022/12/07 17:16:02 by hkaddour         ###   ########.fr       */
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
	//mac
	//w == 13
	//s == 1
	//d == 2
	//a == 0
	//escape == 53

	//linux
	//w == 119
	//s == 115
	//d == 100
	//a == 97
	//escape == 65307

	//printf("%d\n", key);

	//mlx_clear_window(data->mlx->init, data->mlx->win);
	if (key == 65307)
		close_win(data);
	//if (key == 0)
	//{
	//	data->draw_utils->ply_x_pos -= 10;
	//	//data->key_mv->ply_x_move -= 10;
	//}
	if (key == 100)
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
	if (key == 97)
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
	if (key == 119)
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
	if (key == 115)
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

//int	loop(t_data *data)
//{
//	//printf("%d\n", key);
//	einstein_drawing(data);
//	//mlx_key_hook(data->mlx->win, keys, data);
//	//mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
//	//einstein_drawing(data);
//
//	return (0);
//}

void	window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Cub3D");
	catch_player_pos(data);
	einstein_drawing(data);
	//mlx_key_hook(data->mlx->win, keys, data);
	mlx_hook(data->mlx->win, 17, 1L<<0, close_win, data);
	mlx_hook(data->mlx->win, 2, 1L<<0, keys, data);
	//mlx_loop_hook(data->mlx->init, loop, data);
	mlx_loop(data->mlx->init);
}

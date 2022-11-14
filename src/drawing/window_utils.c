/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/14 21:38:31 by hkaddour         ###   ########.fr       */
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
	printf("%d\n", key);
	if (key == 53)
		close_win();
	//a == 0
	if (key == 0)
	{
		data->draw_utils->ply_x_pos = 10;
		//data->draw_utils->ply_y_pos += 10;
		mlx_clear_window(data->mlx->init, data->mlx->win);
		einstein_drawing(data);

	}
	return (0);
}

void	window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Okay");
	einstein_drawing(data);
	mlx_key_hook(data->mlx->win, keys, data);
	mlx_hook(data->mlx->win, 17, 1L<<0, close_win, data);
	mlx_loop(data->mlx->init);
}

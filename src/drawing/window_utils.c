/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/18 20:31:13 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_win(t_data *data)
{
	printf("Window closed!\n");
	free_all(data);
	exit(0);
}

void	init_drawing_data(t_data *data)
{
	int	i;
	double	angle[4] = {0, (M_PI / 2), M_PI, (3 * M_PI/2)};
	char	sight[4] = {'E', 'N', 'W', 'S'};

	i = -1;
	while (sight[++i])
	{
		if (data->map->player == sight[i])
			data->draw_utils->angle = angle[i];
	}
	//ray angle 0 x go to inf
	//ray in 180 also get fucked
	//data->draw_utils->angle = convert_deg2rad(0 + 30);
	//data->draw_utils->angle = convert_deg2rad(0 + 30);
	//data->draw_utils->angle = convert_deg2rad(0);
	//this one init where the angle of the rays will be start
	if (data->draw_utils->angle == 0)
		data->ray->ray_angle = convert_deg2rad(360 - (FOV / 2));
	else
		data->ray->ray_angle = data->draw_utils->angle - convert_deg2rad(FOV / 2);
	//printf("ply_angle = %f\n", convert_rad2deg(data->draw_utils->angle));
	//printf("ray_angle = %f\n", convert_rad2deg(data->ray->ray_angle));
}

int	key_press(int key, t_data *data)
{
	data->key_mv->chk_mlx_loop = 1;
	if (key == UP)
		data->key_mv->key_up = 1;
	if (key == DOWN)
		data->key_mv->key_down = 1;
	if (key == RIGHT)
		data->key_mv->key_right = 1;
	if (key == LEFT)
		data->key_mv->key_left = 1;
	if (key == ROT_RIGHT)
		data->key_mv->rot_rght = 1;
	if (key == ROT_LEFT)
		data->key_mv->rot_lft = 1;
	if (key == ESC)
		close_win(data);
	//keys(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	data->key_mv->chk_mlx_loop = 0;
	if (key == UP)
		data->key_mv->key_up = 0;
	if (key == DOWN)
		data->key_mv->key_down = 0;
	if (key == RIGHT)
		data->key_mv->key_right = 0;
	if (key == LEFT)
		data->key_mv->key_left = 0;
	if (key == ROT_RIGHT)
		data->key_mv->rot_rght = 0;
	if (key == ROT_LEFT)
		data->key_mv->rot_lft = 0;
	return (0);
}

int	drawing_loop(t_data *data)
{
	if (data->key_mv->chk_mlx_loop)
		keys(data);
	return (0);
}

void	window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Cub3D");
	init_drawing_data(data);
	catch_player_pos(data);
	einstein_drawing(data);
	mlx_hook(data->mlx->win, 17, 1L<<0, close_win, data);
	mlx_hook(data->mlx->win, 2, 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 0, key_release, data);
	mlx_loop_hook(data->mlx->init, drawing_loop, data);
	mlx_loop(data->mlx->init);
}

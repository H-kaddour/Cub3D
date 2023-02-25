/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:47:49 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/25 19:56:36 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_win(t_data *data)
{
	printf("Window closed!\n");
	free_all(data);
	exit(0);
}

static void	init_drawing_data(t_data *data)
{
	if (data->map->player == 'E')
		data->draw_utils->angle = 0;
	else if (data->map->player == 'N')
		data->draw_utils->angle = M_PI / 2;
	else if (data->map->player == 'W')
		data->draw_utils->angle = M_PI;
	else if (data->map->player == 'S')
		data->draw_utils->angle = 3 * M_PI / 2;
	if ((int)round(convert_rad2deg(data->draw_utils->angle)) == 0)
		data->ray->ray_angle = convert_deg2rad(360 - (FOV / 2));
	else if ((int)round(convert_rad2deg(data->draw_utils->angle)) < 30)
		data->ray->ray_angle = convert_deg2rad(360 - \
			(fabs(convert_rad2deg(data->draw_utils->angle) - (FOV / 2))));
	else
		data->ray->ray_angle = \
			data->draw_utils->angle - convert_deg2rad(FOV / 2);
	data->ray->view_up_down = (WIN_H / 2);
	data->sp_mot = 3;
}

static int	move_ply_view(int x, int y, t_data *data)
{
	(void)y;
	if (x < (WIN_W / 2))
	{
		data->key_mv->rot_lft = 0;
		data->key_mv->rot_rght = 1;
	}
	else if (x > (WIN_W / 2))
	{
		data->key_mv->rot_lft = 1;
		data->key_mv->rot_rght = 0;
	}
	keys(data);
	data->key_mv->rot_lft = 0;
	data->key_mv->rot_rght = 0;
	mlx_mouse_move(data->mlx->win, (WIN_W / 2), WIN_H);
	mlx_mouse_hide();
	return (0);
}

void	window_init(t_data *data)
{
	data->mlx->init = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->init, WIN_W, WIN_H, "Cub3D");
	init_drawing_data(data);
	catch_player_pos(data);
	get_textures(data);
	sprite_init(data);
	einstein_drawing(data);
	mlx_hook(data->mlx->win, 17, 1L << 0, close_win, data);
	mlx_hook(data->mlx->win, 6, 0, move_ply_view, data);
	mlx_hook(data->mlx->win, 2, 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 0, key_release, data);
	mlx_loop_hook(data->mlx->init, keys, data);
	mlx_loop(data->mlx->init);
}

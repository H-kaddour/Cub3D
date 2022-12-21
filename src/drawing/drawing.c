/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:39 by hkaddour          #+#    #+#             */
/*   Updated: 2022/12/07 18:07:01 by hkaddour         ###   ########.fr       */
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
				data->draw_utils->ply_x_index = j * 50;
				data->draw_utils->ply_y_index = i * 50;

				data->draw_utils->ply_x_pos = j * 50;
				data->draw_utils->ply_y_pos = i * 50;
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
		else if (x == data->draw_utils->x || x == (data->draw_utils->x + 50) - 1)
			clr = 0xD6E4E5;
		else
			clr = 0xFBFACD;
	}
	//walls
	else
	{
		if (i == 0 || i == SQR_SIZE - 1)
			clr = 0xFF8FB1;
		else if (x == data->draw_utils->x || x == (data->draw_utils->x + 50) - 1)
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
	char    *dst;

	i = 0;
	x = data->draw_utils->x;
	y = data->draw_utils->y;
	while (i < SQR_SIZE)
	{
		x = data->draw_utils->x;
		while (x < data->draw_utils->x + SQR_SIZE)
		{
			clr = color_desision(data, i, x, chk);

			//dst = data->mlx->utils->addr + x * (data->mlx->utils->bpp / 8);
			//*(unsigned int *)dst = clr;
			//x++;

			mlx_put_pixel_to_img(data, x++, y, clr);
			//mlx_pixel_put(data->mlx->init, data->mlx->win, x++, \
			//		y, clr);
		}
		y++;
		i++;
	//return;
	}
}

//static void	draw_player(t_data *data)
//{
//	int	x;
//	int	y;
//
////	mlx_pixel_put(data->mlx->init, data->mlx->win, \
////			data->draw_utils->ply_x_pos, data->draw_utils->ply_y_pos, 0xffffff);
//
//	y = data->draw_utils->ply_y_pos + data->key_mv->ply_y_move + 20;
//	while (y < data->draw_utils->ply_y_pos + data->key_mv->ply_y_move + 30)
//	{
//		x = data->draw_utils->ply_x_pos + data->key_mv->ply_x_move + 20;
//		while (x < data->draw_utils->ply_x_pos + data->key_mv->ply_x_move + 30)
//		{
//			mlx_pixel_put(data->mlx->init, data->mlx->win, x, y, 0x497174);
//			x++;
//		}
//		y++;
//	}
//}

static void	draw_player(t_data *data)
{
	int	x;
	int	y;

	y = data->draw_utils->ply_y_pos + 20;
	while (y < data->draw_utils->ply_y_pos + 30)
	{
		x = data->draw_utils->ply_x_pos + 20;
		while (x < data->draw_utils->ply_x_pos + 30)
		{
			//mlx_pixel_put(data->mlx->init, data->mlx->win, x, y, 0x497174);
			mlx_put_pixel_to_img(data, x, y, 0x497174);
			x++;
		}
		y++;
	}
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
				//if (data->map->map[i][j] == data->map->player)
				//	draw_player(data);
				//return ;
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
	//catch_player_pos(data);
	make_and_init_image(data);
	draw_border_of_map(data);
	draw_player(data);
	draw_rays(data);
	mlx_put_image_to_window(data->mlx->init, data->mlx->win, \
			data->mlx->utils->img, 0, 0);
	//mlx_destroy_image(data->mlx->init, data->mlx->utils->img);



	//if ((data->draw_utils->ply_x_pos / 50) != data->draw_utils->ply_pos_w \
	//		&& (data->draw_utils->ply_y_pos / 50) != data->draw_utils->ply_pos_h)
	//	draw_player(data);

	//printf("%d\n", ((data->draw_utils->ply_x_pos - 10) + 20) / 50);
	//printf("%d\n", ((data->draw_utils->ply_y_pos - 10) + 20) / 50);

	//printf("%d\n", (data->draw_utils->ply_x_pos + 20) / 50);
	//printf("%d\n", (data->draw_utils->ply_y_pos + 20) / 50);

	//printf("%d\n", data->draw_utils->ply_x_pos - data->key_mv->ply_x_move);
	//printf("%d\n", data->draw_utils->ply_y_pos - data->key_mv->ply_y_move);
}

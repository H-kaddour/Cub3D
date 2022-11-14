/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:39 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/14 17:59:00 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	color_desision(t_data *data, int i, int x, int chk)
{
	int	clr;

	//empty place and player
	if (!chk)
	{
		if (i == 0 || i == 49)
			clr = 0xD6E4E5;
		else if (x == data->draw_utils->x || x == (data->draw_utils->x + 50) - 1)
			clr = 0xD6E4E5;
		else
			clr = 0xFBFACD;
	}
	//walls
	else
	{
		if (i == 0 || i == 49)
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

	i = 0;
	x = data->draw_utils->x;
	y = data->draw_utils->y;
	while (i < 50)
	{
		x = data->draw_utils->x;
		while (x < data->draw_utils->x + 50)
		{
			clr = color_desision(data, i, x, chk);
			mlx_pixel_put(data->mlx->init, data->mlx->win, x++, \
					y, clr);
		}
		y++;
		i++;
	}
}

static void	draw_player(t_data *data)
{
	int	x;
	int	y;

	y = data->draw_utils->y + 20;
	//x = data->draw_utils->x + 20;
	//mlx_pixel_put(data->mlx->init, data->mlx->win, x, y, 0x497174);
	while (y < data->draw_utils->y + 30)
	{
		x = data->draw_utils->x + 20;
		while (x < data->draw_utils->x + 30)
		{
			mlx_pixel_put(data->mlx->init, data->mlx->win, x, y, 0x497174);
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
				if (data->map->map[i][j] == data->map->player)
					draw_player(data);
				//return ;
			}
			data->draw_utils->x += 50;
			j++;
		}
		data->draw_utils->y += 50;
		i++;
	}
}

void	einstein_drawing(t_data *data)
{
	draw_border_of_map(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_strokes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:38:22 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/20 17:04:52 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	did_it_hit_the_wall(t_data *data, double coord1, double coord2)
{
	data->draw_utils->x_index_map = (int)floor(coord1 / SQR_SIZE);
	data->draw_utils->y_index_map = (int)floor(coord2 / SQR_SIZE);
	if (data->draw_utils->x_index_map < data->map->width && \
			data->draw_utils->y_index_map < data->map->height)
	{
		if (data->map->map[data->draw_utils->y_index_map] \
				[data->draw_utils->x_index_map] != '1')
			return (1);
	}
	return (0);
}

int	check_walls_right_left(t_data *data, int chk)
{
	double x;
	double y;

	if (!chk)
	{
		x = data->draw_utils->ply_x_pos - sin(data->draw_utils->angle) * SPEED;
		y = data->draw_utils->ply_y_pos + cos(data->draw_utils->angle) * SPEED;
	}
	else
	{
		x = data->draw_utils->ply_x_pos + sin(data->draw_utils->angle) * SPEED;
		y = data->draw_utils->ply_y_pos - cos(data->draw_utils->angle) * SPEED;
	}
	return (did_it_hit_the_wall(data, x, y) && \
		did_it_hit_the_wall(data, data->draw_utils->ply_x_pos, y) && \
		did_it_hit_the_wall(data, x, data->draw_utils->ply_y_pos));
}

int	check_walls_up_down(t_data *data, int chk)
{
	double x;
	double y;

	if (!chk)
	{
		x = data->draw_utils->ply_x_pos + cos(data->draw_utils->angle) * SPEED;
		y = data->draw_utils->ply_y_pos + sin(data->draw_utils->angle) * SPEED;
	}
	else
	{
		x = data->draw_utils->ply_x_pos - cos(data->draw_utils->angle) * SPEED;
		y = data->draw_utils->ply_y_pos - sin(data->draw_utils->angle) * SPEED;
	}
	return (did_it_hit_the_wall(data, x, y) && \
		did_it_hit_the_wall(data, data->draw_utils->ply_x_pos, y) && \
		did_it_hit_the_wall(data, x, data->draw_utils->ply_y_pos));
}

static int	left_right_key(t_data *data)
{
	if (data->key_mv->key_right)
	{
		if (check_walls_right_left(data, 0))
		{
			data->draw_utils->ply_x_pos -= sin(data->draw_utils->angle) * SPEED;
			data->draw_utils->ply_y_pos += cos(data->draw_utils->angle) * SPEED;
			return (1);
		}
	}
	if (data->key_mv->key_left)
	{
		if (check_walls_right_left(data, 1))
		{
			data->draw_utils->ply_x_pos += sin(data->draw_utils->angle) * SPEED;
			data->draw_utils->ply_y_pos -= cos(data->draw_utils->angle) * SPEED;
			return (1);
		}
	}
	return (0);
}

static int	up_down_key(t_data *data)
{
	if (data->key_mv->key_up)
	{
		if (check_walls_up_down(data, 0))
		{
			data->draw_utils->ply_x_pos += cos(data->draw_utils->angle) * SPEED;
			data->draw_utils->ply_y_pos += sin(data->draw_utils->angle) * SPEED;
			return (1);
		}
	}
	if (data->key_mv->key_down)
	{
		if (check_walls_up_down(data, 1))
		{
			data->draw_utils->ply_x_pos -= cos(data->draw_utils->angle) * SPEED;
			data->draw_utils->ply_y_pos -= sin(data->draw_utils->angle) * SPEED;
			return (1);
		}
	}
	return (0);
}

static void	rotation_key(t_data *data)
{
	if (data->key_mv->rot_rght)
	{
		if ((int)round(convert_rad2deg(data->draw_utils->angle)) == 0)
			data->draw_utils->angle = (2 * M_PI);
		data->draw_utils->angle -= convert_deg2rad(ROT_SPEED);
		//this one for the ray i will get back to it to optimize it
		if ((int)round(convert_rad2deg(data->ray->ray_angle)) == 0)
			data->ray->ray_angle = (2 * M_PI);
		data->ray->ray_angle = fabs(data->ray->ray_angle - convert_deg2rad(ROT_SPEED));
	}
	if (data->key_mv->rot_lft)
	{
		//printf("gg\n");
		if ((int)round(convert_rad2deg(data->draw_utils->angle)) == 360)
			data->draw_utils->angle = 0;
		data->draw_utils->angle += convert_deg2rad(ROT_SPEED);
		//this one for the ray i will get back to it to optimize it
		//data->ray->ray_angle += convert_deg2rad(5.0);
		if ((int)round(convert_rad2deg(data->ray->ray_angle)) == 360)
			data->ray->ray_angle = 0;
		data->ray->ray_angle += convert_deg2rad(ROT_SPEED);
		//printf("ply_angle = %f\n", convert_rad2deg(data->draw_utils->angle));
		//printf("ray_angle = %f\n", convert_rad2deg(data->ray->ray_angle));
	}
}

int	view_up_down_key(t_data *data)
{
	if (data->key_mv->view_up)
	{
		if (!(data->ray->view_up_down <= (WIN_H / 2) + 100))
			return (0);
		else
			data->ray->view_up_down += 5;
	}
	if (data->key_mv->view_down)
	{
		if (!(data->ray->view_up_down >= (WIN_H / 2) - 100))
			return (0);
		else
			data->ray->view_up_down -= 5;
	}
	return (1);
}

int	keys(t_data *data)
{
	if (data->key_mv->key_left || data->key_mv->key_right)
	{
		if (left_right_key(data))
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
	}
	if (data->key_mv->key_up || data->key_mv->key_down)
	{
		if (up_down_key(data))
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
	}
	if (data->key_mv->view_up || data->key_mv->view_down)
	{
		if (view_up_down_key(data))
			mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
			einstein_drawing(data);
	}
	if (data->key_mv->rot_rght || data->key_mv->rot_lft)
	{
		rotation_key(data);
		mlx_destroy_image(data->mlx->init, data->mlx->utils->img);
		einstein_drawing(data);
	}
	return (0);
}

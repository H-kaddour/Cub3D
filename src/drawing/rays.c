/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:32:12 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/16 20:36:13 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ray_sight(t_data *data)
{
	if (data->ray->ray_angle >= 0 && data->ray->ray_angle <= M_PI)
		return (1);
	return (0);
}

void	get_first_horizontal_intersect(t_data *data, double angle)
{
	data->draw_utils->x = data->draw_utils->ply_x_pos;
	data->draw_utils->y = data->draw_utils->ply_y_pos;
	//data->ray->sight = ray_sight(data);
	//if (data->ray->sight)

	//if (((int)floor(convert_rad2deg(angle)) >= 180 && \
	//		(int)floor(convert_rad2deg(angle) <= 360)))
	if ((int)convert_rad2deg(angle) >= 180 && \
			(int)convert_rad2deg(angle) <= 360)
		data->ray->y_horizontal = floor(data->draw_utils->y / SQR_SIZE) * SQR_SIZE;
	//else if ((int)floor(convert_rad2deg(angle) == 0))
	//	data->ray->y_horizontal = floor(data->draw_utils->y / SQR_SIZE) * SQR_SIZE;

	//else if ((int)floor(convert_rad2deg(angle)) >= 0 \
	//		&& (int)floor(convert_rad2deg(angle) < 180))
	else if ((int)convert_rad2deg(angle) >= 0 \
			&& (int)convert_rad2deg(angle) < 180)
		data->ray->y_horizontal = floor(data->draw_utils->y / SQR_SIZE) * SQR_SIZE + SQR_SIZE;

	data->ray->x_horizontal = data->draw_utils->x + \
		(data->ray->y_horizontal - data->draw_utils->y) / tan(angle);
	//printf("intersect angle %f\n", data->ray->ray_angle);

	//data->ray->x_step = data->draw_utils->x_next;
	//data->ray->y_step = data->draw_utils->y_next;
}

void	get_next_horizontal_intersect(t_data *data, double angle)
{
	//sight true means looking up and vice verca
	//data->draw_utils->x = data->ray->x_horizontal;
	//data->draw_utils->y = data->ray->y_horizontal;
	//if (!data->ray->sight)

	if (((int)convert_rad2deg(angle) >= 180 && \
			(int)convert_rad2deg(angle) <= 360))
	{
		data->ray->y_horizontal -= SQR_SIZE;
		data->ray->x_horizontal += (-SQR_SIZE / tan(angle));
	}
	//else if ((int)floor(convert_rad2deg(angle) == 0))
	//{
	//	data->ray->y_horizontal -= SQR_SIZE;
	//	data->ray->x_horizontal += (-SQR_SIZE / tan(angle));
	//}

	else if ((int)convert_rad2deg(angle) >= 0 \
			&& (int)convert_rad2deg(angle) < 180)
	{
		data->ray->y_horizontal += SQR_SIZE;
		data->ray->x_horizontal += (SQR_SIZE / tan(angle));
	}
	//data->ray->x_step = data->draw_utils->x_next;
	//data->ray->y_step = data->draw_utils->y_next;
}

void	get_first_vertical_intersect(t_data *data, double angle)
{
	data->draw_utils->x = data->draw_utils->ply_x_pos;
	data->draw_utils->y = data->draw_utils->ply_y_pos;
	//if (((int)round(convert_rad2deg(angle)) >= 270 && (int)round(convert_rad2deg(angle) <= 360)) || \
	//		((int)round(convert_rad2deg(angle)) >= 0 && (int)round(convert_rad2deg(angle) <= 90)))
	if (((int)(convert_rad2deg(angle)) >= 270 && (int)(convert_rad2deg(angle) <= 360)) || \
			((int)(convert_rad2deg(angle)) >= 0 && (int)(convert_rad2deg(angle) <= 90)))
	{
		data->ray->x_vertical = floor(data->draw_utils->x / SQR_SIZE) * SQR_SIZE + SQR_SIZE;
		data->ray->y_vertical = data->draw_utils->y + \
			(data->ray->x_vertical - data->draw_utils->x) * tan(angle);
	}
	//else if ((int)round(convert_rad2deg(angle)) > 90 \
	//		&& (int)round(convert_rad2deg(angle) < 270))
	else if ((int)(convert_rad2deg(angle)) > 90 \
			&& (int)(convert_rad2deg(angle) < 270))
	{
		data->ray->x_vertical = floor(data->draw_utils->x / SQR_SIZE) * SQR_SIZE;
		data->ray->y_vertical = data->draw_utils->y + \
			(data->ray->x_vertical - data->draw_utils->x) * tan(angle);
	}
	//data->ray->x_step = data->draw_utils->x_next;
	//data->ray->y_step = data->draw_utils->y_next;
}

void	get_next_vertical_intersect(t_data *data, double angle)
{
	//sight true means looking up and vice verca

	//data->draw_utils->x = data->ray->x_step;
	//data->draw_utils->y = data->ray->y_step;
	if (((int)round(convert_rad2deg(angle)) >= 270 && (int)round(convert_rad2deg(angle) <= 360)) || \
			((int)round(convert_rad2deg(angle)) >= 0 && (int)round(convert_rad2deg(angle) <= 90)))
	{
		//printf("ll\n");
		data->ray->x_vertical += SQR_SIZE;
		data->ray->y_vertical += (SQR_SIZE * tan(angle));
	}
	else if ((int)round(convert_rad2deg(angle)) > 90 \
			&& (int)round(convert_rad2deg(angle) < 270))
	{
		//printf("%f\n", convert_rad2deg(data->ray->ray_angle));
		//printf("x = %f || y = %f\n", data->draw_utils->x_next, data->draw_utils->y_next);
		//data->draw_utils->y_next += (SQR_SIZE * tan(angle));
		data->ray->x_vertical -= SQR_SIZE;
		data->ray->y_vertical += (-SQR_SIZE * tan(angle));
		//data->draw_utils->x_next += SQR_SIZE;
		//data->draw_utils->y_next += (SQR_SIZE * tan(angle));
	}
	//data->ray->x_step = data->draw_utils->x_next;
	//data->ray->y_step = data->draw_utils->y_next;
}

//void	draw_all_horizontal_intersect_rays(t_data *data)
//{
//	int	i = 0;
//	int	j;
//	double angle;
//	angle = data->ray->ray_angle;
//	while (i <= WIN_W)
//	{
//		j = 0;
//		//still SGVFault in empty map
//		if ((int)round(convert_rad2deg(angle)) != 0 \
//				&& (int)round(convert_rad2deg(angle)) != 180)
//		{
//			get_first_horizontal_intersect(data, angle);
//			printf("x_step = %d | y_step = %d\n", data->draw_utils->x_index_map, data->draw_utils->y_index_map);
//			if (did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step))
//			{
//				while (1)
//				{
//					get_next_horizontal_intersect(data, angle);
//					if (data->ray->x_step < 0 || data->ray->x_step > data->map->width * SQR_SIZE)
//						break ;
//					if (data->ray->y_step < 0 || data->ray->y_step > data->map->height * SQR_SIZE)
//						break ;
//					if (!did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step))
//						break ;
//					//if (j == 4)
//					//	break ;
//					j++;
//				}
//			}
//			//printf("x_step = %d | y_step = %d\n", data->draw_utils->x_index_map, data->draw_utils->y_index_map);
//			data->draw_utils->x = data->draw_utils->ply_x_pos;
//			data->draw_utils->y = data->draw_utils->ply_y_pos;
//			dda(data, 0x899fd3);
//		}
//		if ((int)round(convert_rad2deg(angle)) == 360)
//			angle = 0;
//		angle += convert_deg2rad(FOV) / WIN_W;
//		i++;
//	}
//}
//
//void	draw_all_vertical_intersect_rays(t_data *data)
//{
//	int	i = 0;
//	int	j;
//	double angle;
//	angle = data->ray->ray_angle;
//	//if ((int)round(convert_rad2deg(angle)) != 270 \
//	//		&& (int)round(convert_rad2deg(angle)) != 90)
//	//{
//	//	printf("angle = %d\n", (int)round(convert_rad2deg(angle)));
//	//	get_first_vertical_intersect(data, angle);
//	//	dda(data, 0x899fd3);
//	//}
//	//return;
//
//	while (i <= WIN_W)
//	{
//		j = 0;
//		//if ((int)round(convert_rad2deg(angle)) != 270 \
//		//		&& (int)round(convert_rad2deg(angle)) != 90)
//		if (!((int)round(convert_rad2deg(angle)) >= 86 && (int)round(convert_rad2deg(angle)) <= 94) && 
//				!((int)round(convert_rad2deg(angle)) >= 267 && (int)round(convert_rad2deg(angle)) <= 290))
//		{
//			//printf("round angle = %f\n", convert_rad2deg(angle));
//			//printf("x = %f x = %f\n", data->ray->x_step, data->ray->y_step);
//			get_first_vertical_intersect(data, angle);
//			//printf("x = %f x = %f\n", data->ray->x_step, data->ray->y_step);
//			dda(data, 0x000000);
//			//return ;
//
//			if (did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step))
//			{
//				while (1)
//				{
//					//get_next_horizontal_intersect(data, angle);
//					get_next_vertical_intersect(data, angle);
//					if (data->ray->x_step < 0 || data->ray->x_step > data->map->width * SQR_SIZE)
//						break ;
//					if (data->ray->y_step < 0 || data->ray->y_step > data->map->height * SQR_SIZE)
//						break ;
//					if (!did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step) \
//							&& !did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step))
//						break ;
//					//if (j == 4)
//					//	break ;
//					j++;
//				}
//			}
//			data->draw_utils->x = data->draw_utils->ply_x_pos;
//			data->draw_utils->y = data->draw_utils->ply_y_pos;
//			//if (!(data->ray->x_step < 0 || data->ray->x_step > data->map->width * SQR_SIZE \
//			//			|| data->ray->y_step < 0 || data->ray->y_step > data->map->height * SQR_SIZE))
//			dda(data, 0x899fd3);
//		}
//		//if ((int)round(convert_rad2deg(angle)) == 360)
//		//	angle = 0;
//		if ((int)floor(convert_rad2deg(angle) + (convert_deg2rad(FOV) / WIN_W)) == 360)
//			angle = 0;
//		angle += convert_deg2rad(FOV) / WIN_W;
//		i++;
//	}
//}

void	get_horizontal_intersect(t_data *data, double angle)
{
	if ((int)round(convert_rad2deg(angle)) != 0 \
			&& (int)round(convert_rad2deg(angle)) != 180)
	//if ((int)convert_rad2deg(angle) != 0 \
	//		&& (int)convert_rad2deg(angle) != 180)
	{
		get_first_horizontal_intersect(data, angle);
		if (data->ray->x_horizontal < 0 || data->ray->x_horizontal > data->map->width * SQR_SIZE \
				|| data->ray->y_horizontal < 0 || data->ray->y_horizontal > data->map->height * SQR_SIZE)
		{
			data->ray->chk_if_horz = 1;
			return ;
		}
		if (did_it_hit_the_wall(data, data->ray->x_horizontal, data->ray->y_horizontal + round(SQR_SIZE / 10)) && \
				did_it_hit_the_wall(data, data->ray->x_horizontal, data->ray->y_horizontal - round(SQR_SIZE / 10)))
		{
			while (1)
			{
				//printf("angle = %d\n", (int)floor(convert_rad2deg(angle)));
				get_next_horizontal_intersect(data, angle);
				if (data->ray->x_horizontal < 0 || data->ray->x_horizontal > data->map->width * SQR_SIZE \
						|| data->ray->y_horizontal < 0 || data->ray->y_horizontal > data->map->height * SQR_SIZE)
				{
					data->ray->chk_if_horz = 1;
					break ;
				}
				if (!did_it_hit_the_wall(data, data->ray->x_horizontal, data->ray->y_horizontal + round(SQR_SIZE / 10)) || \
						!did_it_hit_the_wall(data, data->ray->x_horizontal, data->ray->y_horizontal - round(SQR_SIZE / 10)))
					break ;
			}
		}
	}
	else
		data->ray->chk_if_horz = 1;
}

void	get_vertical_intersect(t_data *data, double angle)
{
	//if ((int)round(convert_rad2deg(angle)) != 270 \
	//		&& (int)round(convert_rad2deg(angle)) != 90)
	//if (!((int)round(convert_rad2deg(angle)) >= 86 && (int)round(convert_rad2deg(angle)) <= 94) && 
	//		!((int)round(convert_rad2deg(angle)) >= 267 && (int)round(convert_rad2deg(angle)) <= 290))
	//printf("vertical \n");
	if ((int)round(convert_rad2deg(angle)) != 270 \
			&& (int)round(convert_rad2deg(angle)) != 90)
	{
		get_first_vertical_intersect(data, angle);
		//take this off
		//return ;
		if (data->ray->x_vertical < 0 || data->ray->x_vertical > data->map->width * SQR_SIZE \
				|| data->ray->y_vertical < 0 || data->ray->y_vertical > data->map->height * SQR_SIZE)
		{
			data->ray->chk_if_vert = 1;
			return ;
		}
		if (did_it_hit_the_wall(data, data->ray->x_vertical + round(SQR_SIZE / 10), data->ray->y_vertical) && \
				did_it_hit_the_wall(data, data->ray->x_vertical - round(SQR_SIZE / 10), data->ray->y_vertical))
		{
			while (1)
			{
				//printf("vertical\n");
				get_next_vertical_intersect(data, angle);
				//mlx_put_pixel_to_img(data, data->ray->x_vertical - 10, data->ray->y_vertical, 0xff0000);
				if (data->ray->x_vertical < 0 || data->ray->x_vertical > data->map->width * SQR_SIZE \
						|| data->ray->y_vertical < 0 || data->ray->y_vertical > data->map->height * SQR_SIZE)
				{
					data->ray->chk_if_vert = 1;
					break ;
				}
				//+ not working here segv
				if (!did_it_hit_the_wall(data, data->ray->x_vertical + round(SQR_SIZE / 10), data->ray->y_vertical) || \
						!did_it_hit_the_wall(data, data->ray->x_vertical - round(SQR_SIZE / 10), data->ray->y_vertical))
					break ;
			}
		}
	}
	else
		data->ray->chk_if_vert = 1;
}

void	compare_the_intersects(t_data *data)
{
	if (data->ray->chk_if_horz)
	{
		//printf("ok\n");
		////1 for vertical
		//printf("x_ply = %f\n", data->draw_utils->x);
		//printf("y_ply = %f\n", data->draw_utils->y);
		//printf("x_horiz = %f\n", data->ray->x_horizontal);
		//printf("y_horiz = %f\n", data->ray->y_horizontal);
		//printf("x_vert = %f\n", data->ray->x_vertical);
		//printf("y_vert = %f\n", data->ray->y_vertical);
		data->draw_utils->x_next = data->ray->x_vertical;
		data->draw_utils->y_next = data->ray->y_vertical;
	}
	else if (data->ray->chk_if_vert)
	{
		//printf("ok1\n");
		//2 for horizontal
		data->draw_utils->x_next = data->ray->x_horizontal;
		data->draw_utils->y_next = data->ray->y_horizontal;
	}
	else
	{
		//printf("ok2\n");
		double x;
		double y;
		//printf("x_ply = %f\n", data->draw_utils->x);
		//printf("y_ply = %f\n", data->draw_utils->y);
		//printf("x_horiz = %f\n", data->ray->x_horizontal);
		//printf("y_horiz = %f\n", data->ray->y_horizontal);
		//printf("x_vert = %f\n", data->ray->x_vertical);
		//printf("y_vert = %f\n", data->ray->y_vertical);
		//(void)angle;
		//if (((int)round(convert_rad2deg(angle)) > 180 && \
		//		(int)round(convert_rad2deg(angle) <= 270)))
		//{
		//	x = fabs(data->draw_utils->x - data->ray->x_horizontal);
		//	y = fabs(data->draw_utils->y - data->ray->y_horizontal);
		//}
		//if (((int)round(convert_rad2deg(angle)) > 0 && \
		//		(int)round(convert_rad2deg(angle) <= 90)))
		//{
		//	x = fabs(data->draw_utils->x - data->ray->x_horizontal);
		//	y = fabs(data->draw_utils->y - data->ray->y_horizontal);
		//}
		x = fabs(data->draw_utils->x - data->ray->x_horizontal);
		y = fabs(data->draw_utils->y - data->ray->y_horizontal);
		data->ray->dist_horz = sqrt((x * x) + (y * y));
		x = fabs(data->draw_utils->x - data->ray->x_vertical);
		y = fabs(data->draw_utils->y - data->ray->y_vertical);
		data->ray->dist_vert = sqrt((x * x) + (y * y));
		//printf("dist_horz = %d | dist_vert = %d\n", (int)round(data->ray->dist_horz), (int)round(data->ray->dist_vert));
		if ((int)round(data->ray->dist_horz) < (int)round(data->ray->dist_vert))
		{
			//printf("all\n");
			data->draw_utils->x_next = data->ray->x_horizontal;
			data->draw_utils->y_next = data->ray->y_horizontal;
		}
		else
		{
			data->draw_utils->x_next = data->ray->x_vertical;
			data->draw_utils->y_next = data->ray->y_vertical;
		}
	}
}

void	draw_rays(t_data *data)
{
	int	i;
	double	angle;

	i = 0;
	//this one draw player ray
	//printf("jiji\n");
	data->draw_utils->x = data->draw_utils->ply_x_pos;
	data->draw_utils->y = data->draw_utils->ply_y_pos;
	data->draw_utils->x_next = data->draw_utils->x + cos(data->draw_utils->angle) * 50;
	data->draw_utils->y_next = data->draw_utils->y + sin(data->draw_utils->angle) * 50;
	//printf("angle = %f\n", convert_rad2deg(data->draw_utils->angle));
	//printf("x = %f | y = %f\n", data->draw_utils->x, data->draw_utils->y);
	//printf("x_next = %f | y_next = %f\n", data->draw_utils->x_next, data->draw_utils->y_next);
	dda(data, 0x00ff00);
	return ;


	i = 0;
	angle = data->ray->ray_angle;
	//angle = convert_deg2rad(357);
	int	clr = 0xff0000;
	while (i <= WIN_W)
	{
		data->ray->chk_if_horz = 0;
		data->ray->chk_if_vert = 0;
		//printf("%f\n", convert_rad2deg(angle));
		get_horizontal_intersect(data, angle);
		get_vertical_intersect(data, angle);
		compare_the_intersects(data);
		dda(data, clr);
		//return ;
		//if i floor it it work in 0 degree but it goes into a segv
		//if ((int)floor(convert_rad2deg(angle)) == 360)
		//if ((int)round(convert_rad2deg(angle)) == 360)
		//if ((int)convert_rad2deg(angle) == 360)
		if ((int)convert_rad2deg(angle) == 360)
		{
			//printf("angle = %f\n", convert_rad2deg(angle));
			angle = 0;
		}
		//this calcul should save in a variable
		angle += convert_deg2rad(FOV) / WIN_W;
		i++;
	}
	return ;

	//printf("angle = %f\n", convert_rad2deg(data->ray->ray_angle));
	//return ;

	//here check if the angle is 270 or 90 don't draw vertical
	//if ((int)round(convert_rad2deg(data->ray->ray_angle)) != 270 && \
	//	(int)round(convert_rad2deg(data->ray->ray_angle)) != 90)
	//{
	//	get_first_vertical_intersect(data);
	//	//dda(data, 0x000000);
	//	get_next_vertical_intersect(data, data->ray->ray_angle);
	//	dda(data, 0x899fd3);
	//}
	//return ;

	//angle = data->ray->ray_angle;
	//while (i <= WIN_W)
	//{
	//	if (!i)
	//	{
	//		get_first_horizontal_intersect(data);
	//	}
	//	angle += convert_deg2rad(FOV) / WIN_W;
	//	i++;
	//}

	//draw all rays
	//angle = data->ray->ray_angle;
	//if ((int)round(convert_rad2deg(angle)) != 0 \
	//		&& (int)round(convert_rad2deg(angle)) != 180)
	//{
	//	//printf("%f\n", convert_rad2deg(data->ray->ray_angle));
	//	get_first_horizontal_intersect(data);
	//	dda(data, 0x000000);
	//	//get_next_horizontal_intersect(data, angle);
	//	//dda(data, 0x899fd3);
	//	//printf("l\n");
	//}
	//return ;





	//draw_all_horizontal_intersect_rays(data);
	//draw_all_vertical_intersect_rays(data);
	//return ;


	//int	j;
	//angle = data->ray->ray_angle;
	//while (i <= WIN_W)
	//{
	//	j = 0;
	//	if ((int)round(convert_rad2deg(angle)) != 0 \
	//			&& (int)round(convert_rad2deg(angle)) != 180)
	//	{
	//		get_first_horizontal_intersect(data, angle);
	//		//angle += convert_deg2rad(FOV) / WIN_W;
	//		if (did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step) \
	//				&& did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step))
	//		{
	//			while (1)
	//			{
	//				get_next_horizontal_intersect(data, angle);
	//				if (data->ray->x_step < 0 || data->ray->x_step > data->map->width * SQR_SIZE)
	//					break ;
	//				if (data->ray->y_step < 0 || data->ray->y_step > data->map->height * SQR_SIZE)
	//					break ;
	//				if (!did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step) \
	//						&& !did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step))
	//					break ;
	//				//if (j == 4)
	//				//	break ;
	//				j++;
	//			}
	//		}
	//		//printf("x_step = %d | y_step = %d\n", data->draw_utils->x_index_map, data->draw_utils->y_index_map);
	//		data->draw_utils->x = data->draw_utils->ply_x_pos;
	//		data->draw_utils->y = data->draw_utils->ply_y_pos;
	//		dda(data, 0x899fd3);
	//	}
	//	if ((int)round(convert_rad2deg(angle)) == 360)
	//		angle = 0;
	//	angle += convert_deg2rad(FOV) / WIN_W;
	//	i++;

	//	//if ((int)round(convert_rad2deg(angle)) != 0 \
	//	//		&& (int)round(convert_rad2deg(angle)) != 180)
	//	//{
	//	//		get_next_horizontal_intersect(data, angle);
	//	//		dda(data, 0x899fd3);
	//	//	printf("x_step = %f | y_step = %f\n", data->ray->x_step, data->ray->y_step);
	//	//	//if (did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step - 10) \
	//	//	//		&& did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step + 10))
	//	//	//{
	//	//	//	//get_next_horizontal_intersect(data, angle);
	//	//	//	//dda(data, 0x899fd3);
	//	//	//}
	//	//	//else
	//	//	//	break ;
	//	//	if (i == 10)
	//	//		break ;
	//	//}
	//	//angle += convert_deg2rad(FOV) / WIN_W;
	//	//printf("%d\n", i);
	//	//if (i == 10)
	//	//	return ;
	//}
	//return ;

	//if ((int)round(convert_rad2deg(data->ray->ray_angle)) != 0 \
	//		&& (int)round(convert_rad2deg(data->ray->ray_angle)) != 180)
	//{
	//	printf("angle = %f\n", convert_rad2deg(data->ray->ray_angle));
	//	//get_first_horizontal_intersect(data);
	//	dda(data, 0x000000);
	//	return ;
	//	//mlx_put_pixel_to_img(data, data->ray->x_step, data->ray->y_step - 10, 0xff0000);
	//	while (i < 3)
	//	{
	//		//mlx_put_pixel_to_img(data, data->ray->x_step, data->ray->y_step - 10, 0xff0000);
	//		if (did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step - 10) \
	//				&& did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step + 10))
	//		{
	//			get_next_horizontal_intersect(data, data->ray->ray_angle);
	//			dda(data, 0x899fd3);
	//		}
	//		i++;
	//	}
	//}
	//return ;



	//while (did_it_hit_the_wall(data, data->ray->x_step, data->ray->y_step))
	//{
	//	if (convert_rad2deg(data->ray->ray_angle) != 0 \
	//			&& (int)round(convert_rad2deg(data->ray->ray_angle)) != 180)
	//	{
	//		//get_first_horizontal_intersect(data);
	//		get_next_horizontal_intersect(data, data->ray->ray_angle);
	//		//dda(data, 0x899fd3);
	//	}
	//}
	//dda(data, 0x899fd3);
	//return ;

	//angle = data->ray->ray_angle;
	//data->draw_utils->x = data->draw_utils->ply_x_pos;
	//data->draw_utils->y = data->draw_utils->ply_y_pos;
	////this one for up
	//data->draw_utils->y_next = floor(data->draw_utils->y / SQR_SIZE) * SQR_SIZE;
	////this one for down
	////data->draw_utils->y_next = floor(data->draw_utils->y / SQR_SIZE) * SQR_SIZE + SQR_SIZE;
	//data->draw_utils->x_next = data->draw_utils->x + (data->draw_utils->y_next - data->draw_utils->y) / tan(angle);
	//dda(data, 0x899fd3);
	//return ;
	//while (i <= WIN_W)
	//{
	//	data->draw_utils->x = data->draw_utils->ply_x_pos;
	//	data->draw_utils->y = data->draw_utils->ply_y_pos;
	//	data->draw_utils->x_next = data->draw_utils->x + cos(angle) * 700;
	//	data->draw_utils->y_next = data->draw_utils->y + sin(angle) * 700;
	//	dda(data, 0x899fd3);
	//	//if (i == 0 || i == WIN_W)
	//	//{
	//	//	dda(data, 0x899fd3);
	//	//	return ;
	//	//}
	//	angle += convert_deg2rad(FOV) / WIN_W;
	//	i++;
	//}
}

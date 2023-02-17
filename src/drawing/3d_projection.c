/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:17:10 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/17 19:46:48 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	look_im_3d_now(t_data *data)
{
	int	i;

	i = 0;
	data->ray->dist_ply_proj = (WIN_W / 2) / tan(FOV / 2);
	data->ray->proj_wall = fabs(SQR_SIZE / data->ray->ray_dist * data->ray->dist_ply_proj);
	//data->ray->proj_wall = fabs(SQR_SIZE / data->ray->dist_ply_proj * data->ray->dist_ply_proj);
	data->draw_utils->y1 = WIN_H / 2 - data->ray->proj_wall;
	//printf("y = %f\n", data->draw_utils->y1);
	//printf();
	while (i < (int)round(data->ray->proj_wall) * 2)
	{
		//printf("gg\n");
		mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1++), 0x000000);
		//mlx_put_pixel_to_img(data, floor(data->draw_utils->x1), floor(data->draw_utils->y1++), 0x000000);
		i++;
	}
	data->draw_utils->x1++;
	//printf("%f\n", data->ray->proj_wall);
}

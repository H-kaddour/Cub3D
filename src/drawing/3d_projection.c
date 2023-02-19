/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:17:10 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/19 20:37:41 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//void    look_im_3d_now(t_data *data, double angle)
//{
//    int    i;
//
//    (void)angle;
//    //data->ray->dist_ply_proj = (WIN_W / 2) / tan(FOV / 2);
//    data->ray->dist_ply_proj = (WIN_W / 2) / tan((FOV / 2));
//    //data->ray->dist_ply_proj = (WIN_W / 2) / tan(FOV / 2);
//    //funny
//    //data->ray->proj_wall = fabs(SQR_SIZE / data->ray->ray_dist * data->ray->dist_ply_proj * cos(angle));
//    data->ray->proj_wall = fabs((SQR_SIZE / data->ray->ray_dist) * data->ray->dist_ply_proj);
//    //data->ray->proj_wall = fabs(data->ray->ray_dist);
//    //printf("%f\n",data->ray->proj_wall);
//    //return ;
//    //data->ray->proj_wall = fabs(SQR_SIZE / data->ray->dist_ply_proj * data->ray->dist_ply_proj);
//    //data->ray->proj_wall = fabs(SQR_SIZE / data->ray->ray_dist) * cos(angle);
//    data->draw_utils->y1 = WIN_H / 2 - (data->ray->proj_wall / 2);
//    i = data->draw_utils->y1;
//    //printf("y = %f\n", data->draw_utils->y1);
//    //printf();
//    // while (i < (int)round(data->ray->proj_wall))
//    while (i < WIN_H / 2 + (data->ray->proj_wall / 2))
//    {
//        //printf("gg\n");
//        mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1++), 0x0000ff);
//        //mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1++), 0x000000);
//        i++;
//    }
//    data->draw_utils->x1++;
//    //printf("%f\n", data->ray->proj_wall);
//}


void	look_im_3d_now(t_data *data)
{
	int	i;

	i = 0;
  //(void)angle;
  //pikuma
	//data->ray->dist_ply_proj = (WIN_W / 2) / tan(FOV / 2);
	data->ray->dist_ply_proj = (WIN_W / 2) / tan(convert_deg2rad(FOV));
	data->ray->proj_wall = fabs((SQR_SIZE / data->ray->ray_dist) * data->ray->dist_ply_proj);

  //method youness
	//data->ray->proj_wall = fabs(data->ray->ray_dist / SQR_SIZE);
  //data->ray->proj_wall = WIN_H / data->ray->proj_wall;
	data->ray->start_wall = (WIN_H / 2) - (data->ray->proj_wall / 2);
	data->ray->end_wall = (WIN_H / 2) + (data->ray->proj_wall / 2);

	//data->draw_utils->y1 = WIN_H / 2 - (data->ray->proj_wall/ 2);
	data->draw_utils->y1 = 0;
	//while (i < (int)round(data->ray->proj_wall))
	while (i <= WIN_H)
	{
		//mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1++), 0x0000ff);
		if (i < data->ray->start_wall)
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1), data->color->ceiling);
		else if (i >= data->ray->start_wall && i <= data->ray->end_wall)
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1), 0xf030ff);
		else
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1), data->color->floor);
    data->draw_utils->y1++;
		i++;
	}
	data->draw_utils->x1++;
}

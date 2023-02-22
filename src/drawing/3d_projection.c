/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:17:10 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/22 16:56:36 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned int	get_color\
	(t_data *data, double y, double wall_h,double x_offset_t, int i)
{
	unsigned int	color;
	int				y_offset;
	int				x_offset;


	//y_offset = y + (wall_h / 2) - (h_win / 2);
	y_offset = y + (wall_h / 2) - data->ray->view_up_down;
	//y_offset = fabs(y + (wall_h / 2) - (h_win - data->ray->view_up_down / 2));
	x_offset = (x_offset_t / SQR_SIZE) * data->texture[i].w;
	y_offset = ((y_offset) * ((double)data->texture[i].h / wall_h));
	color = data->texture[i].texture[(int)((y_offset * data->texture[i].h) + x_offset)];
	return ((unsigned int)color);
}

void	look_im_3d_now(t_data *data, double angle)
{
	int	i;

	i = 0;
  //(void)angle;
  //pikuma
	//data->ray->dist_ply_proj = (WIN_W / 2) / tan(FOV / 2);
	data->ray->dist_ply_proj = (WIN_W / 2) / tan(convert_deg2rad(FOV /3) * 2);
	data->ray->proj_wall = fabs((SQR_SIZE / data->ray->ray_dist) * data->ray->dist_ply_proj);

  //method youness
	//data->ray->proj_wall = fabs(data->ray->ray_dist / SQR_SIZE);
  //data->ray->proj_wall = WIN_H / data->ray->proj_wall;
	//data->ray->start_wall = (WIN_H / 2) - (data->ray->proj_wall / 2);
	data->ray->start_wall = data->ray->view_up_down - (data->ray->proj_wall / 2);
	//data->ray->end_wall = (WIN_H / 2) + (data->ray->proj_wall / 2);
	data->ray->end_wall = data->ray->start_wall + (data->ray->proj_wall);

	//data->draw_utils->y1 = WIN_H / 2 - (data->ray->proj_wall/ 2);
	data->draw_utils->y1 = 0;
	//while (i < (int)round(data->ray->proj_wall))
	unsigned int	clr;
	//double x_offset_texture;
	while (i <= WIN_H)
	{
		//mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1++), 0x0000ff);
		//data->ray->offset_y = (data->draw_utils->y1 - data->ray->start_wall) * (H_T / data->ray->proj_wall);
		//data->ray->offset_y = data->draw_utils->y1 +  (WIN_H / 2 )- (data->ray->proj_wall / 2);
		//data->ray->offset_y = data->draw_utils->y1 + (data->ray->proj_wall / 2) - (WIN_H / 2 );
		//data->ray->offset_y = (data->draw_utils->y1) - (WIN_H / 2 );
		//printf("%d\n",data->ray->offset_y);
		//clr = data->texture->addr2[(W_T * data->ray->offset_y) + data->ray->offset_x];
		//data->ray->offset_y = (data->ray->offset_y * (W_T / data->ray->proj_wall));
		//printf("x %d\n",data->ray->offset_x);
		//printf("y %d\n",data->ray->offset_y);
		//data->draw_utils->y1 = data->ray->offset_x * SQR_SIZE + i ;
		//clr = data->texture->addr[(500 * data->ray->offset_y) + data->ray->offset_x];
		//clr = data->texture->addr[(int)data->ray->offset_x * SQR_SIZE + (int)( i * (data->ray->proj_wall / SQR_SIZE))];
		//clr = data->texture->addr[( data->ray->offset_y) + data->ray->offset_x];
		if (i < data->ray->start_wall)
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1), data->color->ceiling);
		else if (i >= data->ray->start_wall && i <= data->ray->end_wall)
		{
			//this one works
			//data->ray->offset_y = (int)( (i - data->ray->start_wall) * ((float)SQR_SIZE / data->ray->proj_wall));
			//clr = data->texture->addr2[data->ray->offset_y * SQR_SIZE + data->ray->offset_x]; 

			//data->ray->offset_y = data->draw_utils->y1 + (data->ray->proj_wall / 2) - (WIN_H / 2 );
			//data->ray->offset_y = data->draw_utils->y1 - (WIN_H/2) + (data->ray->proj_wall/2);
			
			//data->ray->offset_y = data->draw_utils->y1 + (data->ray->proj_wall / 2) - (WIN_H / 2 );
			//x_offset_texture = (data->ray->offset_x / SQR_SIZE) * W_T;
			//data->ray->offset_y = (W_T / data->ray->proj_wall) * data->ray->offset_y;
			//clr = data->texture->addr2[(int)fabs((W_T * data->ray->offset_y) + x_offset_texture)];
			//printf("x = %f | y = %f\n", x_offset_texture, data->ray->offset_y);

			//clr = get_color(data, data->draw_utils->y1, data->ray->proj_wall, data->ray->offset_x);
			//if (data->ray->chk_if_horz && (convert_rad2deg(angle) >= 180 && convert_rad2deg(angle) <= 360))
			//	clr = 0xff0000;
			//else if (data->ray->chk_if_horz && (convert_rad2deg(angle) >= 0 && convert_rad2deg(angle) < 180))
			//	clr = 0xff0890;
			//else if (data->ray->chk_if_vert && (convert_rad2deg(angle) >= 180 && convert_rad2deg(angle) <= 360))
			//	clr = 0x00ff00;
			//else if (data->ray->chk_if_vert && (convert_rad2deg(angle) >= 0 && convert_rad2deg(angle) < 180))
			//	clr = 0xf00291;

			//printf("%d\n", data->ray->chk_if_horz);
			//printf("%d\n", data->ray->chk_if_vert);
			//exit(0);
			if (data->ray->chk_if_horz && ((int)convert_rad2deg(angle) >= 0 && (int)convert_rad2deg(angle) <= 180))
				clr = get_color(data, data->draw_utils->y1, data->ray->proj_wall, data->ray->offset_x, 0);
			else if (data->ray->chk_if_horz && (convert_rad2deg(angle) > 90 && convert_rad2deg(angle) <= 360))
				clr = get_color(data, data->draw_utils->y1, data->ray->proj_wall, data->ray->offset_x, 1);
			if (data->ray->chk_if_vert && (((int)convert_rad2deg(angle) >= 270 && (int)convert_rad2deg(angle) <= 360) \
					|| ((int)convert_rad2deg(angle) >= 0 && (int)convert_rad2deg(angle) <= 90)))
				clr = get_color(data, data->draw_utils->y1, data->ray->proj_wall, data->ray->offset_x, 2);
			else if (data->ray->chk_if_vert && ((int)convert_rad2deg(angle) > 90 && (int)convert_rad2deg(angle) < 270))
				clr = get_color(data, data->draw_utils->y1, data->ray->proj_wall, data->ray->offset_x, 3);


			//else
			//	clr = 0xffffff;
			// if (data->ray->chk_if_vert && \
			//	((data->draw_utils->angle >= (3 * M_PI / 2) && data->draw_utils->angle <= (2 * M_PI)) || (data->draw_utils->angle >= 0 && data->draw_utils->angle <= (M_PI / 2))))
			//	clr = get_color(data, data->draw_utils->y1, data->ray->proj_wall, data->ray->offset_x, 2);
			// if (data->ray->chk_if_vert && (data->draw_utils->angle >= 2 /M_PI && data->draw_utils->angle <= (3 * M_PI / 2)))
			//	clr = get_color(data, data->draw_utils->y1, data->ray->proj_wall, data->ray->offset_x, 3);

			//if (data->ray->chk_if_horz && is_up(data))
			//	clr = 0x900d00;
			//else if (data->ray->chk_if_vert && is_up(data))
			//	clr = 0xff0890;
			//else if (data->ray->chk_if_horz && is_down(data))
			//	clr = 0xa090d;
			//else if (data->ray->chk_if_vert && is_down(data))
			//	clr = 0xd0f291;

			//else if (is_right(data))
			//	clr = 0x00ff00;
			//else if (is_left(data))
			//	clr = 0xf00291;

			(void)angle;



			//printf("x %d, y %d\n", data->ray->offset_x, data->ray->offset_y);
			//clr = data->texture->addr[(int)data->ray->offset_x * SQR_SIZE + (int)( (i - data->ray->start_wall))]; 
			//* (data->ray->proj_wall / SQR_SIZE))];
			//printf("h = %f\n", ((int)(data->draw_utils->x_next) % 50) * fabs(data->draw_utils->y1));
			//mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1), \
			//		texture_clr(data, ((int)(data->draw_utils->x_next) % 50) * fabs(data->draw_utils->y1 )));
			//mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1), 0xf030ff);
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1), clr);
		}
		else
			mlx_put_pixel_to_img(data, fabs(data->draw_utils->x1), fabs(data->draw_utils->y1), data->color->floor);
    data->draw_utils->y1++;
		i++;
	}
	data->draw_utils->x1++;
}

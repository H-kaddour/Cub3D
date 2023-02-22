/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:08:06 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/20 22:57:05 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//int	H_T;
//int	W_T;
//key UP and DOWN
void	get_textures(t_data *data)
{
	int	h;
	int	w;

	//data->texture->img = mlx_new_image(data->mlx->init, 500, 500);
	//mlx_xpm
	data->texture->img = mlx_xpm_file_to_image(data->mlx->init, data->ply_stat->south, &w, &h);
	data->texture->addr2 = (unsigned int *)mlx_get_data_addr(data->texture->img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);
	H_T = h;
	W_T = w;
	//mlx_put_image_to_window(data->mlx->init, data->mlx->win, data->texture->img, 0, 0);
	//printf("color = %s\n", data->texture->img);
	//exit(0);
}

unsigned int	texture_clr(t_data *data, int x)
{
	//printf("%d\n", x);
	//printf("%d\n",data->texture->addr[x]);
	//exit(0);
	//int y_offset = y - (wall_height / 2 ) + (screen_hight /2);
	// x , y 7wlhom l nisba dyalhom f texture

	return ((unsigned int)data->texture->addr[x]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:08:06 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/22 13:54:23 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_textures(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx->init, \
			data->ply_stat->east, &data->texture[0].w, &data->texture[0].h);
	data->texture[0].texture = (unsigned int *)mlx_get_data_addr(data->texture[0].img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);

	data->texture[1].img = mlx_xpm_file_to_image(data->mlx->init, \
			data->ply_stat->north, &data->texture[1].w, &data->texture[1].h);
	data->texture[1].texture = (unsigned int *)mlx_get_data_addr(data->texture[1].img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);

	data->texture[2].img = mlx_xpm_file_to_image(data->mlx->init, \
			data->ply_stat->west, &data->texture[2].w, &data->texture[2].h);
	data->texture[2].texture = (unsigned int *)mlx_get_data_addr(data->texture[2].img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);

	data->texture[3].img = mlx_xpm_file_to_image(data->mlx->init, \
			data->ply_stat->south, &data->texture[3].w, &data->texture[3].h);
	data->texture[3].texture = (unsigned int *)mlx_get_data_addr(data->texture[3].img, &data->texture->bpp, \
			&data->texture->size_line, &data->texture->endian);
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

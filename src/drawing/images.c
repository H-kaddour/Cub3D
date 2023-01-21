/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:20:46 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/16 21:16:04 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	make_and_init_image(t_data *data)
{
	data->mlx->utils->img = mlx_new_image(data->mlx->init, WIN_W, WIN_H);
	//if (!data->mlx->utils->img)
	//	exit(0);
	data->mlx->utils->addr = mlx_get_data_addr(data->mlx->utils->img, \
			&data->mlx->utils->bpp, &data->mlx->utils->size_line, \
			&data->mlx->utils->endian);
}

void	mlx_put_pixel_to_img(t_data *data, int x, int y, int clr)
{
	char    *dst;

	//if (x > 0 && y > 0 && WIN_W > x && WIN_H > y)
	if (WIN_W > x && WIN_H > y)
  {
		dst = data->mlx->utils->addr + (y * data->mlx->utils->size_line + \
				x * (data->mlx->utils->bpp / 8));
		*(unsigned int *)dst = clr;
  }
}

//i need 2 function:
//1- one make the img and get the address and shiit
//2- two put the color in the image
//3- use mlx put_to_image to put
//4- use mlx_img_destroy to destroy
